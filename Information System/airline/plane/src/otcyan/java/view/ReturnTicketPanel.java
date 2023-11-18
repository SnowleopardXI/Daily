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
import otcyan.java.bean.User;
import otcyan.java.model.DataHandle;
import otcyan.java.model.FileOperation;
import otcyan.java.model.ReturnTicketModel;
import otcyan.java.tools.ImagePanel;
import otcyan.java.tools.Tookit;

public class ReturnTicketPanel extends JPanel implements ActionListener{
	


	private ImagePanel iPanel = null ;
	private CardLayout card = null ;
	private JButton queryButton, unButton ,backButton= null ;
	private JScrollPane jsp ;
	private DataHandle dataHandle ;
	private JTable jTable ;
	//private JButton resetButton  = null ;
	private User user  ;
	public ReturnTicketPanel(User user){
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
		 unButton = new JButton("退  订");
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
				JOptionPane.showMessageDialog(null, "请选 中一行进行退订") ;
				return ;
			}
		
			String ticketId = (String)jTable.getValueAt(selectedRow, 0) ;
			JOptionPane.showMessageDialog(null, ticketId) ;
			//先从order删除 
			boolean b1 = dataHandle.update("delete from orders where o_tid=?", new String[]{ticketId}) ;
			//再删除tickets表
			boolean b2 = dataHandle.update("delete from tickets where t_id=?", new String[]{ticketId}) ;
			
			System.out.println(b1+""+b2);
			if(b1 && b2){
				//退款给买的那张卡 
				String ticketPrice = dataHandle.queryOneString("select s_price from seat where f_number=? and s_type=?", new String[]{(String)jTable.getValueAt(selectedRow, 1),(String)jTable.getValueAt(selectedRow, 4)}) ;
				//退款
				JOptionPane.showMessageDialog(null, "退订成功！！") ;
				//更新model
				this.query() ;
				//票删除 从文件 中
				File file = new File("path/"+ticketId) ;
				if(file.exists()){
					if(file.delete()){
						JOptionPane.showMessageDialog(null, "已从path中把"+ticketId+"票移除") ;
					}else {
						JOptionPane.showMessageDialog(null, "从path中"+ticketId+"票移除失败") ;
					}
				}
				Bank bank = null ;
				//读取买票 时的bank信息
				FileOperation fileOperation = new FileOperation() ;
				HashMap<String, Bank> map = fileOperation.loadBank() ;
				if(map!=null){
					for(String s : map.keySet()){
						if(s.equals(ticketId)){
							bank = map.get(s) ;
							break ;
						}
					}
				}
				
				if(bank==null){
					JOptionPane.showMessageDialog(null, "还款失败！！银行初始化数据失败！！");
					return ;
				}
				
				boolean b = dataHandle.update("update bank set b_balance=? where b_account=?", new String[]{Double.parseDouble(bank.getB_balance())+Double.parseDouble(ticketPrice)+"",bank.getB_account()}) ;
					if(b){
						JOptionPane.showMessageDialog(null, "退款成功！！已向您的"+bank.getB_name()+":"+bank.getB_account()+"退还"+ticketPrice+"元") ;
					}
				
			}else{
				JOptionPane.showMessageDialog(null, "退订失败！！") ;
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
