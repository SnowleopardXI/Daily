package com.window;
import com.mysqld.Mysqld;

public class StudentSystem {
	public static LoginStart loginstartA;

	public static void main(String[] args) {
		
		show();
		
	}
	static public  void show() {
		LoginStart loginstart=new LoginStart();//初始化构造方法
		loginstartA=loginstart;
		Mysqld a=new Mysqld("user","123456");
		//Manage aa=new Manage();
	}

}
