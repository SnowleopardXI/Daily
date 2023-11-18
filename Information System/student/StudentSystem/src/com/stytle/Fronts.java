package com.stytle;

import java.awt.Font;

public class Fronts {
	
	
	public static Font title;
	public static Font account;
	 
	public static Font accounttext;
	public static Font ok;
	public static Font register;
	public static Font registerAcountText;
	
	public Fronts(){
		
		title=new Font("宋体",Font.BOLD,28);//标题字体
		account=new Font("华文bai行楷",Font.BOLD,18);//标签
		accounttext=new Font("宋体",Font.PLAIN,18);//账号框
		ok=new Font("宋体",Font.BOLD,18);//登录按钮
		register=new Font("宋体",Font.BOLD,18);//注册按钮
		registerAcountText=new Font("宋体",Font.PLAIN,10);//注册文本框字体
		
	}
}
