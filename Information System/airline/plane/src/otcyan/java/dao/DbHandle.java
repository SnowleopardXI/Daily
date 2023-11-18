package otcyan.java.dao;

import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Vector;

import otcyan.java.bean.Bank;
import otcyan.java.bean.FlightAddr;
import otcyan.java.bean.FlightInfo;
import otcyan.java.bean.Seat;
import otcyan.java.bean.User;
import otcyan.java.tools.DBHelp;
import otcyan.java.view.TicketSearchPanel;

public class DbHandle {
	
	DBHelp dbHelp = null ;
	ResultSet rs = null ;
	
	public DbHandle(){
		dbHelp = new DBHelp() ;
	}
	/**
	 * 登录时数据库的查询
	 * @param sql  查询数据库语句
	 * @param paras 查询条件
	 * @return Object 返回的数据
	 */
	public Object loginQuery(String sql,String[] paras){
		
		rs = dbHelp.query(sql, paras) ;
		User user = null ;
		if(rs==null){
			return null ;
		}
		try {
			if(rs.next()){
				//如果有数据 的话，，就创建一个User表
				user = new User(rs.getString(1), rs.getString(2), rs
						.getString(3), rs.getString(4), rs.getString(5), rs
						.getString(6), rs.getString(7), rs.getString(8), rs
						.getString(9));
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			if(rs!=null)
				try {
					rs.close() ;
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			dbHelp.close() ;
		}
		System.out.println(user);
		return user ;
		
	}
	/**
	 * 数据库的增删改
	 * @param sql
	 * @param paras
	 * @return
	 */
	public boolean update(String sql , String[] paras){

		return dbHelp.update(sql, paras) ;
	}
	
	/**
	 * 查询一个机场地点
	 */
	public FlightAddr queryOneFlightAddr(String sql,String[] paras){
		
		rs = dbHelp.query(sql,paras) ;
		FlightAddr fAddr = null ;
		try {
			if(rs.next()){
				 fAddr = new FlightAddr(rs.getString(1), rs.getString(2), rs.getString(3)) ;
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return fAddr ;
	}
	
	/**
	 * 通过航班id查询飞机信息
	 * @param sql
	 * @param paras
	 * @param startAddr
	 * @param endAddr
	 * @return
	 */
	public FlightInfo queryFlightById(String sql,String[] paras ,FlightAddr startAddr,FlightAddr endAddr){
		
		rs = dbHelp.query(sql,paras) ;
		FlightInfo fInfo = null ;
		try {
			if(rs.next()){
				 fInfo = new FlightInfo(rs.getString(1), rs.getString(2), rs.getString(3),rs.getString(4),startAddr,endAddr,rs.getString(7)) ;
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return fInfo ;
	}
	
	/**
	 * 通过id查询座位
	 * select * from seat where f_number='CZ3809'
	 * seats.get(0).getfInfo().getf_type();
	 */
	public Vector<Seat> querySeatById(String sql, String[] paras,FlightInfo fInfo , FlightAddr fAddr){
		
		rs = dbHelp.query(sql,paras) ;
		Vector<Seat> seats = new Vector<Seat>() ;
		try {
			while(rs.next()){
				Seat s = new Seat(fInfo, rs.getString(2), rs.getString(3),rs.getDouble(4)) ;
				seats.add(s) ;
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
			
			
		return seats ;
	}

	/**
	 * 查询所有 的航班地点id号
	 * @param sql
	 * @param paras
	 * @return
	 */
	public Vector<FlightAddr> queryMulInfo(String sql,String[] paras){
		rs = dbHelp.query(sql,paras) ;
		Vector<FlightAddr> vector = new Vector<FlightAddr>() ;
		try {
			while(rs.next()){
				System.out.println(rs.getMetaData().getColumnCount() );
				FlightAddr fAddr = new FlightAddr(rs.getString(1), rs.getString(2), rs.getString(3)) ;
				vector.add(fAddr) ;
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return vector ;
	}
	
	public Bank queryOneBank(String sql , String[] paras ,User user){
		
		rs = dbHelp.query(sql, paras) ;
		Bank bank= null ;
		if(rs==null){
			return null ;
		}
		try {
			if(rs.next()){
				//如果有数据 的话，，就创建一个User表
				bank = new Bank(rs.getInt(1), rs.getString(2), user.getU_name(), user.getU_idcard(), rs.getString(5), rs.getString(6)) ;
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}finally{
			if(rs!=null)
				try {
					rs.close() ;
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			dbHelp.close() ;
		}
		System.out.println(user);
		return bank ;
	}
	/**
	 * 根据地点得到 飞机信息
	 * @param sql
	 * @param paras
	 * @return
	 */
	public FlightInfo queryFlightInfo(String sql,FlightAddr startCityId,FlightAddr endCityId,String str[]){
		
		System.out.println(str.length);
		String[] paras = null ;
		paras = (str.length==1?new String[]{startCityId.getA_id(),endCityId.getA_id()}:new String[]{startCityId.getA_id(),endCityId.getA_id(),str[0],str[1]});
		rs = dbHelp.query(sql, paras) ;
		FlightInfo fInfo = null ;
		if(rs==null){
			return null ;
		}
		try {
			if(rs.next()){
				//有数据   那么构建一个 FlightInfo
				fInfo = new FlightInfo(rs.getString(1), rs.getString(2), rs
						.getString(3), rs.getString(4), startCityId, endCityId,
						rs.getString(7));	
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			try {
				rs.close() ;
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			dbHelp.close() ;
		}
		return fInfo;
	}
	/**
	 * 得到 一个详细座位信息
	 * @param sql
	 * @param paras
	 * @return
	 */
	public Vector<Seat> querySeat(String sql ,String[] paras ,FlightInfo fInfo){
		
		Vector<Seat> seats = new Vector<Seat>() ;
		rs = dbHelp.query(sql, paras) ;
		//ResultSetMetaData rsmdData = rs.getMetaData() ;
		Vector<String> types = new Vector<String>();//存放类型
		try {
			while(rs.next()){
					Seat seat = new Seat(fInfo, rs.getString(2), rs.getString(3), rs.getDouble(4)) ;
						types.add(seat.getS_type()) ;
					seats.add(seat) ;
					System.out.println("***********"+seats.size());
			}
			//考虑没有三个舱的情况 
			if(seats.size()<3){
				if(types.contains("经济舱")){
					Seat seat = new Seat(fInfo, "经济舱", "--", 0) ;
					seats.add(seat) ;
				}
				if(types.contains("商务舱")){
					Seat seat = new Seat(fInfo, "商务舱", "--", 0) ;
					seats.add(seat) ;
				}
				if(types.contains("头等舱")){
					Seat seat = new Seat(fInfo, "头等舱", "--", 0) ;
					seats.add(seat) ;
				}
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}finally{
			try {
				rs.close();
				dbHelp.close() ;
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return seats ;
	}
	/**
	 * 查询数据集合返回类型Vector<Stirng>
	 * @param sql
	 * @param paras
	 * @return
	 */
	public Vector<String> queryStringVector(String sql,String[] paras){
		System.out.println(sql);
		System.out.println(paras);
		rs = dbHelp.query(sql,paras) ;
		Vector<String> vector = new Vector<String>() ;
		try {
			while(rs.next()){
				String s = rs.getString(1) ;
				vector.add(s) ;
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return vector ;
	}
	
	public String queryOneString(String sql,String[] paras){
		
		rs = dbHelp.query(sql, paras) ;
		
		try {
			if(rs.next()){
				return rs.getString(1) ;
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			try {
				rs.close() ;
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			dbHelp.close() ;
		}
		return null ;
	}
	
	public Vector<Vector<String>>  getState(String sql,String[] paras){
		
		//从DB 查
		
		Vector<Vector<String>>  rows=new Vector<Vector<String>>();
//		for(int i=1;i<=2;i++){
//		Vector<String>  row=new Vector<String>();
//		row.add(i+"-"+(i+1));
//		row.add(i+"-"+(i+2));
//		rows.add(row);
//		}
		rs=dbHelp.query(sql,paras);
//		//给行赋值
		try {
			while(rs.next()){
				Vector<String> row = new Vector<String>()  ;
				row.add(rs.getString(1)) ;
				row.add(rs.getString(2)) ;
				row.add(rs.getString(3)) ;
				row.add(rs.getString(4)) ;
				row.add(rs.getString(5)) ;
				rows.add(row) ;
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			try {
				rs.close() ;
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			dbHelp.close() ;
			
		}
//		try {
//			rows.set=rs.getString(1);
//		} catch (SQLException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
		return rows;
		
		
	} 
}
