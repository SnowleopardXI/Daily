package otcyan.java.view;

import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.util.Vector;

import javax.imageio.ImageIO;
import javax.swing.Box;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;

import otcyan.java.bean.Bank;
import otcyan.java.bean.FlightInfo;
import otcyan.java.bean.Seat;
import otcyan.java.bean.User;
import otcyan.java.model.DataHandle;
import otcyan.java.model.ReturnTicketModel;
import otcyan.java.tools.ImagePanel;
import otcyan.java.tools.Tookit;

public class ModifyTicketPanel extends JPanel implements ActionListener{
	


	private ImagePanel iPanel = null ;
	private CardLayout card = null ;
	private JButton queryButton, unButton ,backButton= null ;
	private JScrollPane jsp ;
	private DataHandle dataHandle ;
	private JTable jTable ;
	//private JButton resetButton  = null ;
	private User user  ;
	public ModifyTicketPanel(User user){
		dataHandle = new DataHandle() ;
		this.user = user ;
		this.init();
	}
	
	public JPanel onePanel(){
		JPanel jp = new JPanel(null) ;//空布局
		jp.setOpaque(false) ;
		
		JLabel jl1 = new JLabel("姓    名：",JLabel.RIGHT) ;
		jl1.setBounds(230, 217, 84, 18) ;
		jl1.setFont(Tookit.getFont1()) ;
		JTextField jtf1 = new JTextField(user.getU_name()) ;
		jtf1.setEditable(false) ;
		jtf1.setBounds(320, 217, 174, 22) ;
		
		JLabel jl2 = new JLabel("身份证号码：",JLabel.RIGHT) ;
		jl2.setBounds(230, 260, 84, 18) ;
		jl2.setFont(Tookit.getFont1()) ;
		JTextField jtf2 = new JTextField(user.getU_idcard()) ;
		jtf2.setEditable(false) ;
		jtf2.setBounds(320, 260, 174, 22) ;
		
		
		queryButton = new JButton("开始查询");
		queryButton.addActionListener(this) ;
		queryButton.setFont(Tookit.getFont1()) ;
		queryButton.setBounds(230,300,120,30) ;
		queryButton.setBackground(new Color(0xA9CAF3)) ;
//		resetButton = new JButton("返回") ;
//		resetButton.addActionListener(this) ;
//		resetButton.setBackground(new Color(0xA9CAF3)) ;
//		resetButton.setFont(Tookit.getFont1()) ;
//		resetButton.setBounds(380, 300, 120, 30) ;
		
		jp.add(jl1) ;
		jp.add(jtf1);
		jp.add(jl2) ;
		jp.add(jtf2);
		jp.add(queryButton) ;
//		jp.add(resetButton) ;
		
		return jp ;
	}
	private void init() {
		try {
			card = new CardLayout() ;
			iPanel = new ImagePanel(ImageIO.read(new File("image/returnticket.jpg")),new Dimension(1280,800)) ;
			iPanel.setLayout(card);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		iPanel.add(this.onePanel(),"one") ;
		iPanel.add(this.twoPanel(),"two") ;
		
	}
	public JPanel getJPanel() {
		
		return iPanel;
	}
	
	public JPanel twoPanel(){	
		
		JPanel jp = new JPanel(new BorderLayout());
		jp.setOpaque(false) ;
		//北边
		JPanel north = new JPanel() ;
		north.setOpaque(false) ;
		north.setPreferredSize(new Dimension(Tookit.getScreen().width,94)) ;
		jp.add(north,BorderLayout.NORTH) ;
		
		
		//中间
		JPanel center = new JPanel(new BorderLayout());
		center.setOpaque(false) ;
		JLabel jlName = new JLabel("用户："+user.getU_name()+"的订票信息",JLabel.CENTER);
		jlName.setFont(Tookit.getFont5()) ;
		jlName.setBackground(Color.red) ;
		center.add(jlName,BorderLayout.NORTH) ;
		
		 jsp = new JScrollPane() ;
		//jScrollPane设置透明
		jsp.setOpaque(false) ;
		jsp.getViewport().setOpaque(false) ;
		center.add(jsp) ;
		jp.add(center) ;
		
		JPanel jpBottom = new JPanel() ;
		jpBottom.setOpaque(false) ;
		 unButton = new JButton("改  签");
		unButton.addActionListener(this) ;
		unButton.setFont(Tookit.getFont1()) ;
		unButton.setBackground(new Color(0xA9CAF3)) ;
		 backButton = new JButton("返   回") ;
		backButton.addActionListener(this) ;
		backButton.setBackground(new Color(0xA9CAF3)) ;
		backButton.setFont(Tookit.getFont1()) ;
		jpBottom.add(unButton) ;
		jpBottom.add(backButton) ;
		jp.add(jpBottom,BorderLayout.SOUTH) ;
		
		return jp ;
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		
		if(e.getActionCommand().equals("开始查询")){
			this.query() ;
		}
		if(e.getSource()==backButton){
			card.show(iPanel, "one") ;
		}
		
		if(e.getSource()==unButton){
			//点击退订
			//得到 选中的行
			int selectedRow = jTable.getSelectedRow() ;
			if(selectedRow==-1){
				JOptionPane.showMessageDialog(null, "请选 中一行进行改签") ;
				return ;
			}
		
			String ticketId = (String)jTable.getValueAt(selectedRow, 0) ;
			JOptionPane.showMessageDialog(null, ticketId) ;
			
			//跳出一个改签的对话框
			String modifyDate = JOptionPane.showInputDialog(null, "请输入你要改签的日期：") ;
			String sql = "select t_seatId from tickets where t_date=? and t_f_number =? and t_type=?" ;
			//得到这个日期已卖座位号
			//System.out.println(jtf3_1.getText().trim()+selectFlightInfo.getF_number()+(String)boxType.getSelectedItem());
			Vector<String> seatIds = dataHandle.queryStringVector(sql, new String[]{modifyDate,(String)jTable.getValueAt(selectedRow, 1),(String)jTable.getValueAt(selectedRow, 4)}) ;
			//分配座位 
			//得到 选择舱位的总数 
			String seatTotalNumString = dataHandle.queryOneString("select s_number from seat where f_number=? and s_type=?", new String[]{(String)jTable.getValueAt(selectedRow, 1),(String)jTable.getValueAt(selectedRow, 4)}) ;
		     System.out.println("座位总数为："+seatTotalNumString);
		     int seatTotalNum = Integer.parseInt(seatTotalNumString) ;
		     //卖到 的座位号
		     int sellSeatNum = -1 ;
		     System.out.println("座位总数："+seatTotalNum+"已卖出："+seatIds);
		     
		     for (int i = 1; i <=seatTotalNum; i++) {
		    	 if(!seatIds.contains(i+"")){
		    		 sellSeatNum = i ;
		    		 break ;
		    	 }
			}
		     if(sellSeatNum==-1){
		    	 JOptionPane.showMessageDialog(null, "对不起！"+modifyDate+"票已经卖完") ;
		    	 return ;
		     }
		     
		     //更新  日期  跟座位号
		     boolean b = dataHandle.update("update tickets set t_seatId=?,t_date=? where t_id=?", new String[]{sellSeatNum+"",modifyDate,ticketId}) ;
			if(b){
				JOptionPane.showMessageDialog(null, "<html>修改成功！<br>座位号为： "+(String)jTable.getValueAt(selectedRow, 4)+"ZX "+sellSeatNum+"<br>日期： "+modifyDate+"</html>") ;
				this.query() ;//更新
			}else {
				JOptionPane.showMessageDialog(null, "改签失败！") ;
				return ;
			}
		}
	}

	public void query(){

		//产生一个jtable
		jTable = new JTable() ;
		jTable.setRowHeight(50) ;
		jTable.setBackground(new Color(0xA9CAF3)) ;
		//根据票的id查出航班的出发时间 
		unButton.setEnabled(true) ;
		Vector<String> flightIds= dataHandle.queryStringVector("select t_f_number from tickets where t_uid=?", new String[]{user.getU_id()}) ;
		if(flightIds.size()==0){
			//表示这个Id号没有票
			//表示没有直达的飞机
			JLabel jLabel = new JLabel("对不起！！您还没有订任何票",JLabel.CENTER) ;
			jLabel.setFont(Tookit.getFont5()) ;
			jLabel.setFont(Tookit.getFont2()) ;
			jsp.setViewportView(jLabel) ;
			//预订按钮不可见
			unButton.setEnabled(false) ;
			card.show(iPanel, "two") ;
			return ;
		}
		//这里可以 改为FlihtInfo信息-----------------------------
		Vector<String> startTimes = new Vector<String>() ;
		for(String flightId:flightIds){
			String startTime = dataHandle.queryOneString("select f_start_time from flight_info where f_number=?", new String[]{flightId}) ;
			startTimes.add(startTime) ;
		}
		ReturnTicketModel returnTicketModel = new ReturnTicketModel("select * from tickets where t_uid=?",new String[]{user.getU_id()},user,startTimes) ;
		jTable.setModel(returnTicketModel) ;
		jsp.setViewportView(jTable) ;
		card.show(iPanel, "two") ;
	
	}


}
