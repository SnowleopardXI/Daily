package com.window;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Toolkit;
import java.awt.event.ActionListener;

/*日期：2021年1月2日
 * 创作者:B站up主 翘凳子
 * QQ:3058333641
 * 当前类负责，调用开始的图形界面
 * */
import javax.swing.*;

import com.event.AccountEvent;
import com.event.LoginEvent;
import com.event.RegEvent;
import com.stytle.Fronts;

public class LoginStart extends JFrame {
	//FlowLayout flowlayout;
	FlowLayout flowlayout;//定义一个布局
	
	
	
	//需要5个标签  和一个文本框，和一个密码框  和一个登录按钮
	JLabel bgimg;//定义背景  标签
	//JLabel register;//定义注册   标签
	JLabel account;//定义账号    标签
	JLabel password;//定义密码 	标签
	JLabel title;//定义标题   标签
	public static JTextField  accounttext;//输入账号文本
	public static JPasswordField passwordtext;//输入密码 框
	JButton ok;//登录按钮
	JButton register;//注册按钮
	//窗口变量  
	final int WIDTH=500;//设置顶层框架的宽度
	final int HEIGHT=350;//设置顶层框架的高度
	//定义一个箱子 
	javax.swing.JPanel jpanel_1;//放图片和其他的盘子
	javax.swing.JPanel jpanel_2;//只放标题
	javax.swing.JPanel jpanel_3;//放账号密码标题 和编辑框和密码框
	//javax.swing.JPanel jpanel_4;//放账号密码标题 和编辑框和密码框
	//监听类的定义
	RegEvent regevent;//定义注册标签的鼠标监听事件
	
	ActionListener lintener_1;
	
	
	
	public LoginStart() {
		init();
		setVisible(true); //设置当前窗口是否可显示 
		setResizable(false);//窗口的大小不可变
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);//设置默认关闭方式
		validate();//让组件生效
		
	}
	
	void init() {
		//定义一个布局
		flowlayout=new FlowLayout(FlowLayout.CENTER);
		//给盘子1创建对象
		jpanel_1=new javax.swing.JPanel();
		jpanel_1.setBounds(0, 0, WIDTH, HEIGHT);
		jpanel_1.setLayout(null);//设置布局为空
		//给盘子2创建对象  居中对齐
		jpanel_2=new javax.swing.JPanel();
		jpanel_2.setBounds(0, 50, WIDTH, 50);
		jpanel_2.setLayout(flowlayout);
		jpanel_2.setOpaque(false);//将当前的盘子设置成透明
		//给箱子3进行初始化
		jpanel_3=new javax.swing.JPanel();
		jpanel_3.setBounds(100, 105, 280,130);
		jpanel_3.setLayout(flowlayout);
		jpanel_3.setOpaque(false);//将当前的盘子设置成透明
		
		
		
		//初始化字体类 
		Fronts fronts=new Fronts();
		//添加标题
		this.setTitle("毕业生信息管理系统");
		
		// 设置当前窗口的大小
		Toolkit kit =Toolkit.getDefaultToolkit();//获取对象大小	//设置窗口位置
		Dimension screenSize=kit.getScreenSize();
		int width=screenSize.width;
		int height=screenSize.height;//获取屏幕高度和宽度
		int x=(width-WIDTH)/2;
		int y=(height-HEIGHT)/2;
		this.setBounds(x, y, WIDTH, HEIGHT);
		
		//设置背景图片
		ImageIcon img=new ImageIcon("src/img/1.jpg");//将图片读取放到img变量里面
		bgimg=new JLabel(img);
		bgimg.setBounds(0,0,img.getIconWidth(), img.getIconHeight());//设置背景图片 设置背景位置
		
		
		//添加标题 
		title=new JLabel("毕 业 生 信 息 管 理 系 统");
		title.setFont(fronts.title);
		title.setForeground(Color.WHITE);
		//添加账号和密码 还有编辑框等 
		account=new JLabel("账号 ");
		account.setFont(fronts.account);
		account.setForeground(new  Color(255,228,181));
		//添加账号文本框
		accounttext=new JTextField(20);
		accounttext.setFont(fronts.accounttext);
		accounttext.setForeground(new  Color(224,57,151));
		//添加密码标签
		password=new JLabel("密码 ");
		password.setFont(fronts.account);
		password.setForeground(new  Color(255,228,181));
		//密码框
		passwordtext=new JPasswordField(20);
		passwordtext.setFont(fronts.accounttext);
		passwordtext.setForeground(new  Color(224,57,151));
		//登录按钮
		ok=new JButton("登录");
		ok.setPreferredSize(new Dimension(110,35));
		ok.setFont(fronts.ok);
		ok.setBackground(new Color(8,189,252));
		ok.setForeground(new Color(255,255,255));
		ok.setName("ok");
		//注册标签
		//register=new JLabel("注册账号");
		//register.setBounds(410, 210, 100, 40);
		//register.setFont(fronts.register);
		//register.setForeground(new Color(0,255,255));
		//注册按钮
		register=new JButton("注册");
		register.setPreferredSize(new Dimension(110,35));
		register.setFont(fronts.register);
		register.setBackground(new Color(8,189,252));
		register.setForeground(new Color(255,255,255));
		register.setName("register");
		
		
		
		
		
		
		//添加的操作
		jpanel_1.add(register);
		jpanel_1.add(register);
		jpanel_3.add(account);
		
		jpanel_3.add(accounttext);
		jpanel_3.add(password);
		jpanel_3.add(passwordtext);
		jpanel_3.add(ok);
		jpanel_3.add(register);
		
		jpanel_2.add(title);
		jpanel_1.add(jpanel_2);
		jpanel_1.add(jpanel_3);
		jpanel_1.add(bgimg);//将图片放到盘子里面
		this.add(jpanel_1);
		
		allEvent();
	}
	//所有处理事件都在这个地方去写
		void allEvent() {
			regevent=new RegEvent();
			lintener_1=new LoginEvent();
			register.addMouseListener(regevent);
			ok.addActionListener(lintener_1);
			
		}
		//这个方法是让当前窗口消失
		public void close() {
			this.dispose();
		}
	

}
