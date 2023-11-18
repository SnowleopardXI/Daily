D:\Workspace\Daily\Information System\student\StudentSystempackage com.window;

import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Toolkit;
import java.awt.event.ActionListener;

import javax.swing.JFrame;

import com.event.LoginEvent;

import javax.swing.*;

public class ChangeOwnPassword extends  JFrame {
	FlowLayout flowlayout;//定义一个布局
	final int WIDTH=320;//设置顶层框架的宽度
	final int HEIGHT=80;//设置顶层框架的高度
	//一个标签  一个密码框一个  和一个按钮  
	JLabel password;//密码标签
	public static JPasswordField passwordtext;//定义一个密码框
	JButton changeown;

	ActionListener lintener_1;
	public ChangeOwnPassword() {
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
		
		
		 password=new JLabel("密码");
		 passwordtext=new JPasswordField(15);
		 changeown=new JButton("修改密码");
		 
		 lintener_1=new LoginEvent();
		 changeown.addActionListener(lintener_1);
		
		 changeown.setName("changeown");
		this.setTitle("更改密码");
		
		this.add(password);
		this.add(passwordtext);
		this.add(changeown);
	}
	

}
