package com.Thread;

import com.event.LoginEvent;
import com.mysqld.Mysqld;
import com.window.StudentSystem;

public class RunGetAccountStart implements Runnable{//调用一个线程

	public static boolean Se=true;
	String account;
	@Override
	public void run() {
		// TODO Auto-generated method stub
		account=LoginEvent.accountA;
		
	
		while(Se) {
			String  start=Mysqld.findAccountStart(account);
			
			if(start.equals("0")) {
				LoginEvent.manage.dispose();
				Mysqld.setStart(account, "1");
				Se=false;
			}
		}
		
	}

}
