package otcyan.java.model;

import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.util.Vector;

import javax.swing.table.AbstractTableModel;

import otcyan.java.dao.DbHandle;
import otcyan.java.tools.DBHelp;

public class FlightStateModel extends AbstractTableModel{

	//每一列
	String[] col = {"<html><font size=5>航班号</font></html>",
			"<html><font size=5>起始城市</font></html>",
			"<html><font size=5>到达城市</font></html>",
			"<html><font size=5>动态日期</font></html>",
			"<html><font size=5>航班动态</font></html>"} ;
	//每一行
	Vector<Vector<String>> rows = null ;
	//ResultSet rs = null ;
	//DBHelp dbHelp = null ;
	//ResultSetMetaData rsData = null ;
	
	
	public  FlightStateModel(Vector<Vector<String>> rows){
		this.rows=rows;
	}
//	public FlightStateModel(String sql , String[] paras){
//		dbHelp = new DBHelp() ;
//		col = new Vector<String>() ;
//		rows = new Vector<Vector<String>>() ;
//		this.initDate(sql, paras) ;
//	}
//	
//	public void initDate(String sql,String[] paras){
//		
//		//赋值
//		rs = dbHelp.query(sql, paras) ;
//		//列赋值
//		try {
//			rsData = rs.getMetaData() ;
//			for (int i = 0; i < rsData.getColumnCount(); i++) {
//				col.add(rsData.getColumnName(i+1)) ;
//			}
//			
//			//给行赋值
//			while(rs.next()){
//				Vector<String> row = new Vector<String>()  ;
//				row.add(rs.getString(1)) ;
//				row.add(rs.getString(2)) ;
//				row.add(rs.getString(3)) ;
//				rows.add(row) ;
//			} 
//		} catch (SQLException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}finally{
//			dbHelp.close() ;
//		}
//		
//	}
	@Override
	public int getColumnCount() {
		// TODO Auto-generated method stub
		return col.length;
	}

	@Override
	public int getRowCount() {
		// TODO Auto-generated method stub
		return rows.size();
	}

	@Override
	public Object getValueAt(int rowIndex, int columnIndex) {
		// TODO Auto-generated method stub
		return ((Vector)rows.get(rowIndex)).get(columnIndex);
	}

	@Override
	public String getColumnName(int column) {
		// TODO Auto-generated method stub
		return col[column];
	}
	
	

	
}
