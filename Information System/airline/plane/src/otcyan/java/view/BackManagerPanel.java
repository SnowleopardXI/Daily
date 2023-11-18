package otcyan.java.view;

import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.File;
import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Vector;

import javax.imageio.ImageIO;
import javax.swing.Box;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;


import otcyan.java.bean.FlightAddr;
import otcyan.java.bean.FlightInfo;
import otcyan.java.bean.Seat;
import otcyan.java.dao.DbHandle;
import otcyan.java.model.CheckInfo;
import otcyan.java.model.DataHandle;
import otcyan.java.model.FlightStateModel;
import otcyan.java.tools.DBHelp;
import otcyan.java.tools.ImagePanel;
import otcyan.java.tools.Tookit;

public class BackManagerPanel extends JPanel implements MouseListener,ActionListener{
	
	private JLabel jl1 ,jl2,jl3,jl4;
	private CardLayout card ;
	private ImagePanel ip;
	private JButton jbReset ,jbConfirm ;//createFlight()
	private JCheckBox boxType1,boxType2,boxType3;
	private JComboBox boxStartAir,boxEndAir,boxCompany ;
	private JTextField txtCancelNum ;
	private JButton jbCancel,jbConfirm2;//cancelFlight()
	private JButton jbConfirm3;//modifyFlight()
	private JComboBox boxModiStartAir ,boxModiEndAir, boxModiCompany ;
	private JCheckBox boxModiType1,boxModiType2,boxModiType3;
	private JLabel jlReturn3,jlReturn,jlUpReturn;//modify     createFlight()
	private JButton jbUpCreate ,jbUpDelete;  //updateState()   ,jbUpDelete,jbUpModify
	private JTextField txtModiType,txtModiStartTime,txtModiEndTime,txtModiNum2,txtModiNum1,txtModiPrice1,txtModiPrice2,txtModiNum3, txtModiPrice3;
	private JComboBox cbModiNum;
	private JTable jTable ;
	private JScrollPane jsp ;
	private FlightStateModel fModel;
	private Vector<Vector<String>> states = null ; 
	//数量
	private JTextField txtNum1,txtNum2,txtNum3,txtNum,txtType,txtStartTime,txtEndTime;
	private JTextField txtPrice1,txtPrice2,txtPrice3;
//	private String num1="",num2="",num3="" ;
//	private String price1=null,price2=null,price3=null ;
	String num1,num2,num3,price1,price2,price3 ;
	Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize();
	DataHandle dataHandle = null ;
	FlightInfo flightInfo= null;
	public BackManagerPanel(){
		UIManager.put("Label.font", Tookit.getFont1()) ;
		UIManager.put("Button.font", Tookit.getFont1()) ;
		UIManager.put("ComboBox.font", Tookit.getFont1()) ;
		UIManager.put("CheckBox.font", Tookit.getFont1()) ;
		dataHandle = new DataHandle() ;
		card = new CardLayout() ;
		this.init();
	}
	/**
	 * 第一个主面板
	 * @return
	 */
	public JPanel onePanel(){
		JPanel jPanel = new JPanel(new BorderLayout()) ;
		//jPanel.setBackground(Color.red);
		jPanel.setPreferredSize(new Dimension(355, 255)) ;
		JLabel jLabel = new JLabel("飞机订票系统后台管理");
		jLabel.setForeground(Color.yellow) ;
		jLabel.setFont(new Font("微软雅黑", Font.BOLD, 32)) ;
		jPanel.add(jLabel,BorderLayout.NORTH) ;
		
		JPanel center = new JPanel(new GridLayout(4,1,20,60)) ;
		center.setOpaque(false) ;
		//center.setBackground(Color.red) ;
		center.setPreferredSize(new Dimension(315,155)) ;
		jl1= new JLabel("创建航班") ;
		jl1.setFont(Tookit.getFont6()) ;
		jl1.setEnabled(false) ;
		jl1.addMouseListener(this) ;
		center.add(Box.createRigidArea(new Dimension(120, 200))) ;
		center.add(jl1) ;
		jl2 = new JLabel("取消航班") ;
		jl2.setFont(Tookit.getFont6()) ;
		jl2.addMouseListener(this);
		jl2.setEnabled(false);
		center.add(Box.createRigidArea(new Dimension(120, 200))) ;
		center.add(jl2) ;
		jl3 = new JLabel("航班修改") ;
		jl3.setFont(Tookit.getFont6()) ;
		jl3.addMouseListener(this);
		jl3.setEnabled(false) ;
		center.add(Box.createRigidArea(new Dimension(120, 200))) ;
		center.add(jl3) ;
		jl4 = new JLabel("航班动态管理") ;
		jl4.setFont(Tookit.getFont6()) ;
		jl4.addMouseListener(this);
		jl4.setEnabled(false);
		center.add(Box.createRigidArea(new Dimension(120, 200))) ;
		center.add(jl4) ;
		
		center.setOpaque(false) ;
		jPanel.add(center) ;
		jPanel.setOpaque(false) ;
		//创建 一个空面板
		JPanel blank = new JPanel() ;
		blank.setOpaque(false) ;
		blank.setPreferredSize(new Dimension(1000, 254)) ;
		jPanel.add(blank,BorderLayout.SOUTH) ;
		return jPanel ;
	}
	/**
	 * 创建 航班面板 
	 * @return
	 */
	public JPanel createFlight(){
		JPanel totalPanel = new JPanel() ;
		totalPanel.setOpaque(false) ;//设置透明
		
		JPanel jpAll=new JPanel();
		jpAll.setOpaque(false);//设置透明
		jpAll.setLayout(new BorderLayout());
		
		JPanel head=new JPanel();
		JLabel jlHead=new JLabel("创建航班");
		jlHead.setForeground(Color.yellow);
		jlHead.setFont(Tookit.getFont5());
		head.add(jlHead);
		head.setOpaque(false) ;//设置透明
		jpAll.add(head,BorderLayout.NORTH);
		
		JPanel jp = new JPanel(new GridLayout(14, 2, 7, 7)) ;
		jp.setOpaque(false) ;//设置透明
		JLabel jl1 = new JLabel("航班号：") ;
		jl1.setForeground(Color.yellow);
		jl1.setFont(Tookit.getFont4());
		jp.add(jl1) ;
		txtNum = new JTextField() ;
		jp.add(txtNum);
		JLabel jl2 = new JLabel("机型：") ;
		jl2.setForeground(Color.yellow);
		jl2.setFont(Tookit.getFont4());
		jp.add(jl2);
		txtType = new JTextField() ;
		jp.add(txtType);
		JLabel jl3 = new JLabel("出发时间:") ;
		jl3.setForeground(Color.yellow);
		jl3.setFont(Tookit.getFont4());
		jp.add(jl3);
		txtStartTime = new JTextField() ;
		jp.add(txtStartTime);
		JLabel jl4 = new JLabel("到达时间:") ;
		jl4.setForeground(Color.yellow);
		jl4.setFont(Tookit.getFont4());
		jp.add(jl4);
		txtEndTime = new JTextField() ;
		jp.add(txtEndTime);
		Vector<String> allAir = dataHandle.queryAllInfo("select a_air from flight_addr where 1 =?",new String[]{"1"}) ;
		JLabel jl5 = new JLabel("出发机场:") ;
		jl5.setForeground(Color.yellow);
		jl5.setFont(Tookit.getFont4());
		jp.add(jl5);
		boxStartAir = new JComboBox(allAir) ;//数据从数据库得到
		jp.add(boxStartAir);
		JLabel jl6 = new JLabel("到达机场:") ;
		jl6.setForeground(Color.yellow);
		jl6.setFont(Tookit.getFont4());
		jp.add(jl6);
		boxEndAir = new JComboBox(allAir) ;//数据从数据库得到
		jp.add(boxEndAir);
		JLabel jl7 = new JLabel("航空公司:") ;
		jl7.setForeground(Color.yellow);
		jl7.setFont(Tookit.getFont4());
		jp.add(jl7);
		//得到 所有 航空公司 从数据库中
		Vector<String> allCompany = dataHandle.queryAllInfo("select f_company from flight_info where 1=?",new String[]{"1"}) ;
		
		boxCompany = new JComboBox(allCompany) ;
		jp.add(boxCompany);
		JLabel jl8= new JLabel("舱位类型：") ;
		jl8.setForeground(Color.yellow);
		jl8.setFont(Tookit.getFont4());
		jp.add(jl8);
		JPanel jpType = new JPanel() ;
		jpType.setOpaque(false) ;
		jp.add(jpType);
		boxType1= new JCheckBox("头等舱") ;
		boxType1.setForeground(Color.yellow);
		boxType1.setOpaque(false);
		boxType1.setSelected(true) ;
		
		boxType2 = new JCheckBox("商务舱") ;
		boxType2.setForeground(Color.yellow);
	//	boxType2.addItemListener(this) ;
		boxType2.setOpaque(false);
		boxType2.setSelected(true) ;
		
		boxType3 = new JCheckBox("经济舱") ;
		boxType3.setForeground(Color.yellow);
		//boxType3.addItemListener(this) ;
		boxType3.setOpaque(false);
		boxType3.setSelected(true) ;
		
		jpType.add(boxType1) ;
		jpType.add(boxType2) ;
		jpType.add(boxType3) ;
		JLabel jl9 = new JLabel("头等舱数量：") ;
		jl9.setForeground(Color.yellow);
		jl9.setFont(Tookit.getFont4());
		jp.add(jl9);
		 txtNum1= new JTextField() ;
		jp.add(txtNum1);
		JLabel jl10 = new JLabel("头等舱价格：") ;
		jl10.setForeground(Color.yellow);
		jl10.setFont(Tookit.getFont4());
		jp.add(jl10);
		txtPrice1= new JTextField() ;
		jp.add(txtPrice1);
		JLabel jl11 = new JLabel("商务舱数量：") ;
		jl11.setForeground(Color.yellow);
		jl11.setFont(Tookit.getFont4());
		jp.add(jl11);
		 txtNum2 = new JTextField() ;
		jp.add(txtNum2);
		JLabel jl12 = new JLabel("商务舱价格：") ;
		jl12.setForeground(Color.yellow);
		jl12.setFont(Tookit.getFont4());
		jp.add(jl12);
		 txtPrice2 = new JTextField() ;
		jp.add(txtPrice2);
		JLabel jl13 = new JLabel("经济舱数量：") ;
		jl13.setForeground(Color.yellow);
		jl13.setFont(Tookit.getFont4());
		jp.add(jl13);
		 txtNum3 = new JTextField() ;
		jp.add(txtNum3);
		JLabel jl14 = new JLabel("经济舱价格：") ;
		jl14.setForeground(Color.yellow);
		jl14.setFont(Tookit.getFont4());
		jp.add(jl14);
		 txtPrice3 = new JTextField() ;
		jp.add(txtPrice3);
		boxType1.addItemListener(new ItemListener() {
			
			@Override
			public void itemStateChanged(ItemEvent e) {
				// TODO Auto-generated method stub
				BackManagerPanel.this.jCheckBoxOpera(boxType1, txtNum1, txtPrice1) ;

			}
		});
		boxType2.addItemListener(new ItemListener() {
					
					@Override
					public void itemStateChanged(ItemEvent e) {
						// TODO Auto-generated method stub
						BackManagerPanel.this.jCheckBoxOpera(boxType2, txtNum2, txtPrice2) ;
//						}
					}
				});
		boxType3.addItemListener(new ItemListener() {
			
			@Override
			public void itemStateChanged(ItemEvent e) {
				// TODO Auto-generated method stub
				BackManagerPanel.this.jCheckBoxOpera(boxType3, txtNum3, txtPrice3) ;

			}
		});
		jp.setPreferredSize(new Dimension(450, 555)) ;
		jl1.setHorizontalAlignment(JLabel.CENTER);
		jl2.setHorizontalAlignment(JLabel.CENTER);
		jl3.setHorizontalAlignment(JLabel.CENTER);
		jl3.setHorizontalAlignment(JLabel.CENTER);
		jl4.setHorizontalAlignment(JLabel.CENTER);
		jl5.setHorizontalAlignment(JLabel.CENTER);
		jl6.setHorizontalAlignment(JLabel.CENTER);
		jl7.setHorizontalAlignment(JLabel.CENTER);
		jl8.setHorizontalAlignment(JLabel.CENTER);
		jl9.setHorizontalAlignment(JLabel.CENTER);
		jl10.setHorizontalAlignment(JLabel.CENTER);
		jl11.setHorizontalAlignment(JLabel.CENTER);
		jl12.setHorizontalAlignment(JLabel.CENTER);
		jl13.setHorizontalAlignment(JLabel.CENTER);
		jl14.setHorizontalAlignment(JLabel.CENTER);
		
		 jbConfirm= new JButton("确    定");
		 jbConfirm.addActionListener(this);
		 jbReset = new JButton("重    置");
		 jbReset.addActionListener(this);
		 jlReturn = new JLabel("返回上级菜单");
		 jlReturn.setFont(Tookit.getFont4());
		 jlReturn.addMouseListener(this);
		
		JPanel jpButtom=new JPanel();
		jpButtom.setOpaque(false) ;
		jpButtom.add(jbConfirm);
		jpButtom.add(jbReset);
		jpButtom.add(jlReturn);
		jpAll.add(jpButtom,BorderLayout.SOUTH);
		
		jpAll.add(jp,BorderLayout.CENTER);
		//jpAll.setOpaque(false) ;
		totalPanel.add(jpAll) ;
		//实现上一级菜单的返回
		jlReturn.addMouseListener(this);
		return totalPanel ;
	}
	
	/**
	 * 取消航班
	 * @return
	 */
	public JPanel cancelFlight(){
		JPanel jpAll2=new JPanel();
		jpAll2.setLayout(null);
		jpAll2.setOpaque(false);
		//jpAll.setBackground(Color.yellow);
		
		//JPanel jpHead=new JPanel();
		JLabel jlHead2=new JLabel("取消航班");
		jlHead2.setBounds(400, 100, 150, 40);
		jlHead2.setForeground(Tookit.getColor());
		jlHead2.setFont(Tookit.getFont5());
		
		jbCancel=new JButton("取    消");
		jbConfirm2=new JButton("确    定");
		
		JLabel lbNum=new JLabel("航班号：");
		lbNum.setForeground(Color.yellow);
		lbNum.setFont(Tookit.getFont4());
		lbNum.setBounds(340, 250, 100, 30);
		txtCancelNum=new JTextField();//cancelFlight()
		txtCancelNum.setBounds(450, 250, 150, 30);
		
		jbConfirm2.setBounds(350, 400, 100, 30);
		jbCancel.setBounds(500, 400, 100,30);
		//jlReturn2.setBounds(600, 400, 100, 30);
		
		//jlReturn2.addMouseListener(this);
		
		jpAll2.add(jlHead2);
		jpAll2.add(lbNum);
		jpAll2.add(txtCancelNum);
		jpAll2.add(jbConfirm2);
		jpAll2.add(jbCancel);
		
		jbConfirm2.addActionListener(this);
		jbCancel.addActionListener(this);
		
		//jpAll2.add(jlReturn2);	
		return jpAll2; 
	}
	
	/**
	 *修改航班
	 */
	public JPanel modifyFlight(){
		JPanel modifyPanel = new JPanel() ;
		modifyPanel.setOpaque(false) ;//设置透明
		JPanel jpAll3=new JPanel();
		jpAll3.setOpaque(false);//设置透明
		jpAll3.setLayout(new BorderLayout());
		
		JPanel headPane=new JPanel();
		JLabel jlHead=new JLabel("修改航班");
		jlHead.setForeground(Color.yellow);
		jlHead.setFont(Tookit.getFont5());
		headPane.add(jlHead);
		//head.setPreferredSize(new Dimension(1000,200));
		headPane.setOpaque(false) ;//设置透明
		jpAll3.add(headPane,BorderLayout.NORTH);
		
		JPanel jPane = new JPanel(new GridLayout(14, 2, 7, 3)) ;
		jPane.setOpaque(false) ;//设置透明
		JLabel lbNum = new JLabel("航班号：") ;
		lbNum.setForeground(Color.yellow);
		lbNum.setFont(Tookit.getFont4());
		jPane.add(lbNum) ;
		Vector<String> allFlightNum=dataHandle.queryStringVector("select f_number from flight_info where 1=?", new String[]{"1"});
		cbModiNum = new JComboBox(allFlightNum);
		cbModiNum.addActionListener(this) ;
		cbModiNum.setActionCommand("fid") ;
		jPane.add(cbModiNum);
		JLabel lbType = new JLabel("机型：") ;
		lbType.setForeground(Color.yellow);
		lbType.setFont(Tookit.getFont4());
		jPane.add(lbType);
		txtModiType = new JTextField() ;
		jPane.add(txtModiType);
		JLabel lbStartTime = new JLabel("出发时间:") ;
		lbStartTime.setForeground(Color.yellow);
		lbStartTime.setFont(Tookit.getFont4());
		jPane.add(lbStartTime);
		txtModiStartTime = new JTextField() ;
		jPane.add(txtModiStartTime);
		JLabel lbEndTime = new JLabel("到达时间:") ;
		lbEndTime.setForeground(Color.yellow);
		lbEndTime.setFont(Tookit.getFont4());
		jPane.add(lbEndTime);
		txtModiEndTime = new JTextField() ;
		jPane.add(txtModiEndTime);
		Vector<String> allAir = dataHandle.queryAllInfo("select a_air from flight_addr where 1=?",new String[]{"1"}) ;
		JLabel lbStartAir = new JLabel("出发机场:") ;
		lbStartAir.setForeground(Color.yellow);
		lbStartAir.setFont(Tookit.getFont4());
		jPane.add(lbStartAir);
		boxModiStartAir= new JComboBox(allAir) ;//数据从数据库得到
		jPane.add(boxModiStartAir);
		JLabel lbEndAir = new JLabel("到达机场:") ;
		lbEndAir.setForeground(Color.yellow);
		lbEndAir.setFont(Tookit.getFont4());
		jPane.add(lbEndAir);
		boxModiEndAir= new JComboBox(allAir) ;//数据从数据库得到
		jPane.add(boxModiEndAir);
		JLabel lbCompany = new JLabel("航空公司:") ;
		lbCompany.setForeground(Color.yellow);
		lbCompany.setFont(Tookit.getFont4());
		jPane.add(lbCompany);
		//得到 所有 航空公司 从数据库中
		Vector<String> allCompany = dataHandle.queryAllInfo("select f_company from flight_info where 1=?",new String[]{"1"}) ;
		boxModiCompany = new JComboBox(allCompany) ;
		jPane.add(boxModiCompany);
		JLabel lbSeatType= new JLabel("舱位类型：") ;
		lbSeatType.setForeground(Color.yellow);
		lbSeatType.setFont(Tookit.getFont4());
		jPane.add(lbSeatType);
		JPanel jpType1 = new JPanel() ;
		jpType1.setOpaque(false) ;
		jPane.add(jpType1);
		boxModiType1= new JCheckBox("头等舱") ;
		boxModiType1.setForeground(Color.yellow);
		boxModiType1.setOpaque(false);
		boxModiType2 = new JCheckBox("商务舱") ;
		boxModiType2.setForeground(Color.yellow);
		boxModiType2.setOpaque(false);
		boxModiType3 = new JCheckBox("经济舱") ;
		boxModiType3.setForeground(Color.yellow);
		boxModiType3.setOpaque(false);
		jpType1.add(boxModiType1) ;
		jpType1.add(boxModiType2) ;
		jpType1.add(boxModiType3) ;
		JLabel lbModiNum1 = new JLabel("头等舱数量：") ;
		lbModiNum1.setForeground(Color.yellow);
		lbModiNum1.setFont(Tookit.getFont4());
		jPane.add(lbModiNum1);
		txtModiNum1 = new JTextField() ;
		jPane.add(txtModiNum1);
		JLabel lbModiPrice1 = new JLabel("头等舱价格：") ;
		lbModiPrice1.setForeground(Color.yellow);
		lbModiPrice1.setFont(Tookit.getFont4());
		jPane.add(lbModiPrice1);
		txtModiPrice1 = new JTextField() ;
		jPane.add(txtModiPrice1);
		JLabel lbModiNum2 = new JLabel("商务舱数量：") ;
		lbModiNum2.setForeground(Color.yellow);
		lbModiNum2.setFont(Tookit.getFont4());
		jPane.add(lbModiNum2);
		txtModiNum2 = new JTextField() ;
		jPane.add(txtModiNum2);
		JLabel lbModiPrice2 = new JLabel("商务舱价格：") ;
		lbModiPrice2.setForeground(Color.yellow);
		lbModiPrice2.setFont(Tookit.getFont4());
		jPane.add(lbModiPrice2);
		txtModiPrice2 = new JTextField() ;
		jPane.add(txtModiPrice2);
		JLabel lbModiNum3 = new JLabel("经济舱数量：") ;
		lbModiNum3.setForeground(Color.yellow);
		lbModiNum3.setFont(Tookit.getFont4());
		jPane.add(lbModiNum3);
		txtModiNum3 = new JTextField() ;
		jPane.add(txtModiNum3);
		JLabel lbModiPrice3 = new JLabel("经济舱价格：") ;
		lbModiPrice3.setForeground(Color.yellow);
		lbModiPrice3.setFont(Tookit.getFont4());
		jPane.add(lbModiPrice3);
		txtModiPrice3 = new JTextField() ;
		jPane.add(txtModiPrice3);
		jPane.setPreferredSize(new Dimension(450, 555)) ;
		
		boxModiType1.addItemListener(new ItemListener() {
			
			@Override
			public void itemStateChanged(ItemEvent e) {
				if(!boxModiType1.isSelected()){
					txtModiNum1.setText("--") ;
					txtModiNum1.setEditable(false) ;
					txtModiPrice1.setText(0+"") ;
					txtModiPrice1.setEditable(false) ;
				}else{
					txtModiNum1.setEditable(true) ;
					txtModiPrice1.setEditable(true) ;
				}
			}
		}) ;

		boxModiType2.addItemListener(new ItemListener() {
			
			@Override
			public void itemStateChanged(ItemEvent e) {
				if(!boxModiType2.isSelected()){
					txtModiNum2.setText("--");
					txtModiNum2.setEditable(false);
					txtModiPrice2.setText(0+"");
					txtModiPrice2.setEditable(false);
				}else{
					txtModiNum2.setEditable(true);
					txtModiPrice2.setEditable(true);
				}
			}
		}) ;

		boxModiType3.addItemListener(new ItemListener() {
			
			@Override
			public void itemStateChanged(ItemEvent e) {
				if(!boxModiType3.isSelected()){
					txtModiNum3.setText("--");
					txtModiNum3.setEditable(false);
					txtModiPrice3.setText(0+"");
					txtModiPrice3.setEditable(false);
				}else{
					txtModiNum3.setEditable(true);
					txtModiPrice3.setEditable(true);
				}
			}
		}) ;
		
		lbNum.setHorizontalAlignment(JLabel.CENTER);
		lbType.setHorizontalAlignment(JLabel.CENTER);
		lbStartTime.setHorizontalAlignment(JLabel.CENTER);
		lbEndTime.setHorizontalAlignment(JLabel.CENTER);
		lbStartAir.setHorizontalAlignment(JLabel.CENTER);
		lbEndAir.setHorizontalAlignment(JLabel.CENTER);
		lbCompany.setHorizontalAlignment(JLabel.CENTER);
		lbSeatType.setHorizontalAlignment(JLabel.CENTER);
		lbModiNum1.setHorizontalAlignment(JLabel.CENTER);
		lbModiPrice1.setHorizontalAlignment(JLabel.CENTER);
		lbModiNum2.setHorizontalAlignment(JLabel.CENTER);
		lbModiPrice2.setHorizontalAlignment(JLabel.CENTER);
		lbModiNum3.setHorizontalAlignment(JLabel.CENTER);
		lbModiPrice3.setHorizontalAlignment(JLabel.CENTER);
		
		cbModiNum.addMouseListener(this);
		jlReturn3=new JLabel("返回上级菜单");
		jlReturn3.setFont(Tookit.getFont4());
		jbConfirm3=new JButton("确定修改");
		jbConfirm3.addActionListener(this);
		
		JPanel jpButtom1=new JPanel();
		jpButtom1.setOpaque(false) ;
		jpButtom1.add(jbConfirm3);
//		jpButtom1.add(jbReset3);
		jpButtom1.add(jlReturn3);
		jpAll3.add(jpButtom1,BorderLayout.SOUTH);
		
		jpAll3.add(jPane,BorderLayout.CENTER);
		//jpAll.setOpaque(false) ;
		modifyPanel.add(jpAll3) ;
		//实现上一级菜单的返回
		jlReturn3.addMouseListener(this);
		return modifyPanel ;
	}
	/**
	 * 修改航班动态
	 * @return
	 */
	public JPanel updateState(){
		
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
		JLabel jlName = new JLabel("航班动态管理",JLabel.CENTER);
		jlName.setFont(Tookit.getFont5()) ;
		jlName.setForeground(Color.YELLOW) ;
		center.add(jlName,BorderLayout.NORTH) ;
		jsp = new JScrollPane() ;
		
		
		StringBuffer sb=new StringBuffer();
		sb.append("select fi.F_number, fa.a_city,fa1.a_city,s.fs_date,s.fs_state ");
		sb.append("from  flight_info fi,flight_addr  fa, flight_addr  fa1,state s ");
		sb.append("where s.fs_number=fi.f_number  and  fa.a_id= fi.f_start and fa1.a_id=fi.f_end and 1=?");
		final String sql = sb.toString() ;
		new Thread(){
			
			public void run() {
				
				while(true){
					
					states = new DbHandle().getState(sql,new String[]{"1"}) ;
					fModel = new FlightStateModel(states) ;
//					for(Vector<String> v: states){
//						System.out.println(v);
//					}
					jTable = new JTable() ;
					jTable.setModel(fModel) ;//......
					jTable.setRowHeight(60) ;
					jTable.setBackground(new Color(0xA9CAF3)) ;
					//怎样拿到数据放到表格中
					jsp.setViewportView(jTable) ;
					//重绘
//					jsp.validate() ;
//					jsp.repaint() ;
					try {
						Thread.sleep(2000) ;
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					//移除组件
				}
			};
		}.start() ;
		
		//jScrollPane设置透明
		jsp.setOpaque(false) ;
		jsp.getViewport().setOpaque(false) ;
		center.add(jsp) ;
		jp.add(center,BorderLayout.CENTER) ;
		
		//
		JPanel jpBottom = new JPanel() ;
		jpBottom.setOpaque(false) ;
		jbUpCreate= new JButton("创建航班动态");
		jbUpCreate.addActionListener(this) ;
		jbUpCreate.setFont(Tookit.getFont1()) ;
		jbUpCreate.setBackground(new Color(0xA9CAF3)) ;
		jbUpDelete = new JButton("删除航班动态") ;
		jbUpDelete.addActionListener(this) ;
		jbUpDelete.setBackground(new Color(0xA9CAF3)) ;
		jbUpDelete.setFont(Tookit.getFont1()) ;
//		jbUpModify=new JButton("修改动态");
//		jbUpModify.addActionListener(this);
//		jbUpModify.setFont(Tookit.getFont1());
//		jbUpModify.setBackground(new Color(0xA9CAF3));
		jlUpReturn=new JLabel("返回上级菜单");
		jlUpReturn.setFont(Tookit.getFont4());
		jlUpReturn.addMouseListener(this);
		jpBottom.add(jbUpCreate) ;
		jpBottom.add(jbUpDelete) ;
//		jpBottom.add(jbUpModify) ;
		jpBottom.add(jlUpReturn);
		jp.add(jpBottom,BorderLayout.SOUTH) ;
		
		return jp ;
	
		}

	private void init() {
		
		try {
			ip = new ImagePanel(ImageIO.read(new File("image/171go.jpg")), dimension) ;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}	
		ip.setLayout(card) ;
		ip.add(this.onePanel(),"one") ;
		//创建一个创建航班面板。加入到ip里
		ip.add(this.createFlight(),"create") ;
		//创建一个取消航班面板。。。。。。
		ip.add(this.cancelFlight(),"cancel");
		//创建一个修改航班面板
		ip.add(this.modifyFlight(),"modify");
		//创建一个修改航班动态面板
		ip.add(this.updateState(),"update") ;
		
		ip.setSize(1008,680) ;
		ip.setBackground(new Color(0x498DF8)) ;
	}

	@Override
	public void mouseClicked(MouseEvent e) {
		
		if(e.getSource() instanceof JLabel){
			//鼠标点击
			if(((JLabel)e.getSource())==jl1){
				//创建航班
				card.show(ip, "create") ;
			}
			if((JLabel)e.getSource()==jl2){
				card.show(ip, "cancel");
			}
			if((JLabel)e.getSource()==jl3){
				card.show(ip, "modify");
			}
			if((JLabel)e.getSource()==jl4){
				card.show(ip, "update");
			}
			//createFlight()
			if((JLabel)e.getSource()==jlReturn){
				card.show(ip, "one");
			}
			//modifyFlight()
			if((JLabel)e.getSource()==jlReturn3){
				card.show(ip, "one");
			}
			if((JLabel)e.getSource()==jlUpReturn){
				card.show(ip, "one");
			}
		}
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// 鼠标进入
		if(e.getSource() instanceof JLabel){
			if(((JLabel)e.getSource())==jl1){
				jl1.setForeground(Tookit.getColor()) ;
				jl1.setCursor(new Cursor(Cursor.HAND_CURSOR)) ;
				jl1.setEnabled(true);
			}
			if(((JLabel)e.getSource())==jl2){
				jl2.setForeground(Tookit.getColor()) ;
				jl2.setCursor(new Cursor(Cursor.HAND_CURSOR)) ;
				jl2.setEnabled(true);
			}
			if(((JLabel)e.getSource())==jl3){
				jl3.setForeground(Tookit.getColor()) ;
				jl3.setCursor(new Cursor(Cursor.HAND_CURSOR)) ;
				jl3.setEnabled(true);
			}
			if(((JLabel)e.getSource())==jl4){
				jl4.setForeground(Tookit.getColor()) ;
				jl4.setCursor(new Cursor(Cursor.HAND_CURSOR)) ;
				jl4.setEnabled(true);
			}
			//createFlight()里的返回上一级菜单的   标签
			if(((JLabel)e.getSource())==jlReturn){
				jlReturn.setForeground(Tookit.getColor()) ;
				jlReturn.setCursor(new Cursor(Cursor.HAND_CURSOR)) ;
				jlReturn.setEnabled(true);
			}
			//modifyFlight()里的返回上一级菜单的   标签
			if(((JLabel)e.getSource())==jlReturn3){
				jlReturn3.setForeground(Tookit.getColor()) ;
				jlReturn3.setCursor(new Cursor(Cursor.HAND_CURSOR)) ;
				jlReturn3.setEnabled(true);
			}
			//updateState()里的返回上一级菜单的   标签
			if(((JLabel)e.getSource())==jlUpReturn){
				jlUpReturn.setForeground(Tookit.getColor()) ;
				jlUpReturn.setCursor(new Cursor(Cursor.HAND_CURSOR)) ;
				jlUpReturn.setEnabled(true);
			}
		}
	}

	@Override
	public void mouseExited(MouseEvent e) {
		
		if(e.getSource() instanceof JLabel){
			if(((JLabel)e.getSource())==jl1){
				jl1.setEnabled(false);
			}
			if(((JLabel)e.getSource())==jl2){
				jl2.setEnabled(false);
			}
			if(((JLabel)e.getSource())==jl3){
				jl3.setEnabled(false);
			}
			if(((JLabel)e.getSource())==jl4){
				jl4.setEnabled(false);
			}
			//createFlight()里的'返回上一级'菜单的标签
			if(((JLabel)e.getSource())==jlReturn){
				jlReturn.setEnabled(false);
			}
			//modifyFlight()里的'返回上一级'菜单的标签
			if(((JLabel)e.getSource())==jlReturn3){
				jlReturn3.setEnabled(false);
			}
			//updateState()里的'返回上一级'菜单的标签
			if(((JLabel)e.getSource())==jlUpReturn){
				jlUpReturn.setEnabled(false);
			}
		}
		
		// 修改航班：输入航班号时触发事件
//		if(e.getSource() instanceof JTextField){
//			String fNumber=txtModiNum.getText().trim();
//			String fType=null;
//			String fStartTime=null;
//			String fEndTime=null;
//			FlightAddr fStart=null;
//			FlightAddr fEnd=null;
//			String fCompany=null;
//			//flightInfo=new FlightInfo();
//			//获得航班号
//			StringBuffer sql=new StringBuffer();
//			sql.append("select ");
//			sql.append("* ");
//			sql.append("from flight_info ");
//			sql.append("where f_number=?");
//			FlightInfo flightInfo=new FlightInfo(String fNumber, String fType, String fStartTime,
//					String fEndTime, FlightAddr fStart, FlightAddr fEnd, String fCompany);
//            flightInfo=dataHandle.queryFlightInfo(sql.toString(), new String[]{"sFlightNum"});
//            txtModiNum.setEditable(false);
//            System.out.println("the info is:"+flightInfo);//null
//            txtModiType.setText(flightInfor.get(1));
//			txtModiStartTime.setText(flightInfor.get(2));
//			txtModiEndTime.setText(flightInfor.get(3));
//            for(String s:flightInfor){
//            	System.out.println(s);
//            }
//			
//		}
	}

	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	public ImagePanel getIp() {
		return ip;
	}
	/**
	 * JCheckBox的操作
	 * @param jCheckBox
	 * @param txtNum
	 * @param txtPrice
	 */
	public void jCheckBoxOpera(JCheckBox jCheckBox,JTextField txtNum ,JTextField txtPrice){
		if(!jCheckBox.isSelected()){
			//头等舱数量 
			txtNum.setEditable(false) ;
			txtPrice.setEditable(false) ;
		}
		if(jCheckBox.isSelected()){
			//头等舱数量 
			txtNum.setEditable(true) ;
			txtPrice.setEditable(true) ;
		}
	}
	public boolean checkSeatInfo(String num,String price){
		
		if(num.matches("\\d+") && price.matches("\\d+|(\\d+\\.\\d\\d)")){
			return true;
		}
		return false ;
	}
	
	public void clear(){
		txtNum.setText("") ;
		txtType.setText("") ;
		txtStartTime.setText("") ;
		txtEndTime.setText("") ;
		boxStartAir.setSelectedIndex(0) ;
		boxEndAir.setSelectedIndex(0) ;
		boxCompany.setSelectedIndex(0) ;
		boxType1.setSelected(true) ;
		boxType2.setSelected(true) ;
		boxType3.setSelected(true) ;
		txtNum1.setText("");
		txtNum2.setText("");
		txtNum3.setText("");
		txtPrice1.setText("") ;
		txtPrice2.setText("") ;
		txtPrice3.setText("") ;
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		//createFlight()里的确定创建按钮
		if(e.getSource() == jbConfirm){
			
			//出发机场
			String flightNum = txtNum.getText().trim() ;
			String flightType = txtType.getText().trim() ;
			String startTime = txtStartTime.getText().trim() ;
			String endTime = txtEndTime.getText().trim() ;
			
			int startIndex = boxStartAir.getSelectedIndex() ;
			int endIndex = boxEndAir.getSelectedIndex() ;
			String startAir = (String)boxStartAir.getSelectedItem() ;
			String endAir = (String)boxEndAir.getSelectedItem() ;
			String company = (String)boxCompany.getSelectedItem() ;
			//首先检测 数据 格式 是否正确 
			if(flightNum.equals("")||flightType.equals("")||startTime.equals("")||endTime.equals("")||startIndex==0||endIndex==0){
				JOptionPane.showMessageDialog(null, "数据不能为空") ;
				return ;
			}
			//00:00 01  02 .....09
			//10  11.....19
			//20  24
			if(!startTime.matches("([0-1][0-9]|[2][0-4]):[0-5][0-9]")){
				JOptionPane.showMessageDialog(null, "出发时间格式不对") ;
				txtStartTime.setText("") ;
				return ;
			}
			if(!endTime.matches("([0-1][0-9]|[2][0-4]):[0-5][0-9]")){
				JOptionPane.showMessageDialog(null, "到达时间格式不对") ;
				txtEndTime.setText("") ;
				return ;
			}
			//时间输入是不是正确   可以不做 这个判断
//			if(startTime.compareTo(endTime)>=0){
//				JOptionPane.showMessageDialog(null, "出发时间跟到达时间不合理！") ;
//				txtEndTime.setText("") ;
//				txtStartTime.setText("") ;
//				return ;
//			}
			if(startAir.equals(endAir)){
				JOptionPane.showMessageDialog(null, "出发机场不能和到达相同!!") ;
				return ;
			}
			
			//对头等舱处理
			if(boxType1.isSelected()){
				num1 = txtNum1.getText().trim() ;//得到头等舱数量 
				price1 = txtPrice1.getText().trim() ;//得到 头等舱的价格
				//判断格式
				boolean b = BackManagerPanel.this.checkSeatInfo(num1, price1) ;
				if(b==false){
					JOptionPane.showMessageDialog(null, "头等舱数量或价格格式有误") ;
					txtNum1.setText("") ;
					txtPrice1.setText("") ;
					return ;
				}
			}else{
				num1 = "--" ;//没有数量 
				price1 = "0" ;//价钱 为0
				
			}
			//商务等舱处理
			if(boxType2.isSelected()){
				 num2 = txtNum2.getText().trim() ;//得到头等舱数量 
				 price2 = txtPrice2.getText().trim() ;//得到 头等舱的价格
				//判断格式
					boolean b = BackManagerPanel.this.checkSeatInfo(num2, price2) ;
					if(b==false){
						JOptionPane.showMessageDialog(null, "商务舱数量或价格格式有误") ;
						txtNum2.setText("") ;
						txtPrice2.setText("") ;
						return ;
					}
			}else {
				num2 = "--" ;//没有数量 
				price2= "0" ;//价钱 为0
			}
			//经济等舱处理
			if(boxType3.isSelected()){
				 num3 = txtNum3.getText().trim() ;//得到头等舱数量 
				 price3 = txtPrice3.getText().trim() ;//得到 头等舱的价格
				//判断格式
					boolean b = BackManagerPanel.this.checkSeatInfo(num3, price3) ;
					System.out.println(b);
					if(b==false){
						JOptionPane.showMessageDialog(null, "经济舱数量或价格格式有误") ;
						txtNum3.setText("") ;
						txtPrice3.setText("") ;
						return ;
					}
			}else {
				num3 = "--" ;//没有数量 
				price3= "0" ;//价钱 为0
			}
			if (num1.equals("") || num2.equals("") || num3.equals("")
					|| price1.equals("") || price2.equals("")
					|| price3.equals("")) {
					JOptionPane.showMessageDialog(BackManagerPanel.this, "数据不能为空!!!") ;
					return ;
			}
			
			//验证文件框 信息成功
			//验证 这个航班 Id号是不是已经存在
			CheckInfo cInfo = new CheckInfo() ;
			boolean b = cInfo.checkisExist("select * from flight_info where 1=? ", new String[]{"1"}, flightNum) ;
			if(b){
				JOptionPane.showMessageDialog(null, "航班号已经存在！重新输入") ;
				txtNum.setText("") ;
				return ;
			}
		
			//将信息插入到航班表 和 Seat表       ？？？？需要作事物处理    应该自动返回加入一个返回航班 
			String startAirId = dataHandle.queryOneString("select  a_id from flight_addr where a_air=?", new String[]{startAir}) ;
			String endAirId = dataHandle.queryOneString("select  a_id from flight_addr where a_air=?", new String[]{endAir}) ;
			System.out.println(startAir+"   "+endAirId);
			boolean b1  = dataHandle.update("insert into flight_info values(?,?,?,?,?,?,?)", new String[]{flightNum,flightType,startTime,endTime,startAirId,endAirId,company}) ;
			 //航班插入成功
			 boolean b2 = dataHandle.update("insert into seat values(?,?,?,"+Float.parseFloat(price3)+")", new String[]{flightNum,"经济舱",num3}) ;
			 boolean b3 = dataHandle.update("insert into seat values(?,?,?,"+Float.parseFloat(price2)+")", new String[]{flightNum,"商务舱",num2}) ;
			 boolean b4 = dataHandle.update("insert into seat values(?,?,?,"+Float.parseFloat(price1)+")", new String[]{flightNum,"头等舱",num1}) ;
			 if(b1&&b2&&b3&&b4){
				//进入第主页面
				int n = JOptionPane.showConfirmDialog(null, "航班插入成功！是否继续?") ;
				 if(n==JOptionPane.YES_OPTION){
					  card.show(ip, "create") ;
				 }else {
					card.show(ip, "one") ;
				}
				 BackManagerPanel.this.clear() ;
				 //插入成功！！
			 }else {
				JOptionPane.showMessageDialog(null, "航班插入失败") ;
			}	
		}
		
		//createFlight()里的重置按钮
		if(e.getSource()==jbReset){
			clear();
		}
		//点击取消就返回上一级cancelFlight()里 的取消按钮
		if(e.getSource()==jbCancel){
			card.show(ip, "one");
		}
		//点击确认就按照航班号先删除所在的座位数和航班信息表中的该条记录
		if(e.getSource()==jbConfirm2){
			String fNumber=txtCancelNum.getText().trim();
			//判断该航班号是否为空
			if(fNumber.equals("")){
				JOptionPane.showMessageDialog(null, "数据不能为空！");
				return;
			}
			//先判断该航班号是否存在
			Vector<String> fNums = dataHandle.queryStringVector("select f_number from flight_info where 1=? ", new String[]{"1"}) ;
			if(!fNums.contains(fNumber)){
				//表示不存在
				JOptionPane.showMessageDialog(null, fNumber+"航班号不存在！") ;
				txtCancelNum.setText("") ;
				return ;
			}
			Connection conn=null;
			Statement st=null;
			int b1=0,b2=0;
			try {
				
				DBHelp  dbHelp=new DBHelp();
				conn =dbHelp.getConnection();
				st =conn.createStatement();
				conn.setAutoCommit(false);
				String sql="delete from seat where f_number='"+fNumber+"'";
				b1=st.executeUpdate(sql);
				//String[] paras=new String[]{fNumber};	
			
				//DataHandle dataHandle=new DataHandle();
				//boolean b1=dataHandle.update(sql, paras);
			
				sql="delete from flight_info where f_number='"+fNumber+"'";
			
				b2 = st.executeUpdate(sql);
			} catch (SQLException e2) {
				try {
					conn.rollback();
					JOptionPane.showMessageDialog(null, "取消航班失败！");
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			//boolean b2=dataHandle.update(sql, paras);
			System.out.println(b1+" "+b2);
			if(b1>0 && b2>0){
				try {
					conn.commit();
					JOptionPane.showMessageDialog(null, "取消航班成功！");
					txtCancelNum.setText("") ;
					card.show(ip, "one") ;
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				
			}else{
				try {
					conn.rollback();
					JOptionPane.showMessageDialog(null, "取消航班失败！");
				} catch (SQLException e1) {
					JOptionPane.showMessageDialog(null, "取消航班失败！");
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			
			}
			
		}
		//点击  航班号  时所触发的事件，将该航班的所有信息赋值
		if(e.getActionCommand().equals("fid")){
			JOptionPane.showMessageDialog(null, cbModiNum.getSelectedItem()) ;
			//航班id号
			String selectFlightId = (String)cbModiNum.getSelectedItem() ;
			//根据Id查到 起始机场
			String startAirplane = dataHandle.queryOneString("select f_start from flight_info where f_number=?", new String[]{selectFlightId}) ; 
			String endAirplane = dataHandle.queryOneString("select f_end from flight_info where f_number=?", new String[]{selectFlightId}) ; 
			System.out.println("起始机场:"+startAirplane+"    end:"+endAirplane);
			
			//先得到  FlightAddr ----------->>>>?????????
			FlightAddr startAddr=dataHandle.queryOneFlightAddr("select * from flight_addr where a_id=?", new String[]{startAirplane});
			System.out.println("FlightAddr:"+startAddr);
			String startCity=startAddr.getA_city();
			FlightAddr endAddr=dataHandle.queryOneFlightAddr("select * from flight_addr where a_id=?", new String[]{endAirplane});
			String endCity=endAddr.getA_city();
			System.out.println("起始城市:"+startCity+"    end:"+endCity);
			
			//通过起始地址和目的地得到FlightInfo 
			String sql="select * from flight_info where f_number=?";
			FlightInfo fInfo=dataHandle.queryFlightById(sql, new String[]{selectFlightId}, startAddr, endAddr);
			if(fInfo==null){
				JOptionPane.showMessageDialog(null, "数据为空！");
				return ;
			}
			txtModiType.setText(fInfo.getF_type());
			txtModiStartTime.setText(fInfo.getF_start_time());
			txtModiEndTime.setText(fInfo.getF_end_time());
			boxModiStartAir.setSelectedItem(fInfo.getF_start().getA_air());
//			boxModiStartAir.setEditable(false);
			boxModiEndAir.setSelectedItem(fInfo.getF_end().getA_air());
//			boxModiEndAir.setEditable(false);
			boxModiCompany.setSelectedItem(fInfo.getF_company());
			//Seat
			sql="select * from seat where f_number=?";
			Vector<Seat> selectSeat=dataHandle.querySeatById(sql, new String[]{selectFlightId}, fInfo, startAddr);
			System.out.println("---座位信息----"+selectSeat.get(0)+"   "+selectSeat.get(1)+selectSeat.get(2));
			for(Seat s:selectSeat){
				if(s.getS_type().equals("头等舱")){		
					if(s.getS_number().matches("\\d+")){
						boxModiType1.setSelected(true);
					}
					txtModiNum1.setText(s.getS_number());
					txtModiPrice1.setText(s.getS_price()+"");
				}
				if(s.getS_type().equals("商务舱")){
					if(s.getS_number().matches("\\d+")){
						boxModiType2.setSelected(true);
					}
					txtModiNum2.setText(s.getS_number());
					txtModiPrice2.setText(s.getS_price()+"");
				}
				if(s.getS_type().equals("经济舱")){
					if(s.getS_number().matches("\\d+")){
						boxModiType3.setSelected(true);
					}
					txtModiNum3.setText(s.getS_number());
					txtModiPrice3.setText(s.getS_price()+"");
				}
			}
		}
		//点击确认修改的按钮
		if(e.getSource()==jbConfirm3){
			String flightId = (String)cbModiNum.getSelectedItem() ;//航班ID
			String fType=txtModiType.getText();
			String fStartTime=txtModiStartTime.getText();
			String fEndTime=txtModiEndTime.getText();
			String startAirString = (String)boxModiStartAir.getSelectedItem() ;
			String endAirString = (String) boxModiEndAir.getSelectedItem() ;
			String fComp=String.valueOf(boxModiCompany.getSelectedItem());
			String fNum1=txtModiNum1.getText();
			String fPrice1=txtModiPrice1.getText();
			String fNum2=txtModiNum2.getText();
			String fPrice2=txtModiPrice2.getText();
			String fNum3=txtModiNum3.getText();
			String fPrice3=txtModiPrice3.getText();
			
			//先得到  FlightAddr ----------->>>>?????????
			FlightAddr startAddr=dataHandle.queryOneFlightAddr("select * from flight_addr where a_air=?", new String[]{startAirString});
			System.out.println("FlightAddr:"+startAddr);
			FlightAddr endAddr=dataHandle.queryOneFlightAddr("select * from flight_addr where a_air=?", new String[]{endAirString});
			if(startAddr==null&&endAddr==null){
				JOptionPane.showMessageDialog(null, "目的地或出发地不存在！！");
				return ;
			}
			//要修改两张表1.flightInfo 
			String sql="update flight_info set f_Type=?,f_start_time=?,f_end_time=?,f_company=?,f_start=?,f_end=? where f_number=?";
			
			boolean bInfo=dataHandle.update(sql, new String[]{fType,fStartTime,fEndTime,fComp,startAddr.getA_id(),endAddr.getA_id(),flightId});
			
			//2.Seat  修改航班舱位表？
			sql="update seat set s_number=?,s_price=? where f_number=? and s_type=?";
			boolean bSeat1=dataHandle.update(sql, new String[]{fNum1,fPrice1,flightId,"头等舱"});
			sql="update seat set s_number=?,s_price=? where f_number=? and s_type=?";
			boolean bSeat2=dataHandle.update(sql, new String[]{fNum2,fPrice2,flightId,"商务舱"});
			sql="update seat set s_number=?,s_price=? where f_number=? and s_type=?";
			boolean bSeat3=dataHandle.update(sql, new String[]{fNum3,fPrice3,flightId,"经济舱"});
			System.out.println("boolean:"+bInfo+"  "+bSeat1+"  "+bSeat2+"  "+bSeat3);
			if(bInfo && bSeat1 && bSeat2 && bSeat3){
				int n = JOptionPane.showConfirmDialog(null, "修改成功！数据已录入数据中,是否继续修改?");
				if(n==JOptionPane.NO_OPTION){
					card.show(ip,"one");
				}
			}else{
				JOptionPane.showMessageDialog(null, "修改失败！");
			}
		}
		//点击航班动态管理的创建按钮
		if(e.getSource()==jbUpCreate){
			StateAddDialog sad = new StateAddDialog();
			sad.setVisible(true);
		}
		if(e.getSource()==jbUpDelete){
			//删除航班
			int selectRow = jTable.getSelectedRow() ;
			//得到 航班Id号跟动态日期
			String selectId = (String)jTable.getValueAt(selectRow, 0) ;
			String selectStateDate = (String)jTable.getValueAt(selectRow, 3) ;
			int num = JOptionPane.showConfirmDialog(null, "确认删除?") ;
			if(num==JOptionPane.YES_OPTION){
				boolean b = dataHandle.update("delete from state where fs_number=? and fs_date=?", new String[]{selectId,selectStateDate}) ;
				if(b){
					JOptionPane.showMessageDialog(null, selectId+"  "+selectStateDate+"动态已删除") ;
				}else {
					JOptionPane.showMessageDialog(null, "未知错误！删掉失败！") ;
				}
			}
		}
	}
//	@Override
//	public void itemStateChanged(ItemEvent e) {
//		
//		if(e.getSource() instanceof JCheckBox){
//			
//			JCheckBox jcb = ((JCheckBox)e.getSource());
//			if(jcb.)
//		}
//	}
	
	
}
