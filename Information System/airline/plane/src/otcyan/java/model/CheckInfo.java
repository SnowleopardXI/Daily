package otcyan.java.model;

import java.text.DateFormat;
import java.text.ParseException;
import java.util.Date;
import java.util.Vector;

import javax.swing.JOptionPane;

import otcyan.java.bean.User;
import otcyan.java.tools.Tookit;

public class CheckInfo {

	private DataHandle dataHandle ;
	public CheckInfo(){
		dataHandle = new DataHandle() ;
	}
	/**
	 * 检测注册信息
	 * @param user
	 * @return
	 */
	public boolean checkRegistInfo(User user){
	
		if(this.check(user)){
			//格式正确
			boolean b = checkisExist("select u_id from users where 1=?", new String[]{"1"}, user.getU_id()) ;
			if(b){
				JOptionPane.showMessageDialog(null, user.getU_id()+"已经存在！！");
				return false;
			}
		}else {
			return false ;
		}
		//检查UserId是不是存在
		
		return true;
	}
	
	public boolean check(User user){
		
//		boolean b = false ;
		String userId = user.getU_id() ; 
		String userPwd=user.getU_password(); //
		String userName=user.getU_name();
		String userTel=user.getU_telephone();//11为
		String userAddr=user.getU_address();
		String userEmail=user.getU_email();
		String userIdcard=user.getU_idcard();
		System.out.println(user);
		//判断用户名是否超出
		if(userId.length()>20){
			JOptionPane.showMessageDialog(null, "用户名长度不能超过20!");
			return false ;
		}
		//判断是否存在
		
		//判断姓名是否超长
		if(userName.length()>20){
			JOptionPane.showMessageDialog(null, "姓名长度不能超过20!");
			return false;
		}
		//判断地址是否超出
		if(userAddr.length()>100){
			JOptionPane.showMessageDialog(null, "地址长度不能超过100!");
			return false;
		}
		//判断电话号码是否正确"^(0\\d{2,3}-)?(\\d{7,8})|(0?1\\d{10})$"
		if(!userTel.matches("^(0\\d{2,3}-)?(\\d{7,8})|(0?1\\d{10})$")){
			JOptionPane.showMessageDialog(null, "电话号码格式不对!");
			return false;
		}
	    //判断电子邮箱是否正确
		if(!userEmail.matches("^\\w{1,}@[0-9a-zA-Z]{1,10}.(com|cn)$")){
			JOptionPane.showMessageDialog(null, "电子邮箱格式不正确!");
		}
		//判断身份证号码是否正确
		if(!userIdcard.matches("^\\d{17}[0-9a-zA-Z]$")){
			JOptionPane.showMessageDialog(null, "身份证格式不正确!");
			return false;
		}
		return true ;
	}
	/**
	 * 判断航班是不是存在
	 * @param sql
	 * @param paras
	 * @param txtNum
	 * @return
	 */
	public boolean checkisExist(String sql,String[] paras,String num){
	
		boolean b = false ;
			Vector<String> v = dataHandle.queryStringVector(sql, paras) ;
			if(v.contains(num)){
				//表示已经存在
				b=true ;
			}
		return b ;
	}
	
	public  boolean isTrue(String date){
		//date格式是不是正确 
		if(!date.matches("\\d{4}-\\d{2}-\\d{2}")){
			JOptionPane.showMessageDialog(null, "格式错误!!形如：2012-01-01") ;
			return false ;
		}
		//判断  不能小于 当前日期 
		DateFormat sdf = Tookit.getDateFormat("yyyy-MM-dd") ;
		String currentTime = sdf.format(new Date()) ;//2012-12-13
		System.out.println(currentTime);
		String str[] = currentTime.split("-") ;//currentTime  表示 当前的    2013-03-02
		String strs[] = date.split("-") ;//date   1991  传入的年                                 1991-10-11
		if(!strs[1].matches("0[1-9]|1[0-2]")){
			//月<0 >12 
			JOptionPane.showMessageDialog(null, "月份不能小于0并且大于12") ;
		}
		
		//str[0]  strs[0]  表示 年
		//str[1]  表示月
		//str[2]   表示日 
		if(str[0].compareTo(strs[0])<0){//当前  时间  year  >  date 时间 year  正常
			//表示 当前年要小不同
			JOptionPane.showMessageDialog(null, "输入的年"+strs[0]+"不合理") ;
			return false ;
		}
		
		if(str[0].compareTo(strs[0])==0){
			//表示 相等
			if(str[1].compareTo(strs[1])<0){
				//当前月小 
				if(!isDay(strs[1],strs[2])){
					return false ;
				}
			}
			if(str[1].compareTo(strs[1])==0){
				//月相等
				if(!isDay(strs[1],strs[2])){
					return false ;
				}
			}
			if(str[1].compareTo(strs[1])>0){
				//当前月要大于
				return false ;
			}
		}
		
		if(str[0].compareTo(strs[0])>0){
			//表示当前年要大
			JOptionPane.showMessageDialog(null, "输入的年"+strs[0]+"不合理") ;
			return false;
		}
		
		
		//格式都 正确 
		
		//判断 距离时间 
		try {
			long currentTimeSecond = sdf.parse(currentTime).getTime() ;
			long dateTimeSecond = sdf.parse(date).getTime() ;

			if(dateTimeSecond-currentTimeSecond>10*24*3600*1000){
				//超过10天了
				JOptionPane.showMessageDialog(null, "只能输入10天以内的日期") ;
				return false ;
			}
			if(dateTimeSecond-currentTimeSecond<0){
				//超过10天了
				JOptionPane.showMessageDialog(null, "只能输入"+currentTime+"以后的日期") ;
				return false ;
			}
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		//格式  是不是正确 的
		return true ;
	}
	
	public static boolean isDay(String month,String day){
		
		if(month.matches("0[1]|0[3]|0[5]|0[7]|0[8]|0[10]|0[12]|")){
			//day是30天
			if(day.compareTo("00")<0 || day.compareTo("31")>0){
				return false ;
			}
		}
		if(month.matches("0[2]")){
			//day是30天
			if(day.compareTo("00")<0 || day.compareTo("29")>0){
				return false ;
			}
		}
		if(month.matches("0[4]|0[6]|0[9]|0[11]")){
			//day是30天
			if(day.compareTo("00")<0 || day.compareTo("30")>0){
				return false ;
			}
		}
		
		return true ;
	}
}
