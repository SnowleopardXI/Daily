package otcyan.java.view;

import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.File;
import java.io.IOException;
import java.text.BreakIterator;
import java.util.Arrays;
import java.util.Date;
import java.util.HashMap;
import java.util.Random;
import java.util.Vector;

import javax.imageio.ImageIO;
import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.UIManager;



import otcyan.java.bean.Bank;
import otcyan.java.bean.FlightAddr;
import otcyan.java.bean.FlightInfo;
import otcyan.java.bean.Seat;
import otcyan.java.bean.User;
import otcyan.java.model.CheckInfo;
import otcyan.java.model.DataHandle;
import otcyan.java.model.FileOperation;
import otcyan.java.model.MyButtonRenderer;
import otcyan.java.model.SearchTableModel;
import otcyan.java.tools.DBHelp;
import otcyan.java.tools.ImagePanel;
import otcyan.java.tools.Tookit;

public class TicketSearchPanel extends JPanel implements ActionListener,MouseListener{

	private ImagePanel ticketSearchPanel = null ;
	private HashMap<String, Bank> map= null ;//一个票Id是用什么 银行账号买的 
	private CardLayout card = null ;
	private JButton queryButton = null ;
	private JButton resetButton = null ;
	private JButton order ;
	private JTextField jtf1,jtf2,jtf3,jtf1_1,jtf2_1,jtf3_1, idField,priceField;
	private JComboBox jcBox,jcBox_1, boxType ;
	private JLabel jl1 ,jl2,jl3,jl4,jlTop;
	private JTable jTable ;
	private DataHandle dataHandle ;
	private Vector<FlightInfo> fInfos  ;
	private Vector<Vector<Seat>> seats ;
	private FlightInfo selectFlightInfo = null ; 
	private Vector<String> remainType = null ;
	private Vector<Seat> selectSeat =  null ; 
	private SearchTableModel stmModel ;
	private boolean isGoing  = false ;
	private JScrollPane jsp ;
	private String currenTime ,bankName;
	private User user ;
	private JPanel c ;
	private CheckInfo checkInfo ;
	public TicketSearchPanel(User user){
		checkInfo = new CheckInfo() ;
		map = new HashMap<String, Bank>() ;
		dataHandle = new DataHandle() ;
		this.user = user ;
		UIManager.put("Label.font", Tookit.getFont1()) ;
		UIManager.put("Button.font", Tookit.getFont1()) ;
		UIManager.put("ComboBox.font", Tookit.getFont1()) ;
		UIManager.put("CheckBox.font", Tookit.getFont1()) ;
		remainType = new Vector<String>() ;
		currenTime = Tookit.getDateFormat("yyyy-MM-dd").format(new Date()) ;
		card = new CardLayout() ;
		this.init();
	}
	/**
	 * 第一张面板
	 * @return
	 */
	public JPanel onePanel(){
		JPanel jPanel = new JPanel(new BorderLayout()) ;
		jPanel.setOpaque(false) ;
		
		//控制北边
		JPanel north = new JPanel() ;
		north.setPreferredSize(new Dimension(1028,145)) ;
		north.setOpaque(false) ;
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
		 jl4 = new JLabel("出发时间：",JLabel.RIGHT);
		jl4.setBounds(200, 175, 74, 20) ;
		jl4.setFont(Tookit.getFont1()) ;
		jcBox = new JComboBox(new String[]{"全部时间段","00:00-06：00","06:00-12:00","12:00-18:00","18:00-24:00"}) ;
		jcBox.setFont(Tookit.getFont1()) ;
		jcBox.setBounds(275, 170, 100, 30) ;

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
		center.add(jl4) ;
		center.add(jcBox) ;
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
		JPanel jPanel = new JPanel(new BorderLayout()) ;
		jPanel.setOpaque(false) ;
		JPanel north = new JPanel() ;
		north.setOpaque(false) ;
		//得到所有 TextField值
		//加入到北边面板里
		jl1= new JLabel("出发城市：");
		jl1.setFont(Tookit.getFont1()) ;
		  jtf1_1 = new JTextField(12) ;
	     jl2 = new JLabel("到达城市：");
		jl2.setFont(Tookit.getFont1()) ;
		 jtf2_1 = new JTextField(12) ;
		 jl3 = new JLabel("出发日期：",JLabel.RIGHT);
		jl3.setFont(Tookit.getFont1()) ;
		 jtf3_1 = new JTextField() ;
		 jtf3_1.setPreferredSize(new Dimension(137, 23)) ;
		 jl4 = new JLabel("出发时间：",JLabel.RIGHT);
		jl4.setFont(Tookit.getFont1()) ;
		  jcBox_1 = new JComboBox(new String[]{"全部时间段","00:00-06:00","06:00-12:00","12:00-18:00","18:00-24:00"}) ;
		 jcBox_1.setFont(Tookit.getFont1()) ;

		queryButton = new JButton("开始查询");
		queryButton.addActionListener(this) ;
		queryButton.setFont(Tookit.getFont1()) ;
		queryButton.setBackground(new Color(0xA9CAF3)) ;
		
		order = new JButton("预订");
		order.addActionListener(this) ;
		order.setFont(Tookit.getFont1()) ;
		order.setBounds(180, 220, 120, 30) ;
		order.setBackground(new Color(0xA9CAF3)) ;
		
		north.add(jl1) ;
		north.add(jtf1_1) ;
		north.add(jl2) ;
		north.add(jtf2_1) ;
		north.add(jl3) ;
		north.add(jtf3_1) ;
		north.add(jl4) ;
		north.add(jcBox_1) ;
		north.add(queryButton) ;
		north.add(order) ;
		JPanel bank = new JPanel() ;//空面板
		bank.setOpaque(false) ;
		bank.setPreferredSize(new Dimension(1028,96)) ;
		JPanel top = new JPanel(new GridLayout(2,1)) ;
		top.setOpaque(false) ;
		top.add(bank)  ;
		top.add(north) ;
		jPanel.add(top,BorderLayout.NORTH) ;
	
		jsp = new JScrollPane() ;
		//jScrollPane设置透明
		jsp.setOpaque(false) ;
		jsp.getViewport().setOpaque(false) ;
		jPanel.add(jsp) ;
		return jPanel ;
	}
	
	private void init() {
		try {
			ticketSearchPanel = new ImagePanel(ImageIO.read(new File("image/ticketsearch.jpg")),new Dimension(Tookit.getScreen().width-100,Tookit.getScreen().height-100)) ;
			ticketSearchPanel.setLayout(card);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		ticketSearchPanel.add(this.onePanel(),"one") ;
		ticketSearchPanel.add(this.twoPanel(),"two") ;
		ticketSearchPanel.add(this.threePanel(),"three") ;
		ticketSearchPanel.add(this.fourPanel(),"four") ;
	}
	public JPanel getJPanel() {
		return ticketSearchPanel;
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		
		if(e.getActionCommand().equals("开始查询")){
			if(!isGoing){
				jtf3_1.setText(jtf3.getText().trim()) ;
				jtf2_1.setText(jtf2.getText().trim());
				jtf1_1.setText(jtf1.getText().trim()) ;
			}
			this.query() ;
		}
		
		if(e.getActionCommand().equals("重新查询")){
			this.clear() ;
		}
		if(e.getActionCommand().equals("预订")){
			this.order();
		}
		if(e.getActionCommand().equals("重新选择")){
			card.show(ticketSearchPanel, "two") ;
		}
		if(e.getActionCommand().equals("取消订单")){
			card.show(ticketSearchPanel, "two") ;
		}
		if(e.getActionCommand().equals("提交订单")){
			
			//赋值
			jlTop.setText("<html>应付金额：<font color=#FF0000 size=7>"+priceField.getText().trim()+"</font>元</html>") ;
			
			//得到所有 的这个用户的银行信息
			Vector<String> v = dataHandle.queryStringVector("select b_name from bank where b_u_name=? and b_u_card=?", new String[]{user.getU_name(),user.getU_idcard()}) ;
			//判断 有没有该账号
			if(v.size()==0){
				//表示 该用户没有网上银行
				JOptionPane.showMessageDialog(null, "没有网上银行,请注册！") ;
				//跳转
				card.show(ticketSearchPanel, "two") ;
				return ;
			}
			System.out.println(v);
			c.removeAll() ;//清除面板所有组件
			
			for(String bankNames:v){	
				Box box = Box.createVerticalBox() ;
				JLabel jl_bank =  new JLabel(bankNames,JLabel.CENTER);
				jl_bank.setFont(Tookit.getFont3()) ;
				box.add(jl_bank) ;
				jl_bank.addMouseListener(TicketSearchPanel.this) ;
				jl_bank.setEnabled(false) ;
				JLabel jl_picture = new JLabel(new ImageIcon("image/"+bankNames+".jpg")) ;
				box.add(jl_picture) ;
				c.add(box) ;
			}
			//跳到付款页面
			card.show(ticketSearchPanel, "four") ;
		}
		if(e.getActionCommand().equals("网上支付")){
			//判断钱是不是足够的
			String sql = "select b_balance from bank where b_u_name=? and b_u_card=? and b_name=?" ;
			String balanceString = dataHandle.queryOneString(sql, new String[]{user.getU_name(),user.getU_idcard(),bankName}) ;
			sql = "select b_account from bank where b_u_name=? and b_u_card=? and b_name=?" ;
			String account = dataHandle.queryOneString(sql, new String[]{user.getU_name(),user.getU_idcard(),bankName}) ;
			
			System.out.println(balanceString);	
			if(balanceString==null){
					JOptionPane.showMessageDialog(null, "请选择网上银行") ;
					return ;
				}
			double balance = Double.parseDouble(balanceString) ;
			//得到 当前票价
			double currentPrice = Double.parseDouble(priceField.getText().trim());
			if(balance<currentPrice){
				JOptionPane.showMessageDialog(TicketSearchPanel.this, "余额不足，无法支付!") ;
				//跳转
				card.show(ticketSearchPanel, "four") ;
				return ;
			}
			sql = "select t_seatId from tickets where t_date=? and t_f_number =? and t_type=?" ;
			//得到已卖座位号
			System.out.println(jtf3_1.getText().trim()+selectFlightInfo.getF_number()+(String)boxType.getSelectedItem());
			Vector<String> seatIds = dataHandle.queryStringVector(sql, new String[]{jtf3_1.getText().trim(),selectFlightInfo.getF_number(),(String)boxType.getSelectedItem()}) ;
			//分配座位 
			//得到 选择舱位的总数 
			int seatTotalNum = 0 ;
		     for(Seat seat : selectSeat){
		    	 if(seat.getS_type().equals((String)boxType.getSelectedItem())){
		    		 seatTotalNum = Integer.parseInt(seat.getS_number()) ;
		    		 break ;
		    	 }
		     }
		     //卖到 的座位号
		     int sellSeatNum = -1 ;
		     System.out.println("座位总数："+seatTotalNum+"已卖出："+seatIds);
		     
		     for (int i = 1; i <=seatTotalNum; i++) {
				
		    	 if(!seatIds.contains(i+"")){
		    		 sellSeatNum = i ;
		    		 break ;
		    	 }
			}	    
		    System.out.println(sellSeatNum);
		    System.out.println(selectFlightInfo.getF_number());
			//插入一个票务表
			sql = "insert into tickets values(?,?,?,?,?,?)" ;
			boolean b1 = dataHandle.update(sql, new String[]{"e"+new Random().nextInt(10000),selectFlightInfo.getF_number(),user.getU_id(),sellSeatNum+"",(String)boxType.getSelectedItem(),jtf3_1.getText().trim()}) ;
			//插入一个订单表
			sql = "select t_id from tickets where t_date=? and t_seatId=? and t_type=?" ;
		    String sellTicketId = dataHandle.queryOneString(sql, new String[]{jtf3_1.getText().trim(),sellSeatNum+"",(String)boxType.getSelectedItem()}) ;
			System.out.println("卖出的票的id:"+sellTicketId);
		    boolean b2 = dataHandle.update("insert into orders values(?,?,?,?)", new String[]{"O"+(new Random().nextInt(10000)),user.getU_id(),sellTicketId,currenTime}) ;
			//更新  bank表
			String remainBalance = (balance-currentPrice)+"" ;
			boolean b3 = dataHandle.update("update bank set b_balance=? where b_name=? and b_u_name=? and b_u_card=?", new String[]{remainBalance,bankName,user.getU_name(),user.getU_idcard()}) ;
		    System.out.println(b1+"  "+b2+"  "+b3+" ");
			if(b1 && b2 && b3){
				JOptionPane.showMessageDialog(null, "<html>恭喜"+user.getU_name()+"订票成功"+"<br>票号为:"+sellTicketId+"<br>座位号："+(String)boxType.getSelectedItem()+"   ZX"+sellSeatNum+"<br>登机时间："+jtf3_1.getText().trim()+"   "+selectFlightInfo.getF_start_time()+"<br>票价 ："+priceField.getText()+"</html>") ;
				//产生一个票
				FileOperation fileOperation = new FileOperation() ;
				boolean b4 = fileOperation.saveTickets(selectSeat.get(0), user, "   ZX"+sellSeatNum, (String)boxType.getSelectedItem(), jtf3_1.getText().trim(),sellTicketId) ;
				if(b4){
					JOptionPane.showMessageDialog(null, "票已保存在path/"+sellTicketId+"下") ;
				}else {
					JOptionPane.showMessageDialog(null, "票保存失败！！") ;
				}
				//将   这个 票的id 跟  银行卡号加入到一个hashMap里。。方便以后 退票
				Bank bank = dataHandle.queryOneBank("select * from bank where b_u_name=? and b_u_card=? and b_name=?", new String[]{user.getU_name(),user.getU_idcard(),bankName},user) ;
				//加载map信息
				HashMap<String, Bank> map = fileOperation.loadBank() ;
				if(map==null){
					map = new HashMap<String, Bank>() ;//防止 第一次的时候 没有值 
				}
				map.put(sellTicketId, bank) ;//放一个值 
				//保存到文件 里
				fileOperation.saveBank(map) ;
				
			}else{
				JOptionPane.showMessageDialog(null, "订票失败") ;
			}
			card.show(ticketSearchPanel, "two") ;
			this.query() ;
		}
	}
	
	public void clear(){
		this.jtf1.setText("") ;
		this.jtf2.setText("") ;
		this.jtf3.setText("") ;
		this.jcBox.setSelectedIndex(0) ;
	}
	
	public JPanel threePanel(){
		
		JPanel jPanel = new JPanel(new BorderLayout()) ;
		jPanel.setOpaque(false) ;
		//上面是一个空panel
		JPanel blankTop = new JPanel() ;
		blankTop.setOpaque(false) ;
		blankTop.setPreferredSize(new Dimension(Tookit.getScreen().width,103)) ;
		jPanel.add(blankTop,BorderLayout.NORTH) ;
		
		JPanel center = new JPanel(new BorderLayout()) ;
		center.setOpaque(false) ;
		JPanel top = new JPanel(new GridLayout(2, 7, 63, 30)) ;
		top.setOpaque(false) ;
		JLabel id = new JLabel("航班号",JLabel.CENTER) ;
		JLabel type = new JLabel("舱位",JLabel.CENTER) ;
		JLabel price = new JLabel("价格",JLabel.CENTER) ;
		JLabel name = new JLabel("姓名",JLabel.CENTER);
		JLabel cardType = new JLabel("证件类型",JLabel.CENTER) ;
		JLabel cardNum = new JLabel("证件号码") ;
		JLabel telNum = new JLabel("手机号码") ;
		
		idField = new JTextField() ;
		idField.setEditable(false) ;
		boxType = new JComboBox(remainType) ;//录用数据
	    priceField = new JTextField() ;
		priceField.setEditable(false) ;
		JTextField nameField = new JTextField(user.getU_name()) ;
		nameField.setEditable(false) ;
		JComboBox boxCardType = new JComboBox(new String[]{"身份证","学生证","居民证"}) ;
		JTextField cardNumField = new JTextField(user.getU_idcard()) ;
		cardNumField.setEditable(false) ;
		JTextField telNumField = new JTextField(user.getU_telephone()) ;
		telNumField.setEditable(false) ;
		top.add(id) ;
		top.add(type) ;
		top.add(price) ;
		top.add(name) ;
		top.add(cardType) ;
		top.add(cardNum) ;
		top.add(telNum) ;
		
		top.add(idField) ;
		top.add(boxType) ;
		top.add(priceField) ;
		top.add(nameField) ;
		top.add(boxCardType) ;
		top.add(cardNumField) ;
		top.add(telNumField) ;
		//top.setOpaque(false) ;
		center.add(top,BorderLayout.NORTH) ;
		//监听 
		boxType.addItemListener(new ItemListener() {
			
			@Override
			public void itemStateChanged(ItemEvent e) {
				if(remainType.size()!=0){
					//有舱位
					String string = (String)boxType.getSelectedItem() ;
					for(Seat seat :selectSeat){
						if(seat.getS_type().equals(string)){
							priceField.setText(seat.getS_price()+"") ;
							break ;
						}
					}
				}
			}
		}) ;
		
		//中间是一个
		//JPanel c = new JPanel() ;
		String s = "<html>1.一张有效身份证件同一乘车日期同一车次只能购买一张车票。 <br>2.购票时可使用的有效身份证件包括：中华人民共和国居民身份证、港澳居民来往内地通行证、台湾居民来往大陆通行证和按规定可使用的有效护照。<br>3. 购买儿童票时，乘车儿童有有效身份证件的，请填写本人有效身份证件信息。乘车儿童没有有效身份证件的，应使用同行成年人的有效身份证件信息；购票时不受前条限制，<br>4.但购票后、开车前须办理换票手续方可进站乘车。 <br>5.购买学生票时，须在我的常用联系人中登记乘车人的学生详细信息。学生票乘车时间限为每年的暑假6月1日至9月30日、寒假12月1日至3月31日。购票后、开车前，须办理换票手续方可进站乘车。换票时，新生凭录取通知书，毕业生凭学校书面证明，其他凭学生优惠卡。 <br>购买残疾军人（伤残警察）优待票的，须在购票后、开车前办理换票手续方可进站乘车。换票时，不符合规定的减价优待条件，没有有效中华人民共和国残疾军人证或中华<br>人民共和国伤残人民警察证的，不予换票，所购车票按规定办理退票手续。</html>";
		JLabel text = new JLabel(s) ;
		center.add(text) ;
		
		JPanel bottom = new JPanel() ;
		bottom.setOpaque(false) ;
		JButton reSelect = new JButton("重新选择");
		reSelect.addActionListener(this) ;
		reSelect.setFont(Tookit.getFont1()) ;
		reSelect.setBackground(new Color(0xA9CAF3)) ;
		JButton cancelSelect = new JButton("取消订单");
		cancelSelect.addActionListener(this) ;
		cancelSelect.setFont(Tookit.getFont1()) ;
		cancelSelect.setBackground(new Color(0xA9CAF3)) ;
		JButton subSelect = new JButton("提交订单");
		subSelect.addActionListener(this) ;
		subSelect.setFont(Tookit.getFont1()) ;
		subSelect.setBounds(180, 220, 120, 30) ;
		subSelect.setBackground(new Color(0xA9CAF3)) ;
		bottom.add(reSelect) ;
		bottom.add(cancelSelect) ;
		bottom.add(subSelect) ;
		center.add(bottom,BorderLayout.SOUTH) ;
		jPanel.add(center) ;
		//下面是一个空panel
		JPanel blankbottom = new JPanel() ;
		blankbottom.setOpaque(false) ;
		blankbottom.setPreferredSize(new Dimension(Tookit.getScreen().width,103)) ;
		jPanel.add(blankbottom,BorderLayout.SOUTH) ;
		return jPanel ;
	}
	
	public JPanel fourPanel(){
		
		JPanel jPanel = new JPanel(new BorderLayout()) ;
		jPanel.setOpaque(false) ;
		//上面是一个空panel
		JPanel blankTop = new JPanel() ;
		blankTop.setOpaque(false) ;
		blankTop.setPreferredSize(new Dimension(Tookit.getScreen().width,103)) ;
		jPanel.add(blankTop,BorderLayout.NORTH) ;
		
		JPanel center = new JPanel(new BorderLayout()) ;
		center.setOpaque(false) ;
		 jlTop = new JLabel() ;
		jlTop.setOpaque(false) ;
		
		center.add(jlTop,BorderLayout.NORTH) ;//中间北部
		
		//中间是一个janel
		//上面
		 c = new JPanel() ;
		 c.setOpaque(false) ;
		 center.add(c) ;//中间的中间
		 //中间的南部
		 JPanel jPanel3 = new JPanel(new GridLayout(2, 1)) ;
		  jPanel3.setOpaque(false) ;
		  
		 JLabel jlBottom = new JLabel("<html>1.请您选择支付银行。建议使用中国工商银行、中国农业银行、中国银行、招商银行、中国建设银行的银行卡，支付请直接点击相应银行的<br>按钮；如果您使用其他银行的银行卡，请点击“中国银联”按钮。<br>2.您点击支付银行后，将进入银行页面。请遵守相关银行规定进行操作。您在银行页面上进行的任何操作及其产生的任何法律后果，将按照<br>您与银行之间签订的合同处理。本网站不承担任何责任。</html>") ;
		 jPanel3.add(jlBottom) ;
		 
	 	JPanel jPanel2 = new JPanel() ;
	 	jPanel2.setOpaque(false) ;
		JButton reSelect1 = new JButton("重新选择");
		reSelect1.addActionListener(this) ;
		reSelect1.setFont(Tookit.getFont1()) ;
		reSelect1.setBackground(new Color(0xA9CAF3)) ;
		
		JButton onLine = new JButton("网上支付");
		onLine.addActionListener(this) ;
		onLine.setFont(Tookit.getFont1()) ;
		onLine.setBounds(180, 220, 120, 30) ;
		onLine.setBackground(new Color(0xA9CAF3)) ;
		jPanel2.add(reSelect1) ;
		jPanel2.add(onLine) ;
		jPanel3.add(jPanel2) ;
		
		//jPanel3.add(jlBottom) 
		center.add(jPanel3,BorderLayout.SOUTH) ;
		
		jPanel.add(center) ;
		//下面是一个空panel
		JPanel blankbottom = new JPanel() ;
		blankbottom.setOpaque(false) ;
		blankbottom.setPreferredSize(new Dimension(Tookit.getScreen().width,103)) ;
		jPanel.add(blankbottom,BorderLayout.SOUTH) ;
		return jPanel ;
	}
	/**
	 * 开始查询
	 */
	public void query (){
		
		String startCity = null ,endCity = null,startDate = null,startTime ;
		if(!isGoing){
			//表示 是第一个页面进入
			System.out.println("-------");
			startCity = this.jtf1.getText().trim() ;
			 endCity = this.jtf2.getText().trim();
			 startDate = this.jtf3.getText().trim() ;//需要作 判断
			 startTime  = (String)this.jcBox.getSelectedItem() ;
			
		}else {
			startCity = this.jtf1_1.getText().trim() ;
			 endCity = this.jtf2_1.getText().trim();
			 startDate = this.jtf3_1.getText().trim() ;//需要作 判断
			 startTime  = (String)this.jcBox_1.getSelectedItem() ;
		}
		//拆分
		System.out.println(startTime);
		String str[] = startTime.split("-") ;
		//判断 是不是全为空
		if(startCity.equals("") || endCity.equals("") || startDate.equals("")){
			JOptionPane.showMessageDialog(TicketSearchPanel.this, "请输入数据！！") ;
			return ;
		}
		//检查日期是不是有误
		if(!checkInfo.isTrue(startDate)){
			JOptionPane.showMessageDialog(null, "日期不正确，请重新输入！") ;
			return ;
		}
		isGoing = true ;
		card.show(ticketSearchPanel, "two") ;

		//首先根据 出发城市跟到达城市 查出所有 这个路线的航班地点表的Id
	
		String sql = "select * from flight_addr where a_city=?" ;
		String[] paraStartCity = {startCity} ;
		String[] paraEndCity = {endCity};
		//查出所有 出发城市的航班地点Id号
		Vector<FlightAddr> startCityIds = dataHandle.quertyMulInfo(sql, paraStartCity) ;
		//如果为空null，，表示 没有该起点城市 机场。。。。。需要转承、、、、
		//查出所有 到达城市的航班地点Id号
		Vector<FlightAddr> endCityIds = dataHandle.quertyMulInfo(sql, paraEndCity) ;
		
		//查出所有 的  从出发城市到到达城市 航班 飞机信息
		fInfos = dataHandle.queryMulFlightInfo(startCityIds, endCityIds,str) ;
		
		if(fInfos.size()==0){
			//表示没有直达的飞机
			JLabel jLabel = new JLabel("<html>没有直达飞机，是否<font color=#FF0000 size=7>转承</font></html>",JLabel.CENTER) ;
			
			jLabel.setFont(Tookit.getFont2()) ;
			jsp.setViewportView(jLabel) ;
			//预订按钮不可见
			order.setEnabled(false) ;
		}else {
			order.setEnabled(true) ;
			//查出所有 这个航班飞机的座位详细信息
			seats = new Vector<Vector<Seat>>() ;
			for(FlightInfo fInfo:fInfos){
				Vector<Seat> seat = dataHandle.querySeatsInfo("select * from seat where f_number=?", new String[]{fInfo.getF_number()},fInfo) ;
				seats.add(seat) ;
//				System.out.println(fInfo.getF_number()+"   "+fInfo.getF_start().getA_city()+"    "+fInfo.getF_start().getA_air()+"   "+fInfo.getF_end().getA_city()+"   " +fInfo.getF_end().getA_air()+"   "+fInfo.getF_start_time()+"  "+fInfo.getF_end_time());
			}
			//创建一个数据模型
			//放一个jtable 
			jTable = new JTable();
			stmModel = new SearchTableModel(seats,startDate) ;
			this.jTable.setModel(stmModel) ;
			//MyButtonRenderer   buttonRenderer= new MyButtonRenderer(jTable, 12) ;
			
			//jTable.getColumn("购票").setCellRenderer(buttonRenderer) ;//设置 一个button 在Jtable上
			jTable.setRowHeight(60) ;
			jTable.setBackground(new Color(0xA9CAF3)) ;
			jsp.setViewportView(jTable);
		}	
	}
	
	public void order(){
		

		//得到 选中的行
		int selectedRow = jTable.getSelectedRow() ;
		if(selectedRow==-1){
			JOptionPane.showMessageDialog(null, "至少选 中一行进行预订") ;
			return ;
		}
	
		//跳到第三个面板 上
		//得到User信息 
		//得到 Seat信息
		String selectFlightId = (String)stmModel.getValueAt(selectedRow, 0) ;
		//判断这个jtf3_1.getText().trim()日期  是否有航班动态 
		String state =dataHandle.queryOneString("select fs_state from state where fs_date=? and fs_number=?", new String[]{jtf3_1.getText().trim(),selectFlightId}) ;
		System.out.println(state);
		if(state!=null){
			if(state.matches(".*取消.*|.*延迟.*|.*推迟.*")){
				JOptionPane.showMessageDialog(null, "此航班在"+jtf3_1.getText().trim()+"已被取消,请关注航班动态信息") ;
				return ;
			}
		}
		for(FlightInfo fInfo: fInfos){
			if(fInfo.getF_number().equals(selectFlightId)){
				selectFlightInfo = fInfo ;
				break;
			}
		}
		for (Vector<Seat> v : seats) {
			for(Seat seat:v){
				if(seat.getfInfo().equals(selectFlightInfo)){
					selectSeat = v ;
					break ;
				}
			}
		}
		if(selectFlightInfo==null || selectSeat==null){
			JOptionPane.showMessageDialog(null, "数据出错！！") ;
			return ;
		}
		//选择的余数  经济舱  商务舱  头等舱
		String num1 = (String)stmModel.getValueAt(selectedRow, 8) ;
		String num2 = (String)stmModel.getValueAt(selectedRow, 9) ;
		String num3 = (String)stmModel.getValueAt(selectedRow, 10) ;
		//JOptionPane.showMessageDialog(null,jTable.getColumnName(8) ) ;
		//System.out.println(num1+"  "+num2+"  "+num3);
		remainType.removeAllElements() ;//移除所有 的元 素  防止 返回再次点入
		if(num1.matches("[1-9][0-9]*")){
			//表示 经济舱有票
			System.out.println(num1);
			remainType.add(jTable.getColumnName(8)) ;
		}
		if(num2.matches("[1-9][0-9]*")){
			//表示 经济舱有票
			remainType.add(jTable.getColumnName(9)) ;
		}
		if(num3.matches("[1-9][0-9]*")){
			//表示 经济舱有票
			remainType.add(jTable.getColumnName(10)) ;
		}
		System.out.println(remainType.size());
		boxType.setSelectedIndex(0) ;
		idField.setText(selectFlightId)  ;
		
		card.show(ticketSearchPanel, "three") ;
		//得到 
	
	}
	@Override
	public void mouseClicked(MouseEvent e) {
		
		if(e.getSource() instanceof JLabel){
			
			bankName = ((JLabel)e.getSource()).getText().trim() ; 
		}
		
	}
	@Override
	public void mouseEntered(MouseEvent e) {
		
		if(e.getSource() instanceof JLabel){
			JLabel mjlJLabel = ((JLabel)e.getSource()) ;
			mjlJLabel.setEnabled(true) ;
			mjlJLabel.setForeground(Tookit.getColor()) ;
			mjlJLabel.setCursor(new Cursor(Cursor.HAND_CURSOR)) ;
		}
		
	}
	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource() instanceof JLabel){
			JLabel mjlJLabel = ((JLabel)e.getSource()) ;
			mjlJLabel.setEnabled(false) ;
			mjlJLabel.setCursor(new Cursor(Cursor.DEFAULT_CURSOR)) ;
		}
	}
	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}
}
