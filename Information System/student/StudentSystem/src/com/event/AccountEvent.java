package com.event;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.sql.*;

import javax.swing.JButton;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

import com.mysql.jdbc.Connection;
import com.mysqld.Mysqld;
import com.window.Register;
//只是大部分的监听
public class AccountEvent implements ActionListener{
	
	JTextField alluse;
	JButton allJbutton;
	Statement sql;
	ResultSet rs;
	@Override//重写父类
	public void actionPerformed(ActionEvent e) {
		
		try {
			
			alluse=(JTextField) e.getSource();//则证明他是按钮
			if(alluse!=null) {
				allUee();
			}
			
		}catch(Exception e1) {
			
			 allJbutton= (JButton) e.getSource();
			if( allJbutton.getName()=="reg") {
				Jbtton();
				
			}
			
		}			
	}
	void allUee() {
		if(alluse.getName()=="nametext") {
			Register.accounttext.requestFocus();
	
		}
		if(alluse.getName()=="accounttext") {
			Register.passwordtext.requestFocus();
		}
		if(alluse.getName()=="passwordtext") {
			Register.okpasswordtext.requestFocus();
		}
		if(alluse.getName()=="okpasswordtext"){
			
			Register.reg.requestFocus();
		}
	}
	void Jbtton()  {
		boolean nameT=Register.nametext.getText().equals("");
		boolean accountT=Register. accounttext.getText().equals("");
		//获取密码
		char[] str=Register.passwordtext.getPassword();
		String passwordtext =new String(str);
		boolean passwordT=passwordtext.equals("");
		
		
		str=Register.okpasswordtext.getPassword();
		String okpasswordtext =new String(str);
		boolean okpasswordT=okpasswordtext.equals("");
		
		
		
		if(nameT==true) {
			JOptionPane.showMessageDialog(null, "姓名不能为空", "提示",JOptionPane.WARNING_MESSAGE);
		}else if(accountT==true){
			JOptionPane.showMessageDialog(null, "账号不能为空", "提示",JOptionPane.WARNING_MESSAGE);
		}else if(passwordT==true) {
			JOptionPane.showMessageDialog(null, "密码不能为空", "提示",JOptionPane.WARNING_MESSAGE);
		}else if(okpasswordT==true) {
			JOptionPane.showMessageDialog(null, "确认密码不能为空", "提示",JOptionPane.WARNING_MESSAGE);
		}else if(passwordtext.equals(okpasswordtext)==false){
			//如果确认密码和密码是不一样的
			JOptionPane.showMessageDialog(null, "密码输入不一致", "提示",JOptionPane.WARNING_MESSAGE);
		}else {
			//姓名文本
			String name=Register.nametext.getText();
			//账号文本
			String account=Register. accounttext.getText();
			//密码文本
			String password= passwordtext;
			java.sql.Connection con=Mysqld.con;
			PreparedStatement preSql;
			String Uri="insert into user values(?,?,?,?)";
			try {
				preSql=con.prepareStatement(Uri);
				preSql.setString(1, name);
				preSql.setString(2, account);
				preSql.setString(3, password);
				preSql.setString(4, "0");
				int ok=preSql.executeUpdate();
				JOptionPane.showMessageDialog(null, "注册成功", "注册消息",JOptionPane.WARNING_MESSAGE);
				
			}catch(SQLException e) {
				JOptionPane.showMessageDialog(null, "当前账号已经存在", "注册消息",JOptionPane.WARNING_MESSAGE);
				
			}
			
		}
		
		
	}

}
