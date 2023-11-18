package otcyan.java.model;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.HashMap;
import java.util.Vector;

import otcyan.java.bean.Bank;
import otcyan.java.bean.Seat;
import otcyan.java.bean.User;

public class FileOperation{
	
	/**
	 * 登录文件保存
	 * @param path 文件保存路径
	 * @return  
	 */
	public boolean save(String pathName,Vector<String> loginNames){
		
		boolean b = true ;
		BufferedWriter bWriter = null ;
		try {
			bWriter = new BufferedWriter(new FileWriter(new File(pathName))) ;
			for(String loginName : loginNames){
				bWriter.write(loginName) ;
				bWriter.newLine() ;
			}
			bWriter.flush() ;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			b = false ;
		}finally{
			if(bWriter!=null)
				try {
					bWriter.close() ;
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
		}
				
		return b ;
	}
	/**
	 * 登录文件加载
	 * @param path
	 */
	public Vector<String> loading(String pathName){
		
		Vector<String> loginNames = new Vector<String>() ;
		BufferedReader bReader = null ;
		File file = new File(pathName) ;
		if(!file.exists()){
			try {
				file.createNewFile() ;
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		try {
			bReader = new BufferedReader(new FileReader(file)) ;
			while(true){
				String loginName = bReader.readLine() ;
				if(loginName==null){
					break ;
				}
				loginNames.add(loginName) ;
				
			}
		}catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			if(bReader!=null)
				try {
					bReader.close() ;
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
		}
		return loginNames ;
	}
	/**
	 * 保存的是具体的票信息
	 * @param seat
	 * @param user
	 * @param ticketNum
	 * @param ticketType
	 * @param ticketDate
	 * @return
	 */
	public boolean saveTickets(Seat seat,User user,String seatNum,String ticketType,String ticketDate,String ticketId){
		
		boolean b = true ;
		BufferedWriter bw = null ;
		try {
			bw = new BufferedWriter(new FileWriter(new File("path/"+ticketId))) ;
			///写入到文件里
			bw.write("姓名：   "+user.getU_name()) ;
			bw.newLine() ;
			bw.write("身份证：   "+user.getU_idcard()) ;
			bw.newLine() ;
			bw.write("出发地：   "+seat.getfInfo().getF_start().getA_city()+"  "+seat.getfInfo().getF_start().getA_air()) ;
			bw.newLine() ;
			bw.write("目的地：  "+seat.getfInfo().getF_end().getA_city()+"  "+seat.getfInfo().getF_end().getA_air()) ;
			bw.newLine() ;
			bw.write("座位：  "+ticketType+"   "+seatNum) ;
			bw.newLine() ;
			bw.write("登机时间   "+ticketDate) ;
			bw.newLine() ;
			bw.flush() ;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			b = false ;
			e.printStackTrace();
		}finally{
			try {
				if(bw!=null) 
					bw.close() ;
			} catch (IOException e) {
				// TODO Auto-generated catch block
				b = false ;
				e.printStackTrace();
			}
		}
		return b ;
		
	}

	public boolean saveBank(HashMap<String, Bank> map) {
		
		boolean b = true ;
		ObjectOutputStream oos = null ;
			try {
				oos = new ObjectOutputStream(new FileOutputStream(new File("path/bank"))) ;
				//写入到文件 中
				oos.writeObject(map) ;
				oos.flush() ;
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}finally{
				if(oos!=null)
					try {
						oos.close() ;
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
			}
		return b ;
	}
	
	public HashMap<String, Bank> loadBank(){
		
		HashMap<String, Bank> map = null ;
		File file = new File("path/bank") ;
		if(!file.exists()){
			try {
				file.createNewFile() ;
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		ObjectInputStream ois = null ;
			try {
				ois = new ObjectInputStream(new FileInputStream(new File("path/bank"))) ;
				//写入到文件 中
				map = (HashMap<String, Bank>)ois.readObject() ;
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (ClassNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}finally{
				if(ois!=null)
					try {
						ois.close() ;
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
			}
			return map ;
	}
}
