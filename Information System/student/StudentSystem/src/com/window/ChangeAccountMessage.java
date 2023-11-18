package com.window;

import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Toolkit;
import java.awt.event.ActionListener;

import com.event.LoginEvent;

import javax.swing.*;

public class ChangeAccountMessage extends  JFrame {
	FlowLayout flowlayout;//定义一个布局
	final int WIDTH=230;//设置顶层框架的宽度
	final int HEIGHT=160;//设置顶层框架的高度
	
	//密码    姓名   2个标签  1个编辑框  一个密码框  和一个按钮
	JLabel account;
	public static JTextField accounttext;
	JLabel name;
	JLabel password;
	public static JTextField nametext;
	public static JPasswordField passwordtext;
	JButton change;
	
	//创建一个监听
	ActionListener lintener_1;
	public ChangeAccountMessage() {
		init();
		setVisible(true); //设置当前窗口是否可显示 
		setResizable(false);//窗口的大小不可边
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);//设置默认关闭方式
		validate();//让组件生效
		
	}
	void init() {

		// 设置当前窗口的大小
		Toolkit kit =Toolkit.getDefaultToolkit();//获取对象大小	//设置窗口位置
		Dimension screenSize=kit.getScreenSize();
		int width=screenSize.width;
		int height=screenSize.height;//获取屏幕高度和宽度
		int x=(width-WIDTH)/2;
		int y=(height-HEIGHT)/2;
		this.setBounds(x, y, WIDTH, HEIGHT);
		flowlayout=new FlowLayout(FlowLayout.CENTER);
		this.setLayout(flowlayout);//设置布局
		name=new JLabel("姓名");
		password=new JLabel("密码");
		account=new JLabel("账户");
		nametext=new JTextField(15);
		passwordtext=new JPasswordField(15);
		accounttext=new JTextField(15);
		change=new JButton("更改学生信息");
		
		change.setName("change");
		
	
		
		
		this.setTitle("改信息");
		
		
		this.add(account);
		this.add(accounttext);
		
		this.add(name);
		this.add(nametext);
		this.add(password);
		this.add(passwordtext);
		this.add(change);
		lintener_1=new LoginEvent();
		change.addActionListener(lintener_1);
		
	}
	

}
