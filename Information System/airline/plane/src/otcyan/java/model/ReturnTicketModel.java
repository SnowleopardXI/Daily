package otcyan.java.model;

import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.util.Vector;

import javax.swing.table.AbstractTableModel;

import otcyan.java.bean.User;
import otcyan.java.tools.DBHelp;

public class ReturnTicketModel extends AbstractTableModel{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	//列的项
	private Vector<String> col  ;
	//行的项
	private Vector<Vector> rows ; 
	private DBHelp dbHelp = null ;
	
	ResultSetMetaData rsmd;
	
	public void initCol(){
		col=new Vector<String>();
		col.add("票号") ;
		col.add("航班号") ;
		col.add("姓名") ;
		col.add("座位号") ;
		col.add("舱位") ;
		col.add("出发日期") ;
		col.add("出发时间") ;
	}
	
	public ReturnTicketModel(String sql , String paras[] , User user , Vector<String> startTimes){
	
		int count = 0 ;
		//初始化列
		this.initCol() ;
		rows = new Vector<Vector>() ;
		dbHelp =new DBHelp();
		ResultSet rs=dbHelp.query(sql, paras);
		//把查询结果放入到列表中
	
		try {
			 rsmd=rs.getMetaData();
//			for (int i = 0; i < rsmd.getColumnCount(); i++) {
//				this.col.add(rsmd.getColumnName(i+1));
//			}
				while(rs.next())
				{
					Vector<String> temp=new Vector<String>();
					for (int i = 0; i < rsmd.getColumnCount(); i++)
					{
						if(i==2){
							temp.add(user.getU_name()) ;
							continue ;
						}
						temp.add(rs.getString(i+1));
					}	
					temp.add(startTimes.get(count++)) ;
					rows.add(temp);
				}
			} catch (Exception e) {
				e.printStackTrace();
			}
			finally
			{
				if(rs!=null){
					try {
						rs.close() ;
					} catch (SQLException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
				dbHelp.close() ;
			}			
	
	}

//	//进行增删改
//	public boolean upd(String sql,String paras[])
//	{
//
//		return db.updExcute(sql, paras);
//		
//	}
	
	public int getColumnCount() {
		// TODO Auto-generated method stub
	//	System.out.println(this.col.size());
		return this.col.size();
	}

	public int getRowCount() {
		// TODO Auto-generated method stub
		//System.out.println(this.rows.size());
		return this.rows.size();
		
	}

	public Object getValueAt(int raw, int col) {
		// TODO Auto-generated method stub
		return ((Vector)this.rows.get(raw)).get(col);
	}

	@Override
	public String getColumnName(int arg0) {
		// TODO Auto-generated method stub
		return (String)this.col.get(arg0);
	}


}
