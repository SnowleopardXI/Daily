package com.event;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class WindowsEven extends WindowAdapter{
	
	 public void  windowClosing(WindowEvent e){
	     //
	
		 LoginEvent.setStart();
		 
	    }
}
