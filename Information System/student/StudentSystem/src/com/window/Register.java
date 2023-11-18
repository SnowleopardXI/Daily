package com.window;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Toolkit;
import java.awt.event.ActionListener;
import java.awt.event.FocusListener;
import java.awt.event.KeyListener;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

import com.event.AccountEvent;
import com.stytle.Fronts;

public class Register  extends JFrame{
	//定义布局
	FlowLayout flowlayout;//定义一个布局
	//定义窗口的高度和宽度
	final int WIDTH=410;//设置顶层框架的宽度
	final int HEIGHT=345;//设置顶层框架的高度
	//定义箱子
	javax.swing.JPanel jpanel_1;//放图片和其他的盘子
	javax.swing.JPanel jpanel_2;//只是放标题
	javax.swing.JPanel jpanel_3;//只是放标题
	
	//定义监听
	ActionListener lintener_1;//账号文本框 的监听

	
	
	
	//定义按钮和标签
	JLabel bgimg;//定义背景  标签
	JLabel title;//定义标题   标签
	JLabel name;//定义名字标签
	public static JTextField nametext;//定义名文本框
	
	
	JLabel account;//定义账号标题
	public static JTextField accounttext;//定义账号输入文本
	
	
	JLabel password;//定义密码标签
	public static JPasswordField passwordtext;//定义密码文本框

	
	JLabel okpassword;//定义确认
	public static JPasswordField okpasswordtext;//定义确认密码文本框
	
	
	public static JButton reg;//注册按钮
	
	
	public Register() {
		init();
		setVisible(true); //设置当前窗口是否可显示 
		setResizable(false);//窗口的大小不可边
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);//设置默认关闭方式
		validate();//让组件生效
		
	}
	
	void init() {
		//定义布局
		flowlayout=new FlowLayout(FlowLayout.CENTER);//居中对齐 
		
		//先设置窗口显示的位置
		// 设置当前窗口的大小
		Toolkit kit =Toolkit.getDefaultToolkit();//获取对象大小	//设置窗口位置
		Dimension screenSize=kit.getScreenSize();
		int width=screenSize.width;
		int height=screenSize.height;//获取屏幕高度和宽度
		int x=(width-WIDTH)/2;
		int y=(height-HEIGHT)/2;
		this.setBounds(x, y,WIDTH,HEIGHT);
		//设置盘子大小
		jpanel_1=new javax.swing.JPanel();
		jpanel_1.setPreferredSize(new Dimension (WIDTH,HEIGHT));
		jpanel_1.setLayout(null);//设置布局
		jpanel_1.setOpaque(false);//将当前的盘子设置成透明
		//设置背景图片
		ImageIcon img=new ImageIcon("src/img/2.jpg");//将图片读取放到img变量里面
		bgimg=new JLabel(img);
		bgimg.setBounds(0,0,img.getIconWidth(), img.getIconHeight());//设置背景图片 设置背景位置
		//设置一个标题
		Fronts fronts=new Fronts();
		
		title=new JLabel("毕业生信息管理系统账号注册");
		title.setFont(fronts.title);
		title.setForeground(Color.gray);
		//对箱子二的内容进行初始化
		jpanel_2=new javax.swing.JPanel();
		jpanel_2.setBounds(0, 30, WIDTH-10, 70);
		jpanel_2.setOpaque(false);//将当前的盘子设置成透明
		jpanel_2.setLayout(flowlayout);
		//初始化第三箱子
		jpanel_3=new javax.swing.JPanel();
		jpanel_3.setBounds(25, 100,350,200);
		jpanel_3.setOpaque(false);//将当前的盘子设置成透明
		jpanel_3.setLayout(flowlayout);//设置布局
		//第一行数据进行初始化
		name =new JLabel("姓        名:");
		name.setFont(fronts.account);
		nametext=new JTextField(20);
		name.setForeground(new Color(102,102,102));
		nametext.setForeground(new Color(18,120,192));
		nametext.setPreferredSize(new Dimension(15,28));
		nametext.setFont(fronts.accounttext);
	

		
		
		//第二行
		account =new JLabel("账        号:");
		account.setFont(fronts.account);
		accounttext=new JTextField(20);
		account.setForeground(new Color(102,102,102));
		accounttext.setForeground(new Color(18,120,192));
		accounttext.setPreferredSize(new Dimension(15,28));
		accounttext.setFont(fronts.accounttext);
			
	
		
		//第三行
		password =new JLabel("密        码:");
		password.setFont(fronts.account);
		passwordtext=new JPasswordField(20);
		password.setForeground(new Color(102,102,102));		
		passwordtext.setForeground(new Color(18,120,192));
		passwordtext.setPreferredSize(new Dimension(15,28));
		passwordtext.setFont(fronts.accounttext);
		
		

		
		
		//passwordsatisfy.setBounds(0,0,img.getIconWidth(), img.getIconHeight());//设置背景图片 设置背景位置
		//第四行
		
		okpassword =new JLabel("确认密码:");
		okpassword.setFont(fronts.account);
		okpasswordtext=new JPasswordField(20);
		okpassword.setForeground(new Color(102,102,102));		
		okpasswordtext.setForeground(new Color(18,120,192));
		okpasswordtext.setPreferredSize(new Dimension(15,28));
		okpasswordtext.setFont(fronts.accounttext);

		
	
		//第五行
		reg=new JButton("注          册");
		reg.setPreferredSize(new Dimension(290,30));
		reg.setFont(fronts.ok);
		reg.setForeground(new Color(244,170,128));
	
		//第一行
		jpanel_3.add(name);
		jpanel_3.add(nametext);

		//第二行
		jpanel_3.add(account);
		jpanel_3.add(accounttext);

		//第三行
		jpanel_3.add(password);
		jpanel_3.add(passwordtext);

		//第四行
		jpanel_3.add(okpassword);
		jpanel_3.add(okpasswordtext);
	
		//最后一行
		jpanel_3.add(reg);
		jpanel_2.add(title);
		
		jpanel_3.setBorder(BorderFactory.createTitledBorder("账号注册界面"));
		
		jpanel_1.add(jpanel_3);
		jpanel_1.add(jpanel_2);
		jpanel_1.add(bgimg);
		this.add(jpanel_1);//将箱子1添加到最低层  
		setAllTag();
		allEvent();
	}
	
	void allEvent() {
	
		lintener_1=new AccountEvent();
		nametext.addActionListener(lintener_1);
		accounttext.addActionListener(lintener_1);
		passwordtext.addActionListener(lintener_1);
		okpasswordtext.addActionListener(lintener_1);
		reg.addActionListener(lintener_1);
		
	}
	void setAllTag() {

		nametext.setName("nametext");//姓名
		accounttext.setName("accounttext");//账号
		passwordtext.setName("passwordtext");//定义密码文本框
		okpasswordtext.setName("okpasswordtext");//定义确认密码文本框
		reg.setName("reg");
		
		
	}
	
	
	
}
