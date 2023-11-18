package otcyan.java.model;

import java.awt.Dimension;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.util.Set;
import java.util.Vector;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.table.AbstractTableModel;


import otcyan.java.bean.FlightInfo;
import otcyan.java.bean.Seat;
import otcyan.java.tools.DBHelp;
import otcyan.java.tools.Tookit;
/**
 * 查询出所有 的 航班信息 表，放到table表中
 * @author Administrator
 *
 */
public class SearchTableModel extends AbstractTableModel{

	//列的项
	private Vector<String> col  ;
	//行的项
	private Vector<Vector> rows ; 
	private DataHandle dataHandle = null ;
	private String[] types={"经济舱","商务舱","头等舱"};
	private int count = 0 ;
	
	public SearchTableModel(Vector<Vector<Seat>> seats,String startDate){
		dataHandle = new DataHandle() ;
		col = new Vector<String>() ;
		rows = new Vector<Vector>() ;
		this.initData(seats,startDate) ;
	}
	
	@SuppressWarnings("unchecked")
	public void initData(Vector<Vector<Seat>> seats,String startDate){
		
		//得到 总共有多少列的数据
		//为列赋值
		col.add("航班号") ;
		col.add("航班机型") ;
		col.add("出发地") ;
		col.add("目的地") ;
		col.add("始发机场") ;
		col.add("到达机场") ;
		col.add("出发时间 ") ;
		col.add("达到时间") ;
		col.add("经济舱") ;
		col.add("商务舱") ;
		col.add("头等舱") ;
		col.add("航空公司") ;
		col.add("购票") ;
			
		//为每行赋值
		for(Vector<Seat> v: seats) {
			System.out.println(v.size());
			 FlightInfo fInfo = v.get(1).getfInfo() ;
			 Vector row = new Vector() ;
			 row.add(fInfo.getF_number()) ;
			 row.add(fInfo.getF_type())  ;
			 row.add(fInfo.getF_start().getA_city()) ;
			 row.add(fInfo.getF_end().getA_city()) ;
			 row.add(fInfo.getF_start().getA_air()) ;
			 row.add(fInfo.getF_end().getA_air()) ;
			 row.add(fInfo.getF_start_time()) ;
			 row.add(fInfo.getF_end_time()) ;
			 //舱位数量
			 
			 for(Seat seat:v){
				 System.out.println(seat);
				// row.add(seat.getS_number()) ;//每一行的是 经济舱,商务舱，头等舱的座位数量
				 String type = types[count++] ;
				 System.out.println(type);
				 String paras[] = {startDate,fInfo.getF_number(),type}; //
				 //查询出所有 的座位号Id
				 Vector<String> seatIds = dataHandle.queryStringVector("select t_seatId from tickets where t_date=? and t_f_number =? and t_type=?", paras) ;
				 
				 if(seat.getS_number().matches("\\d+")){
					 System.out.println("===========");
					 //表示有此座位 不是  --
					 row.add(Integer.parseInt(seat.getS_number())-seatIds.size()+"") ;
				 }else{
					 row.add(seat.getS_number()) ;
				 }
				 
			 }
			 count=0 ;//count清零
			 row.add(fInfo.getF_company()) ;
			 row.add("预订") ;
			 rows.add(row) ;
		}
		
	}
	
	@Override
	public int getColumnCount() {
		return col.size();
	}

	@Override
	public int getRowCount() {
		return rows.size();
	}

	@Override
	public Object getValueAt(int rowIndex, int columnIndex) {
		// TODO Auto-generated method stub
		return ((Vector)rows.get(rowIndex)).get(columnIndex);
	}

	@Override
	public String getColumnName(int column) {
		//String[] name = {"航班号","机型","出发时间","达到时间","始发机场","目的地","航空公司"};
		return col.get(column) ;
	}

}
