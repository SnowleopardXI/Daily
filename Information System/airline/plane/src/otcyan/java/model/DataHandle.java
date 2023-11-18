package otcyan.java.model;

import java.util.Vector;

import otcyan.java.bean.Bank;
import otcyan.java.bean.FlightAddr;
import otcyan.java.bean.FlightInfo;
import otcyan.java.bean.Seat;
import otcyan.java.bean.User;
import otcyan.java.dao.DbHandle;

public class DataHandle {
	
	DbHandle dbHandle = null ;
	
	public DataHandle(){
		dbHandle = new DbHandle() ;
	}
	
	/**
	 * 查询一个机场地点queryOneFlightAddr
	 */
	public FlightAddr queryOneFlightAddr(String sql,String[] paras){
		System.out.println("ssss:"+paras[0]);
		return dbHandle.queryOneFlightAddr(sql, paras) ;
	}
	
	/**
	 * 通过航班id查询飞机信息
	 */
	public FlightInfo queryFlightById(String sql,String[] paras ,FlightAddr startAddr,FlightAddr endAddr){
		
		return dbHandle.queryFlightById(sql, paras, startAddr, endAddr) ;
	}
	
	/**
	 * 通过id查询座位
	 */
	public Vector<Seat> querySeatById(String sql, String[] paras,FlightInfo fInfo , FlightAddr fAddr){
		
		return dbHandle.querySeatById(sql, paras, fInfo, fAddr) ;
	}
	

	public boolean update(String sql , String[] paras){

		return dbHandle.update(sql, paras) ;
	}
	/**
	 * 返回boolean值 验证成功返回boolean
	 * 
	 * sql 这是查询语句  paras是查询条件  items是登录判定条件
	 * @return
	 */
	public User getUser(String sql,String[] paras){
		return (User) dbHandle.loginQuery(sql, paras) ;
	}
	/**
	 * 查询所有 航班 的所属公司 
	 *
	 */
	public Vector<String> queryAllInfo(String sql,String[]paras){
		Vector<String> vv = new Vector<String>() ;
		vv.add("-------请选择-------") ;
		//去掉重复的
		Vector<String> v = this.queryStringVector(sql, paras) ;
		//去除重名的情况 
		for(String s : v ){
			if(!vv.contains(s)){
				//没有这个 公司
				vv.add(s) ;
			}
		}
		return vv ;
	}
	/**
	 * 查出所有 的航班地点 的id号
	 * @param sql
	 * @param paras
	 * @return
	 */
	public Vector<FlightAddr> quertyMulInfo(String sql,String[] paras){
		return dbHandle.queryMulInfo(sql, paras) ;
	}
	public Bank queryOneBank(String sql , String[] paras ,User user){
		
		return dbHandle.queryOneBank(sql, paras, user) ;
	}
	/**
	 * 
	 * @param startCityIds 所有 出发城市的FlightAddr
	 * @param endCityIds 所有 到达城市的FlightAddr
	 * @param str  这是某个时间 段的二个时间
	 * @return
	 */
	public Vector<FlightInfo> queryMulFlightInfo(Vector<FlightAddr> startCityIds , Vector<FlightAddr> endCityIds,String[] str){
		
		//如果 有 起点到 目的地的机场跟地点 。。那么 就加入到vector里
		Vector<FlightInfo> vector = new Vector<FlightInfo>() ;
		String sql = (str.length==1?"select * from flight_info where f_start=? and f_end=?":"select * from flight_info where f_start=? and f_end=? and f_start_time>=? and f_start_time<=?") ;
		//起始地点
		for (FlightAddr startCityId : startCityIds) {
			for (FlightAddr endCityId : endCityIds) {
				//从数据库中查找
				FlightInfo fInfo = dbHandle.queryFlightInfo(sql, startCityId, endCityId,str) ;
				if(fInfo!=null){
					//表示 有这个航班
					vector.add(fInfo) ;
				}
			}
		}
		
		return vector ;
	}
	
	public Vector<Seat> querySeatsInfo(String sql,String[] paras,FlightInfo fInfo){
		
		Vector<Seat> seats = dbHandle.querySeat(sql, paras,fInfo) ;
		return seats ;
	}
	
	public Vector<String> queryStringVector(String sql , String[] paras ){
		
		return dbHandle.queryStringVector(sql, paras) ;
	}
	
	public String queryOneString(String sql,String[] paras){
		return dbHandle.queryOneString(sql, paras) ;
	}
	
	
}
