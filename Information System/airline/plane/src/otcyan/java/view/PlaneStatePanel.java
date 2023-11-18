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
import java.util.HashMap;
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
import otcyan.java.dao.DbHandle;
import otcyan.java.model.DataHandle;
import otcyan.java.model.FlightStateModel;
import otcyan.java.model.SearchTableModel;
import otcyan.java.tools.ImagePanel;
import otcyan.java.tools.Tookit;

public class PlaneStatePanel extends JPanel implements ActionListener{
	
	static HashMap<String, Bank> map= null ;//一个票Id是用什么 银行账号买的 
	private CardLayout card = null ;
	private Vector<Vector<String>> states =null;
	private FlightStateModel fModel=null;
	private JTextField jtf1,jtf2,jtf3;
	private JLabel jl1 ,jl2,jl3;
	private String currenTime ;
	private JButton queryButton,backButton,resetButton ;
	private JScrollPane jsp ;
	private JTable jTable;
	private DbHandle dbHandle;
	private  String[] paras= null;
	private Thread thread = null ;

	private ImagePanel iPanel = null ;
	public PlaneStatePanel(){
		card = new CardLayout() ;
		dbHandle = new DbHandle();
		this.init();
	}
	private void init() {
		try {
			iPanel = new ImagePanel(ImageIO.read(new File("image/planeinf.jpg")),new Dimension(1280,800)) ;
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

	public JPanel onePanel(){
		JPanel jPanel = new JPanel(new BorderLayout()) ;
		jPanel.setOpaque(false) ;
		//控制北边
		JPanel north = new JPanel() ;
		north.setPreferredSize(new Dimension(1028,145)) ;
		north.setBackground(new Color(0xA7C8F3));
		JLabel jlTitle = new JLabel("航班动态");
		jlTitle.setFont(new Font("黑体", Font.PLAIN, 50));
		jlTitle.setForeground(Color.white);
		north.add(jlTitle);
		jPanel.add(north,BorderLayout.NORTH) ;
		
		JPanel center = new JPanel(null) ;
		center.setOpaque(false) ;
		
		jl1= new JLabel("出发城市：");
		jl1.setBounds(200, 20, 74, 20) ;
		jl1.setFont(Tookit.getFont1()) ;
		jtf1= new JTextField(12) ;
		jtf1.setBounds(275, 20, 130, 20) ;
	    jl2 = new JLabel("到达城市：");
		jl2.setBounds(200, 70, 74, 20) ;
		jl2.setFont(Tookit.getFont1()) ;
	    jtf2 = new JTextField() ;
		jtf2.setBounds(275, 70, 130, 20) ;
		jl3 = new JLabel("出发日期：",JLabel.RIGHT);
		jl3.setFont(Tookit.getFont1()) ;
		jl3.setBounds(200, 120, 74, 20) ;
		jtf3 = new JTextField(currenTime) ;
		jtf3.setBounds(275, 120, 130, 20) ;
		
		
		
		queryButton = new JButton("开始查询");
		queryButton.addActionListener(this) ;
		queryButton.setFont(Tookit.getFont1()) ;
		queryButton.setBounds(180, 220, 120, 30) ;
		queryButton.setBackground(new Color(0xA9CAF3)) ;
		resetButton = new JButton("重新查询") ;
		resetButton.addActionListener(this) ;
		resetButton.setBackground(new Color(0xA9CAF3)) ;
		resetButton.setFont(Tookit.getFont1()) ;
		resetButton.setBounds(320, 220, 120, 30) ;
		
		center.add(jl1) ;
		center.add(jtf1) ;
		center.add(jl2) ;
		center.add(jtf2) ;
		center.add(jl3) ;
		center.add(jtf3) ;
		center.add(queryButton) ;
		center.add(resetButton) ;
		
		jPanel.add(center) ;
		//控制南边
		JPanel south = new JPanel() ;
		south.setPreferredSize(new Dimension(1028,200)) ;
		south.setOpaque(false) ;
		jPanel.add(south,BorderLayout.SOUTH) ;
		
		return jPanel ;
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
		JLabel jlName = new JLabel("航班状态信息",JLabel.CENTER);
		jlName.setFont(Tookit.getFont5()) ;
		jlName.setForeground(Color.yellow);
		center.add(jlName,BorderLayout.NORTH) ;
		//创建JTable
		
		
//		new Thread(){
//			public void run() {
//				//负责model更新
//				
//				try {
//					Thread.sleep(1000);
//				} catch (InterruptedException e) {
//					// TODO Auto-generated catch block
//					e.printStackTrace();
//				}
//			};
//		}.start();
		
		jsp = new JScrollPane() ;
		//jScrollPane设置透明
		jsp.setOpaque(false) ;
		jsp.getViewport().setOpaque(false) ;
		center.add(jsp) ;
		jp.add(center) ;
		
		JPanel jpBottom = new JPanel() ;
		jpBottom.setOpaque(false) ;
//		unButton = new JButton("退  订");
//		unButton.addActionListener(this) ;
//		unButton.setFont(Tookit.getFont1()) ;
//		unButton.setBackground(new Color(0xA9CAF3)) ;
		backButton = new JButton("返   回") ;
		backButton.addActionListener(this) ;
		backButton.setBackground(new Color(0xA9CAF3)) ;
		backButton.setFont(Tookit.getFont1()) ;
//		jpBottom.add(unButton) ;
		jpBottom.add(backButton) ;
		jp.add(jpBottom,BorderLayout.SOUTH) ;
		return jp ;
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		// 第一张面板中的查询
		if(e.getSource()==queryButton){
			String startCity = jtf1.getText();
			String endCity = jtf2.getText();
			String stateDate = jtf3.getText();
			StringBuffer sb = new StringBuffer();
			int index =sb.length() ;
			sb.delete(0,index);
			sb.append("select fi.F_number, fa.a_city,fa1.a_city,s.fs_date,s.fs_state ");
			sb.append("from  flight_info fi,flight_addr  fa, flight_addr  fa1,state s ");
			sb.append("where s.fs_number=fi.f_number  and  fa.a_id= fi.f_start and fa1.a_id=fi.f_end ");
			//如果用户什么都没有填就显示所有的动态信息
			if(jtf1.getText().trim().equals("")||jtf2.getText().trim().equals("")||jtf3.getText().trim().equals("")){
				sb.append("and 1=?");
				paras=new String[]{"1"};
			}else{
				//条件查询
				sb.append("and fa.a_city=? and fa1.a_city=? and s.fs_date=?");
				paras = new String[]{startCity,endCity,stateDate};
				
				
//				for(Vector<String> v: states){
//					System.out.println(v);
//				}
				
//				if(states.size()==0){
//					JLabel jLabel = new JLabel("当前航班没有任何动态",JLabel.CENTER) ;
//					jLabel.setFont(Tookit.getFont5()) ;
//					jLabel.setFont(Tookit.getFont2()) ;
//					jsp.setViewportView(jLabel) ;
//					//设置不可见
////					queryButton.setEnabled(false);
//				}
			}
			final String sql = String.valueOf(sb);
			thread =new Thread(new Runnable() {
				
				@Override
				public void run() {
					// TODO Auto-generated method stub
					while(true){
						states = new DbHandle().getState(sql,paras) ;
						fModel = new FlightStateModel(states) ;
						jTable = new JTable() ;
						jTable.setModel(fModel) ;//......
						jTable.setRowHeight(60) ;
						jTable.setBackground(new Color(0xA9CAF3)) ;
						//怎样拿到数据放到表格中
						jsp.setViewportView(jTable) ;
						//重绘
//						jsp.validate() ;
//						jsp.repaint() ;
						try {
							Thread.sleep(1000) ;
						} catch (InterruptedException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
						//移除组件
					}
				}
			}) ;
			thread.start() ;
//			new Thread(){
//				public void run() {
//					//负责model更新
//					//拿到 Vector<Vector<String>> states 
//					while(true){
//						states = new DbHandle().getState(sql,paras) ;
//						fModel = new FlightStateModel(states) ;
//						jTable = new JTable() ;
//						jTable.setModel(fModel) ;//......
//						jTable.setRowHeight(60) ;
//						jTable.setBackground(new Color(0xA9CAF3)) ;
//						//怎样拿到数据放到表格中
//						jsp.setViewportView(jTable) ;
//						//重绘
////						jsp.validate() ;f
////						jsp.repaint() ;
//						try {
//							Thread.sleep(1000) ;
//						} catch (InterruptedException e) {
//							// TODO Auto-generated catch block
//							e.printStackTrace();
//						}
//						//移除组件
//					}
//				};
//			}.start();
			card.show(iPanel, "two") ;
			
		}
		//第一张面板中的重置
		if(e.getSource()==resetButton){
			jtf1.setText("");
			jtf2.setText("");
			jtf3.setText("");
		}
		//第二张面板中的返回
		if(e.getSource()==backButton){
			this.clear();
			thread.stop() ;
			card.show(iPanel, "one");
		}
	}
	public void clear(){
		jtf1.setText("");
		jtf2.setText("");
		jtf3.setText("");
	}
	


}
