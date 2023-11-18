package otcyan.java.tools;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Toolkit;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Tookit {

	public static DateFormat getDateFormat(String type){
		SimpleDateFormat dateFormat = new SimpleDateFormat(type) ;//"yyyy/MM/dd k:m:s E"
		return dateFormat ;
	}
	public static Color getColor(){
		return new Color(0xC4C43B) ;
	}
	public static Font getFont1(){
		return new Font("微软雅黑", Font.PLAIN, 14) ;
	}
	public static Font getFont6(){
		return new Font("微软雅黑", Font.BOLD,30);
	}
	public static Font getFont2(){
		return new Font("微软雅黑", Font.BOLD, 20) ;
	}
	public static Font getFont3(){
		return new Font("微软雅黑", Font.PLAIN, 18) ;
	}
	public static Font getFont4(){
		return new Font("微软雅黑", Font.BOLD, 18) ;
	}
	public static Font getFont5(){
		return new Font("微软雅黑", Font.BOLD, 24) ;
	}
	
	
	/*
	 * 得到当前时间
	 */
	public static String getCurrentTime(){
		StringBuffer sb = new StringBuffer();
		Date date = new Date() ;
		SimpleDateFormat dateFormat = new SimpleDateFormat("k:m:s") ;
		
		sb.append("<html>"+dateFormat.format(date)+"<br>") ;
		dateFormat = new SimpleDateFormat("yyyy/MM/dd") ;
		sb.append(dateFormat.format(date)+"") ;
		dateFormat = new SimpleDateFormat("E");
		sb.append(dateFormat.format(date)+"</html>") ;
		return sb.toString() ;
	}
	
	public static Dimension getScreen(){
		return Toolkit.getDefaultToolkit().getScreenSize() ;
	}
}
