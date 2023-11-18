package otcyan.java.view;

import java.awt.AWTException;
import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.MenuItem;
import java.awt.PopupMenu;
import java.awt.SystemTray;
import java.awt.Toolkit;
import java.awt.TrayIcon;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JSplitPane;
import javax.swing.UIManager;

import otcyan.java.bean.User;
import otcyan.java.tools.ImagePanel;
import otcyan.java.tools.Tookit;

public class MangerMainView extends JFrame implements Runnable,MouseListener,ActionListener{
	

	
	private JMenuBar jmBar = null ;
	private JLabel timeLabel = null ;
	private CardLayout card = null ;
	private JSplitPane jsp = null;
	private JPanel rightPanel = null ;
	private JLabel[] jLabels = null;
	private User user = null ;
//	private  TrayIcon ti ;
//	public static void main(String[] args) {
//		MangerMainView mainView = new MangerMainView("otcyan");
//		mainView.setVisible(true) ;
//		//mainView.run() ;
//	}
	public MangerMainView(User user){
		this.user = user ;
		this.init() ;
	}
	public void init(){
		//修改默认字体 
		UIManager.put("Menu.font", Tookit.getFont1()) ;
		UIManager.put("MenuItem.font", Tookit.getFont1()) ;
		UIManager.put("MenuBar.background", new Color(0x498DF8)) ;
		//加菜单项
		this.setJMenuBar(this.initMenu()) ;
		//中间面板
		this.add(this.initCenterPanel()) ;
		//下面面板 
		this.add(this.buttonPanel(),BorderLayout.SOUTH) ;
		//this.setLocationRelativeTo(null) ;
		Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize() ;
		this.setSize(dimension.width-80, dimension.height-30) ;
		this.setTitle("航空订票系统") ;
		this.setIconImage(new ImageIcon("image/1.png").getImage()) ;
		this.setDefaultCloseOperation(EXIT_ON_CLOSE) ;		
//		//托盘
		this.initTi() ;
	}
	
	/**
	 * 初始化托盘
	 */
	public void initTi(){
		 try {  
             // 判断当前平台是否支持系统托盘  
             if (SystemTray.isSupported()) {  
                     // 获得系统托盘  
                     SystemTray st = SystemTray.getSystemTray();  

                     // 新建一个系统托盘按钮并制定图片  
                     Image image = Toolkit.getDefaultToolkit().getImage("image/1.png") ;// 定义托盘图标的图片  
                     TrayIcon ti = new TrayIcon(image);  

                     // 定义这个新建的托盘按钮  
                     ti.setToolTip("打开系统");  
                     ti.addMouseListener(new MouseAdapter() {  
                             public void mouseClicked(MouseEvent e) {  
                                     if (e.getButton() == MouseEvent.BUTTON1)// 鼠标左键单击，打开窗体  
                                             MangerMainView.this.setVisible(true);  
                                    MangerMainView.this.setExtendedState(JFrame.NORMAL);  
                             }  
                     });  
                     PopupMenu p = new PopupMenu("OK");  

                     MenuItem m1 = new MenuItem("打开");  
                     m1.addActionListener(new ActionListener() {  
                             public void actionPerformed(ActionEvent e) {  
                                    MangerMainView.this.setVisible(true);  
                                    MangerMainView.this.setExtendedState(JFrame.NORMAL);   
                             }  
                     });  
                     p.add(m1);  
                     p.addSeparator();  
                     MenuItem m = new MenuItem("退出");  
                     m.addActionListener(new ActionListener() {  
                             public void actionPerformed(ActionEvent e) {  
                                     System.exit(0);  
                             }  
                     });  
                     p.add(m);  
                     ti.setPopupMenu(p); // 为托盘添加右键菜单  

                     // 将定义好的托盘按钮绑定到系统图盘上  
                     st.add(ti);  
             }  
     } catch (Exception e) {  
             e.printStackTrace();  
     }  
	}

	/**
	 * 初始化中间的面板
	 * @return
	 */
	public JSplitPane initCenterPanel(){
		card = new CardLayout() ;
		Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize();
		
		ImagePanel leftPanel = null;
		
		try {
			leftPanel = new ImagePanel(ImageIO.read(new File("image/171go.jpg")),dimension);
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}//画主面板
		leftPanel.setLayout(new GridLayout(7, 1, 10, 10)) ;//左边为风格布局
		String info[] ={"机 票 查 询","改 签 处 理","航 班 动 态","退 票 处 理","销 售 统 计","后 台 管 理","退 出 系 统"};
		jLabels = new JLabel[7] ;
		for (int i = 0; i < info.length; i++) {
			JLabel jLabel = new JLabel(info[i],JLabel.CENTER);
			jLabels[i] = jLabel ;
			jLabel.setForeground(Tookit.getColor()) ;
			jLabel.setEnabled(false) ;
			jLabel.addMouseListener(this) ;
			jLabel.setFont(Tookit.getFont6()) ;
			leftPanel.add(jLabel) ;
		}
		
		rightPanel = new JPanel(card) ;//右边设置为卡片布局
		//创建一个机票查询面板
		TicketSearchPanel tsPanel = new TicketSearchPanel(user) ;
		rightPanel.add(tsPanel.getJPanel(), "tsPanel") ;
		//创建一个取票查询面板
		ModifyTicketPanel gtqView = new ModifyTicketPanel(user) ;
		rightPanel.add(gtqView.getJPanel(),"gtqPanel") ;
		//创建一个航班动态
		rightPanel.add(new PlaneStatePanel().getJPanel(),"pqPanel") ;
		//创建一个退票处理面板
		rightPanel.add(new ReturnTicketPanel(user).getJPanel(),"rtPanel") ;
		//创建一个销售统计面板
		rightPanel.add(new SalesCountPanel().getiPanel(),"scPanel") ;
		//创建一个后台管理面板	
		rightPanel.add(new BackManagerPanel().getIp(),"bmPanel") ;
		//创建一个介绍面板
		rightPanel.add(new Introduce(),"introduce") ;
		
		//把二个加入到拆分 面板
		 jsp = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,true,leftPanel,rightPanel) ;
		//设置左边窗体的大小
		int w=Toolkit.getDefaultToolkit().getScreenSize().width;
		jsp.setDividerLocation(w);
		//设置拆分窗体中间线的大小
		jsp.setDividerSize(0);
		//jsp.setEnabled(false) ;
		jsp.setOneTouchExpandable(true) ;//有伸展条
		return jsp ;
	}
	/**
	 * 初始化下面底部面板
	 * @return
	 */
	public JPanel buttonPanel(){
		
		JPanel buttomPanel = new JPanel(new BorderLayout()) ;
		
		buttomPanel.setBackground(new Color(0x498DF8)) ;
		
		 timeLabel= new  JLabel() ;//当前时间
		 //启动线程
		 new Thread(this).start() ;
		 buttomPanel.add(timeLabel,BorderLayout.EAST) ;
		 JLabel jLabel = new JLabel("管理员："+user.getU_name()+"登录") ;
		 jLabel.setFont(Tookit.getFont1());
		 buttomPanel.add(jLabel,BorderLayout.WEST) ;
		return buttomPanel ;
	}
	/**
	 * 初始化菜单
	 * @return
	 */
	public JMenuBar initMenu(){
		jmBar = new JMenuBar() ;
		//用户菜单
		JMenu jm1 = new JMenu("用户") ;
		JMenu jm2 = new JMenu("航班在线") ;
		JMenu jm3 = new JMenu("航班管理") ;
		JMenu jm4 = new JMenu("航班操作") ;
		JMenu jm5 = new JMenu("帮助") ;
		JMenuItem jm1_1 = new JMenuItem("切换用户") ;
		jm1_1.addActionListener(this) ;
		JMenuItem jm1_2 = new JMenuItem("用户信息修改");
		jm1_2.addActionListener(this) ;
		JMenuItem jm1_3 = new JMenuItem("用户退出") ;
		jm1_3.addActionListener(this) ;
		jm1.add(jm1_1) ;
		jm1.add(jm1_2) ;
		jm1.add(jm1_3) ;
		
		JMenuItem jm2_1 = new JMenuItem("读取消息") ;
		jm2_1.addActionListener(this) ;
		JMenuItem jm2_2 = new JMenuItem("发送消息") ;
		jm2_2.addActionListener(this) ;
		jm2.add(jm2_1) ;
		jm2.add(jm2_2) ;
		
		JMenuItem jmi3_1 = new JMenuItem("创建航班") ;
		jmi3_1.addActionListener(this) ;
		jmi3_1.setActionCommand("back") ;
		JMenuItem jmi3_2 = new JMenuItem("取消航班") ;
		jmi3_2.addActionListener(this) ;
		jmi3_2.setActionCommand("back") ;
		JMenuItem jmi3_3 = new JMenuItem("航班修改") ;
		jmi3_3.addActionListener(this) ;
		jmi3_3.setActionCommand("back") ;
		JMenuItem jmi3_4 = new JMenuItem("航班动态修改") ;
		jmi3_4.addActionListener(this) ;
		jmi3_4.setActionCommand("back") ;
		jm3.add(jmi3_1) ;
		jm3.add(jmi3_2) ;
		jm3.add(jmi3_3) ;
		jm3.add(jmi3_4) ;
		
		JMenuItem jm4_1 = new JMenuItem("机票查询") ;
		jm4_1.addActionListener(this) ;
		JMenuItem jm4_2 = new JMenuItem("改签查询") ;
		jm4_2.addActionListener(this) ;
		JMenuItem jm4_3 = new JMenuItem("航班动态") ;
		jm4_3.addActionListener(this) ;
		JMenuItem jm4_4 = new JMenuItem("退票处理") ;
		jm4_4.addActionListener(this) ;
		jm4.add(jm4_1) ;
		jm4.add(jm4_2) ;
		jm4.add(jm4_3) ;
		jm4.add(jm4_4) ;
		
		JMenuItem jm5_1 = new JMenuItem("系统简介") ;
		jm5_1.addActionListener(this) ;
		JMenuItem jm5_2 = new JMenuItem("帮助") ;
		jm5_2.addActionListener(this) ;
		jm5.add(jm5_1) ;
		jm5.add(jm5_2) ;
		
		jmBar.add(jm1) ;
		jmBar.add(jm2) ;
		jmBar.add(jm3) ;
		jmBar.add(jm4) ;
		jmBar.add(jm5) ;
		return jmBar ;
	}

	@Override
	public void run() {
		
		while(true){
			timeLabel.setText(Tookit.getCurrentTime()) ;
			try {
				Thread.sleep(1000) ;
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}//睡一秒
		}
		
	}
	@Override
	public void mouseClicked(MouseEvent e) {
		
		if(((JLabel)e.getSource()).getText().trim().equals("机 票 查 询")){
			card.show(rightPanel, "tsPanel") ;
			jsp.setDividerSize(10);
			jsp.setDividerLocation(200) ;
		}
		
		
		if(((JLabel)e.getSource()).getText().trim().equals("改 签 处 理")){
			card.show(rightPanel, "gtqPanel") ;
			jsp.setDividerSize(10);
			jsp.setDividerLocation(200) ;
		}
		if(((JLabel)e.getSource()).getText().trim().equals("航 班 动 态")){
			card.show(rightPanel, "pqPanel") ;
			jsp.setDividerSize(10);
			jsp.setDividerLocation(200) ;
		}
		if(((JLabel)e.getSource()).getText().trim().equals("退 票 处 理")){
			card.show(rightPanel, "rtPanel") ;
			jsp.setDividerSize(10);
			jsp.setDividerLocation(200) ;
		}
		if(((JLabel)e.getSource()).getText().trim().equals("退 出 系 统")){
			//退出系统 
			int num = JOptionPane.showConfirmDialog(this, "是否真的退出系统?") ;
			if(num==JOptionPane.YES_OPTION){
				//退出系统 
				System.exit(0) ;
			}
		}
		if(((JLabel)e.getSource()).getText().trim().equals("销 售 统 计")){
			card.show(rightPanel, "scPanel") ;
			jsp.setDividerSize(10);
			jsp.setDividerLocation(200) ;
		}
		if(((JLabel)e.getSource()).getText().trim().equals("后 台 管 理")){
			card.show(rightPanel, "bmPanel") ;
			jsp.setDividerSize(10);
			jsp.setDividerLocation(200) ;
		}
		if(((JLabel)e.getSource()).getText().trim().equals("系 统 简 介")){
			card.show(rightPanel, "introduce") ;
			jsp.setDividerSize(10);
			jsp.setDividerLocation(200) ;
		}
		
		
	}
	@Override
	public void mouseEntered(MouseEvent e) {
		//将label变为可见
		for (int i = 0; i < jLabels.length; i++) {
			if(e.getSource()==jLabels[i]){
				//表示 点击到了哪一个
				jLabels[i].setEnabled(true) ;
				jLabels[i].setCursor(new Cursor(Cursor.HAND_CURSOR)) ;//为什么没有效果
				//jLabels[i].validate() ;
				return ;
			}
		}
		
	}
	@Override
	public void mouseExited(MouseEvent e) {

		for (int i = 0; i < jLabels.length; i++) {
			if(e.getSource()==jLabels[i]){
				//表示 点击到了哪一个
				jLabels[i].setEnabled(false) ;
			//	jLabels[i].setCursor(new Cursor(Cursor.MOVE_CURSOR)) ;
				return ;
			}
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
	@Override
	public void actionPerformed(ActionEvent e) {

		//表示 是标签
		if(e.getActionCommand().trim().equals("机票查询")){
			card.show(rightPanel, "tsPanel") ;
			jsp.setDividerSize(10);
			jsp.setDividerLocation(200) ;
		}
		if(e.getActionCommand().trim().equals("改签查询")){
			card.show(rightPanel, "gtqPanel") ;
			jsp.setDividerSize(10);
			jsp.setDividerLocation(200) ;
		}
		if(e.getActionCommand().trim().equals("航班动态")){
			card.show(rightPanel, "pqPanel") ;
			jsp.setDividerSize(10);
			jsp.setDividerLocation(200) ;
		}
		if(e.getActionCommand().trim().equals("退票处理")){
			System.out.println("tuipaio");
			card.show(rightPanel, "rtPanel") ;
			jsp.setDividerSize(10);
			jsp.setDividerLocation(200) ;
		}
		if(e.getActionCommand().trim().equals("back")){
			
			card.show(rightPanel, "bmPanel") ;
			jsp.setDividerSize(10);
			jsp.setDividerLocation(200) ;
		}
		
		if(e.getActionCommand().trim().equals("用户退出")){
			//退出系统 
			int num = JOptionPane.showConfirmDialog(this, "是否真的退出系统?") ;
			if(num==JOptionPane.YES_OPTION){
				//退出系统 
				System.exit(0) ;
			}
		}
		if(e.getActionCommand().trim().equals("帮助")){
			//退出系统 
			HelpDialog helpDialog = new HelpDialog(this) ;
			helpDialog.setTitle("帮助") ;
		}
		if(e.getActionCommand().trim().equals("切换用户")){
			//跳到登录页面
			new LoginView().setVisible(true) ;
			this.dispose() ;
		}
		//跳到用户修改界面
		if (e.getActionCommand().trim().equals("用户信息修改")) {
			Userinformodification userinfor = new Userinformodification(MangerMainView.this,user);
			userinfor.setVisible(true);
			MangerMainView.this.dispose() ;
		}
		
		if(e.getActionCommand().trim().equals("系统简介")){
			card.show(rightPanel, "introduce") ;
			jsp.setDividerSize(10);
			jsp.setDividerLocation(200) ;
		}
//		if(e.getActionCommand().trim().equals("系统简介")){
//			card.show(rightPanel, "introduce") ;
//			jsp.setDividerSize(10);
//			jsp.setDividerLocation(200) ;
//		}
	
	}

}
