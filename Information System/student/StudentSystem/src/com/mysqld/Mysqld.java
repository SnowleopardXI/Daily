package com.mysqld;

import java.sql.*;

import javax.swing.JOptionPane;

import com.event.LoginEvent;

import com.window.ChangeAccountMessage;
import com.window.Manage;



public class Mysqld {
	
	public static Connection con=null;
	public Mysqld(String account,String password) {
		//定义了一个数据的账号和密码
		//第一步加载驱动
		try {
			Class.forName("com.mysql.jdbc.Driver");
			System.out.println("加载驱动成功");
		}catch (Exception e) {
			System.out.println("加载驱失败");
		}
		//
		
		String uri="jdbc:mysql://10.40.172.1:3306/student?characterEncoding=utf-8&useSSL=false";
		try {
			con=DriverManager.getConnection(uri,account,password);
			System.out.println("连接数据库成功");
		}catch(SQLException e) {
			System.out.println("连接数据库失败");
		}
	}
	//将注册信息写入
	public static boolean loginAccount(String account, String password) {
		//登录账号
		//对数据库的数据进行读读取
		Statement sql;
		ResultSet rs;
		String uri="select account,password from user";
		try {
			sql=con.createStatement();
			rs=sql.executeQuery(uri);
			while(rs.next()) {
				String acc=rs.getString(1);//返回的第一个值就是账号
				String pass=rs.getString(2);//返回的第一个值就是账号
				if(acc.equals(account)&&pass.equals(password)){
					return true;
				}
				
			}
		
		}catch(SQLException e) {
		
			return false;
		}
		return false;
		
	}
	public static void onlineAccount() {
		Statement sql;
		ResultSet rs;
		String uri="select * from user";
		try {
			sql=con.createStatement();
			rs=sql.executeQuery(uri);
			Manage.resultText.setText("");
			Manage.resultText.setText("姓名\t账号\t状态\n");
			while(rs.next()) {
				String name=rs.getString(1);//返回的第一个值就是账号
				String account=rs.getString(2);//返回的第一个值就是账号
				String password=rs.getString(3);//返回的第一个值就是账号
				String start=rs.getString(4);//返回的第一个值就是账号
				if(start.equals("1")) {
					System.out.println("在线");
					String uri1=Manage.resultText.getText()+name+"\t"+account+"\t在线"+"\n";
					Manage.resultText.setText(uri1);
					
				}

				
				}
				
			
		
		}catch(SQLException e) {
		

		}

		
	}
	public static void AllAccount() {
		Statement sql;
		ResultSet rs;
		String uri="select * from user";
		try {
			sql=con.createStatement();
			rs=sql.executeQuery(uri);
			Manage.resultText.setText("");
			Manage.resultText.setText("姓名\t账号\t状态\n");
			while(rs.next()) {
				String name=rs.getString(1);//返回的第一个值就是账号
				String account=rs.getString(2);//返回的第一个值就是账号
				String password=rs.getString(3);//返回的第一个值就是账号
				String start=rs.getString(4);//返回的第一个值就是账号
				if(start.equals("1")) {
				
					String uri1=Manage.resultText.getText()+name+"\t"+account+"\t在线"+"\n";
					Manage.resultText.setText(uri1);
					
				}
				if(start.equals("0")) {
					
					String uri1=Manage.resultText.getText()+name+"\t"+account+"\t离线"+"\n";
					Manage.resultText.setText(uri1);
					
				}

				
				}
				
			
		
		}catch(SQLException e) {
		

		}

		
	}
	public static void changeOtherAccountMessage() {
		ResultSet rs;
		PreparedStatement preSql;
		String sqlStr="update user set name=?,password=? where account=?";
		try {
			String account=ChangeAccountMessage.accounttext.getText();
			String name=ChangeAccountMessage.nametext.getText();
			String password=new String (ChangeAccountMessage.passwordtext.getPassword());
			preSql=con.prepareStatement(sqlStr);
			int ok = 100;
			if(account.equals("")) {
				JOptionPane.showMessageDialog(null, "账号不能为空", "更改消息",JOptionPane.WARNING_MESSAGE);
			}else if (name.equals("")) {
				JOptionPane.showMessageDialog(null, "姓名不能为空", "更改消息",JOptionPane.WARNING_MESSAGE);
			}else if (password.equals("")) {
				JOptionPane.showMessageDialog(null, "密码不能为空", "更改消息",JOptionPane.WARNING_MESSAGE);
			}else {
				preSql.setString(1, name);
				preSql.setString(2,password);
				preSql.setString(3, account);
				ok=preSql.executeUpdate();
				if(ok==0) {
					JOptionPane.showMessageDialog(null, "请输入正确账号", "更改消息",JOptionPane.WARNING_MESSAGE);
				}else {
					JOptionPane.showMessageDialog(null, "更改成功", "更改消息",JOptionPane.WARNING_MESSAGE);
				}
			
			}
			
			
			
		}catch(SQLException e) {
			
		}
	}
	public static void setStart(String account,String start) {//将账户的名字传入过来
		PreparedStatement preSql;
		String sqlStr="update user set start=? where account=?";
		try {
			preSql=con.prepareStatement(sqlStr);
			preSql.setString(1,  start);
			preSql.setString(2, account);
			preSql.executeLargeUpdate();
		}catch(SQLException e) {
			
		}
		
		
	}
	public static void changePassword(String account,String password) {
		PreparedStatement preSql;
		String sqlStr="update user set password=? where account=?";
		try {
			preSql=con.prepareStatement(sqlStr);
			preSql.setString(1, password);
			preSql.setString(2, account);
			preSql.executeLargeUpdate();
			
		}catch(SQLException e) {
			
		}
		
	}
	public static String  findAccountStart(String account) {
		PreparedStatement preSql;
		String sqlStr="select start from user where account=?";
		String satart="a";
		
		
		try {
			preSql=con.prepareStatement(sqlStr);
			preSql.setString(1, account);
			ResultSet rs = preSql.executeQuery();
			while(rs.next()) {
				satart=rs.getString(1);
				
			}
	
			return satart;
		}catch(SQLException e) {
			
			return satart;
		}
		
	}
	public static  void addStudent(String name,String sex,String age,String grade,String number) {
		PreparedStatement preSql;
		String sqlStr="insert into  stu(name,sex,age,grade,number) values(?,?,?,?,?)";
	
		
		
		try {
			preSql=con.prepareStatement(sqlStr);
			preSql.setString(1, name);
			preSql.setString(2, sex);
			preSql.setString(3, age);
			preSql.setString(4, grade);
			preSql.setString(5, number);
			int ok = preSql.executeUpdate();
			JOptionPane.showMessageDialog(null, "添加成功", "添加数据",JOptionPane.WARNING_MESSAGE);
		
		}catch(SQLException e) {
			JOptionPane.showMessageDialog(null, "当前学号已经存字", "添加数据",JOptionPane.WARNING_MESSAGE);
		
		}
		
		
	}
	public static  void delStudeng(String number) {
		PreparedStatement preSql;
		String sqlStr="delete from stu where number=?";

		try {
			preSql=con.prepareStatement(sqlStr);
			preSql.setString(1, number);
			int ok = preSql.executeUpdate();
			if(ok==0) {
				JOptionPane.showMessageDialog(null, "未找到相关学号", "消息",JOptionPane.WARNING_MESSAGE);
			}else {
				JOptionPane.showMessageDialog(null, "删除成功", "消息",JOptionPane.WARNING_MESSAGE);
			}
		
		}catch(SQLException e) {
			JOptionPane.showMessageDialog(null, "当前学号已经存字", "添加数据",JOptionPane.WARNING_MESSAGE);
		
		}
	}
	
	public static  void changeStudeng(String name,String sex,String age,String grade,String number,String numberT) {
		
		PreparedStatement preSql;
		String sqlStr="update stu  set name=?,sex=?,age=?,grade=?,number=? where number=?";
		try {
			preSql=con.prepareStatement(sqlStr);
			preSql.setString(1, name);
			preSql.setString(2, sex);
			preSql.setString(3, age);
			preSql.setString(4, grade);
			preSql.setString(5, number);
			preSql.setString(6, numberT);
			int ok = preSql.executeUpdate();
			if(ok==0) {
				JOptionPane.showMessageDialog(null, "学号重复或者输入学号不存在", "消息",JOptionPane.WARNING_MESSAGE);
			}else {
				JOptionPane.showMessageDialog(null, "更改成功", "消息",JOptionPane.WARNING_MESSAGE);
			}
		
		}catch(SQLException e) {
		
			System.out.println(e);
		}
		
		
	}
	public static  void   findAllStudeng() {
		PreparedStatement preSql;
		Manage.model.setNumRows(0);//将表格数据为0
		String sqlStr="select * from stu";//查找所有的
		try {
			preSql=con.prepareStatement(sqlStr);
			ResultSet rs = preSql.executeQuery();
			LoginEvent.addAble(rs);
		
		}catch(SQLException e) {
		
			System.out.println(e);
		}
		
	}
	public static  ResultSet getRs() {
		PreparedStatement preSql;
		ResultSet rs = null ;
		Manage.model.setNumRows(0);//将表格数据为0
		String sqlStr="select * from stu";//查找所有的
		try {
			preSql=con.prepareStatement(sqlStr);
			rs = preSql.executeQuery();
			
		
		}catch(SQLException e) {
		
			System.out.println(e);
		}
	
		return rs;
		
	
	}
	public static  void finConStudent(String name,String sex,String age,String grade,String number) {
		PreparedStatement preSql;
		ResultSet rs = null ;
		Manage.model.setNumRows(0);//将表格数据为0
		String sqlStr="select * from stu where name REGEXP? and sex REGEXP? and age REGEXP? and grade REGEXP? and number REGEXP?";//查找所有的
		try {
			preSql=con.prepareStatement(sqlStr);
			preSql.setString(1, name);
			preSql.setString(2, sex);
			preSql.setString(3, age);
			preSql.setString(4, grade);
			preSql.setString(5, number);
			rs= preSql.executeQuery();
			LoginEvent.addAble(rs);
		
		}catch(SQLException e) {
		
			System.out.println(e);
		}
		
	}
	public static  void findOneStudent(String number) {
		PreparedStatement preSql;
		ResultSet rs = null ;
		Manage.model.setNumRows(0);//将表格数据为0
		String sqlStr="select * from stu where number=?";
		try {
			preSql=con.prepareStatement(sqlStr);
			preSql.setString(1, number);
			rs= preSql.executeQuery();
			LoginEvent.addOneAble(rs);
		
		}catch(SQLException e) {
		
			System.out.println(e);
		}
		
	}

}
