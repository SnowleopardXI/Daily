package com.event;

import java.awt.Button;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.swing.JButton;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;

import com.Thread.RunGetAccountStart;

import com.mysqld.Mysqld;
import com.window.ChangeAccountMessage;
import com.window.ChangeOwnPassword;
import com.window.LoginStart;
import com.window.Manage;
import com.window.StudentSystem;

public class LoginEvent implements ActionListener{
	
	JButton button;//定义一个按钮
	public static String accountA;//记录登录的账户
	JMenuItem item;
	static ChangeOwnPassword aa;
	public static Manage manage;
	static  String start;
	public static Thread cheack;
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		
		try {
			
			button= (JButton) e.getSource();//强制转换类型
			
			if(button.getName()=="ok") {
				//如果账号和密码跟数据库里面的是一样那就登录 同写入状态数据
				String account=LoginStart.accounttext.getText();
				String passworn=new String (LoginStart.passwordtext.getPassword());
				
				if(Mysqld.loginAccount( account, passworn)) {
					//登录事件
					this.accountA=account; //同是也写入登录状态   0  是不在线  1在线
					//第一步先查询当前账号的登录状态
					start=Mysqld.findAccountStart(accountA);//返回一个字符串的状态
					
					if(start.equals("1")) {
						//JOptionPane.showMessageDialog(null, "当前账号已经登录", "登录消息",JOptionPane.WARNING_MESSAGE);
						int a=JOptionPane.showConfirmDialog(null,"当前账号已经登录，是否继续登录","登录消息",JOptionPane.YES_NO_OPTION);
						//0代表确认  1代表 否
						
						if(a==0) {
							//将数据库的状态瞬间改为0
							Mysqld.setStart(accountA,"0");
							StudentSystem.loginstartA.close();
							manage=new Manage();//打开登录界面
							while(Mysqld.findAccountStart(accountA).equals("1")) {
								checkStart();
								break;
							}
							
							
						}
					//sleep
						
					}else {
						Mysqld.setStart(accountA,"1");
						StudentSystem.loginstartA.close();
						manage=new Manage();//打开登录界面
						checkStart();
						
					}
				
					
					
					
					
				}else {
					JOptionPane.showMessageDialog(null, "密码错误", "登录消息",JOptionPane.WARNING_MESSAGE);
				}
			
			
		
				
			}
			
			if(button.getName()=="change") {
				//向数据库更新信息
		
				Mysqld.changeOtherAccountMessage();
				
			}
			if(button.getName()=="changeown") {
				//第一步知道当前账户是哪个账户然后 信息密码
				String password=new String (ChangeOwnPassword.passwordtext.getPassword());
				
				Mysqld. changePassword(accountA,password);
				JOptionPane.showMessageDialog(null, "修改密码成功", "修改密码消息",JOptionPane.WARNING_MESSAGE);
				
				//把管理界面给他关闭 打开登录界面
				manage.dispose();//管理界面消失   
				//把登录状态设置为0 
				Mysqld.setStart(accountA,"0");
				aa.dispose();
				StudentSystem.show();
			
			}
			
			//____________________________________________
			
			if(button.getName()=="add") {
				//向数据库写入数据
				Manage.model.setNumRows(0);
				String name=Manage.nametext.getText();
				boolean man=Manage.Men.isSelected();
				boolean woman=Manage.Women.isSelected();
				boolean allsex=Manage.allsex.isSelected();
				
				String sex;
				String age=Manage.agetext.getText();
				String grade=Manage.gradetext.getText();
				String number=Manage.numbertext.getText();
				
				
				
				if(name.equals("")) {
					JOptionPane.showMessageDialog(null, "姓名不能为空", "编辑消息",JOptionPane.WARNING_MESSAGE);
				}else if((man==false&&woman==false)&&allsex==true) {
					Manage.Men.setSelected(true);
					JOptionPane.showMessageDialog(null, "”全部“在增加信息不能被选中", "编辑消息",JOptionPane.WARNING_MESSAGE);
					
					
				}else if(man==false&&woman==false&&allsex==false) {
					JOptionPane.showMessageDialog(null, "请选择性别", "编辑消息",JOptionPane.WARNING_MESSAGE);
				}else if( age.equals("")) {
					JOptionPane.showMessageDialog(null, "年级不能为空", "编辑消息",JOptionPane.WARNING_MESSAGE);
				}else if ( grade.equals("")) {
					JOptionPane.showMessageDialog(null, "班级不能为空", "编辑消息",JOptionPane.WARNING_MESSAGE);
				}else if(number.equals("")) {
					JOptionPane.showMessageDialog(null, "学号不能为空", "编辑消息",JOptionPane.WARNING_MESSAGE);
				}else {
					if(Manage.Men.isSelected()==true) {
						sex=Manage.Men.getText();
					}else {
						sex=Manage.Women.getText();
					}
						
					Mysqld.addStudent(name, sex, age , grade, number);
					//将添加的数据显示到表格里面
					//ManageForm.model.addRow(dm);
					
					String  data[]=new String [5];
						data[0]=name;
						data[1]=sex;
						data[2]=age;
						data[3]=grade;
						data[4]=number;
						Manage.model.addRow(data);
					
				}
				
				
			}
			
			
			if(button.getName()=="del") {
				//删除数据
				
				 
				 String numberA=Manage.numbeconditiontext.getText();
				 if(numberA.equals("")) {
					 JOptionPane.showMessageDialog(null, "条件框不能为空", "删除消息",JOptionPane.WARNING_MESSAGE);
				 }else {
					 Mysqld.delStudeng(numberA);
				 }
				 
				
			}
			
			
				
			if(button.getName()=="chan") {
				String name=Manage.nametext.getText();
				boolean man=Manage.Men.isSelected();
				boolean woman=Manage.Women.isSelected();
				boolean allsex=Manage.allsex.isSelected();
				
				String sex;
				String age=Manage.agetext.getText();
				String grade=Manage.gradetext.getText();
				String number=Manage.numbertext.getText();
				
				
				String numberA=Manage.numbeconditiontext.getText();
				if(numberA.equals("")) {
					 JOptionPane.showMessageDialog(null, "条件框学号不能为空", "删除消息",JOptionPane.WARNING_MESSAGE);
				 }else	if(name.equals("")) {
					JOptionPane.showMessageDialog(null, "姓名不能为空", "编辑消息",JOptionPane.WARNING_MESSAGE);
				}else if((man==false&&woman==false)&&allsex==true) {
					Manage.Men.setSelected(true);
					JOptionPane.showMessageDialog(null, "”全部“在增加信息不能被选中", "编辑消息",JOptionPane.WARNING_MESSAGE);
					
					
				}else if(man==false&&woman==false&&allsex==false) {
					JOptionPane.showMessageDialog(null, "请选择性别", "编辑消息",JOptionPane.WARNING_MESSAGE);
				}else if( age.equals("")) {
					JOptionPane.showMessageDialog(null, "年级不能为空", "编辑消息",JOptionPane.WARNING_MESSAGE);
				}else if ( grade.equals("")) {
					JOptionPane.showMessageDialog(null, "班级不能为空", "编辑消息",JOptionPane.WARNING_MESSAGE);
				}else if(number.equals("")) {
					JOptionPane.showMessageDialog(null, "学号不能为空", "编辑消息",JOptionPane.WARNING_MESSAGE);
				}else {
					if(Manage.Men.isSelected()==true) {
						sex=Manage.Men.getText();
					}else {
						sex=Manage.Women.getText();
						
					}
				
					 Mysqld.changeStudeng(name, sex, age , grade, number,numberA);
				}
				
				
			}		
			if(button.getName()=="show") {
				
				String numberA=Manage.numbeconditiontext.getText();//单条信息
				
				
				String sex = "";
				String name=Manage.nametext.getText();
				boolean man=Manage.Men.isSelected();
				boolean woman=Manage.Women.isSelected();
				boolean allsex=Manage.allsex.isSelected();
				
				if(!man&&!woman&&!allsex) {
					Manage.allsex.setSelected(true);//选中
				}
				String age=Manage.agetext.getText();
				String grade=Manage.gradetext.getText();
				String number=Manage.numbertext.getText();
				if(Manage.Men.isSelected()==true) {
					sex=Manage.Men.getText();
				}else if(Manage.Women.isSelected()==true){
					sex=Manage.Women.getText();
					
				}
				
			
				
				if(numberA.equals("")) {
	
					 if(name.equals("")&&allsex&&age.equals("")&&grade.equals("")&&number.equals("")) {
						  Mysqld.findAllStudeng();
					
					 }else {
						 //查找条件消息的
						 if(name.equals("")) {
							 name=".*?";
						 }
						 if(sex.equals("")) {
							 sex=".*?";
						 }
						 if(age.equals("")) {
							 age=".*?";
						 }
						 if(grade.equals("")) {
							 grade=".*?";
						 }
						 if(number.equals("")) {
							 number=".*?";
						 }
						 Mysqld.finConStudent(name,sex,age,grade,number) ;
						 
					 }
					 
						//ResultSet rs=Mysqld.getRs();//获取所有结果的rs
				} else if(!numberA.equals("")) {
					 Mysqld.findOneStudent(numberA);
					 
					 
				}
					
			}
			if(button.getName()=="reset") {
				Manage.nametext.setText("");
				Manage.allsex.setSelected(true);
				Manage.agetext.setText("");
				Manage.gradetext.setText("");
				Manage.numbertext.setText("");
			
		
				
				
			}
			//_________________________________________________
			
			
			
			
		}catch (ClassCastException e1) {
			
			
			try {
				item=(JMenuItem) e.getSource();
				if(item.getName()=="item1") {
					if(accountA.equals("root")) {
						Mysqld.onlineAccount();
					}else {
						JOptionPane.showMessageDialog(null, "你不是管理员账户无法查看", "消息",JOptionPane.WARNING_MESSAGE);
					}
					
				}
				if(item.getName()=="item2") {
					if(accountA.equals("root")) {
						Mysqld.AllAccount() ;
					}else {
						JOptionPane.showMessageDialog(null, "你不是管理员账户无法查看", "消息",JOptionPane.WARNING_MESSAGE);
					}
					
				}
				if(item.getName()=="item3") {
					ChangeAccountMessage c=new ChangeAccountMessage();
				}
				if(item.getName()=="item4") {
				 aa=new ChangeOwnPassword();
				}
				if(item.getName()=="item1_1") {
					
					Mysqld.setStart(accountA,"0");
					manage.dispose();
				}
				if(item.getName()=="item1_2") {
					Mysqld.setStart(accountA,"0");
					manage.dispose();
					StudentSystem.show();
					//打开那登录窗口
				}
		
		
					
				

			}catch(Exception e2) {
				
			}
			
		}
	}
	public static void setStart() {
		Mysqld.setStart(accountA,"0");
	}
	void checkStart() {
		RunGetAccountStart run =new RunGetAccountStart();
		
		cheack=new Thread(run);
		cheack.start();
	}
	
	public static void addAble(ResultSet rs) {
		String  data[]=new String [5];
		try {
			while(rs.next()) {
				data[0]=rs.getString(1) ;
				data[1]=rs.getString(2) ;
				data[2]=rs.getString(3) ;
				data[3]=rs.getString(4) ;
				data[4]=rs.getString(5) ;
				Manage.model.addRow(data);
				
			}
			
			
		}catch(SQLException e) {
			
		}
		
	
	}
	public static void addOneAble(ResultSet rs) {
		String  data[]=new String [5];
		try {
				rs.next();
				data[0]=rs.getString(1) ;
				data[1]=rs.getString(2) ;
				data[2]=rs.getString(3) ;
				data[3]=rs.getString(4) ;
				data[4]=rs.getString(5) ;
				
				Manage.nametext.setText(data[0]);
				if(data[1].equals("男")) {
					Manage.Men.setSelected(true);
				}else if(data[1].equals("女")) {
					Manage.Women.setSelected(true);
				}
				Manage.agetext.setText(data[2]);
				Manage.gradetext.setText(data[3]);
				Manage.numbertext.setText(data[4]);
			
				Manage.model.addRow(data);
				

			
			
		}catch(SQLException e) {
			
		}
		
		
	}


}
