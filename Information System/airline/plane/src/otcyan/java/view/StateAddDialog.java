package otcyan.java.view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.util.Vector;

import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import otcyan.java.bean.FlightAddr;
import otcyan.java.bean.FlightInfo;
import otcyan.java.model.CheckInfo;
import otcyan.java.model.DataHandle;
import otcyan.java.tools.ImagePanel;
import otcyan.java.tools.Tookit;

public class StateAddDialog extends JDialog implements ActionListener{
	private DataHandle dataHandle;
	private Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize();
	private JButton jbConfirm,jbCancel;
	private JComboBox cbFlightId;
	private JTextField txtStartCity,txtEndCity,txtDate;
	private JTextArea taStates;
	private JScrollPane jsp;
	private CheckInfo checkInfo ;
	
	public StateAddDialog(){
		checkInfo = new CheckInfo() ;
		dataHandle = new DataHandle();
		init();
	}
	
	public void init(){
		this.setSize(600, 500) ;
		this.setModal(true);
		this.setLocationRelativeTo(null) ;
		this.setResizable(false) ;
		this.setTitle("创建航班动态") ;
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE) ;
		ImagePanel jPanel = null;
		try {
			jPanel = new ImagePanel(ImageIO.read(new File("image/171go.jpg")), dimension);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		JPanel jpAll=new JPanel();
		jpAll.setLayout(new BorderLayout());
		jpAll.setOpaque(false) ;
		
		//北边
		JPanel jpInfos=new JPanel();
		jpInfos.setOpaque(false);
		jpInfos.setLayout(new BorderLayout());
		jpInfos.setPreferredSize(new Dimension(250,100));
		JLabel jlCreateState=new JLabel("创建航班动态",JLabel.CENTER);
		jlCreateState.setForeground(Color.yellow);
		jlCreateState.setFont(Tookit.getFont5());
		jpInfos.add(jlCreateState,BorderLayout.CENTER);
		jPanel.add(jpAll);
		jpInfos.setOpaque(false);
		jpAll.add(jpInfos,BorderLayout.NORTH);
		
		//中间
		JPanel jpCenter=new JPanel();
		jpCenter.setLayout(new GridLayout(5,2,4,15));
		jpCenter.setOpaque(false);
		JLabel jlFlightId = new JLabel("航班号：");
		jlFlightId.setFont(Tookit.getFont5()) ;
		jlFlightId.setForeground(Color.YELLOW) ;
		jpCenter.add(jlFlightId);
		Vector<String> allFlightId=dataHandle.queryStringVector("select f_number from flight_info where 1=?", new String[]{"1"});
		cbFlightId = new JComboBox(allFlightId);
		cbFlightId.addActionListener(this);
		cbFlightId.setActionCommand("fid");
		jpCenter.add(cbFlightId);
		JLabel jlStartCity = new JLabel("起始城市：");
		jlStartCity.setFont(Tookit.getFont5());
		jlStartCity.setForeground(Color.yellow);
		jpCenter.add(jlStartCity);
		txtStartCity = new JTextField();
		jpCenter.add(txtStartCity);
		JLabel jlEndCity = new JLabel("到达城市：");
		jlEndCity.setFont(Tookit.getFont5());
		jlEndCity.setForeground(Color.yellow);
		jpCenter.add(jlEndCity);
		txtEndCity = new JTextField();
		jpCenter.add(txtEndCity);
		JLabel jlDate = new JLabel("动态日期:");
		jlDate.setFont(Tookit.getFont5());
		jlDate.setForeground(Color.yellow);
		jpCenter.add(jlDate);
		txtDate = new JTextField();
		jpCenter.add(txtDate);
		JLabel jlStates = new JLabel("航班动态描述：");
		jlStates.setFont(Tookit.getFont5());
		jlStates.setForeground(Color.yellow);
		jpCenter.add(jlStates);
		jsp = new JScrollPane();
		taStates = new JTextArea();
		jsp.setViewportView(taStates);
		jpCenter.add(jsp);
		
		jpAll.add(jpCenter,BorderLayout.CENTER);
		
		//底部
		JPanel jpButtom = new JPanel();
		jpButtom.setOpaque(false);
//		jpButtom.setLayout(new BorderLayout());
//		jpButtom.setPreferredSize(new Dimension(250,100));
		jbConfirm = new JButton("确      定");
		jbConfirm.addActionListener(this);
		jpButtom.add(jbConfirm);
		jbCancel = new JButton("取      消");
		jbCancel.addActionListener(this);
		jpButtom.add(jbCancel);
		jpAll.add(jpButtom,BorderLayout.SOUTH);
		
		jPanel.add(jpAll);
		this.add(jPanel);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		
		//选中航班号后
		if(e.getActionCommand().equals("fid")){
			String selectFlightId = (String)cbFlightId.getSelectedItem() ;
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
			//System.out.println("起始城市:"+startCity+"    end:"+endCity);
			txtStartCity.setText(startCity);
			txtStartCity.setEditable(false);
			txtEndCity.setText(endCity);
			txtEndCity.setEditable(false);
		}
		//创建就将数据添加到数据库
		if(e.getSource()==jbConfirm){
			String flightId = (String)cbFlightId.getSelectedItem() ;
			String fDate = txtDate.getText();
			String fDiscribe = taStates.getText();
			if(fDate.equals("") || fDiscribe.equals("")){
				JOptionPane.showMessageDialog(null, "动态日期或动态描述不能为空！");
				return ;
			}
			
			if(!checkInfo.isTrue(fDate)){
				JOptionPane.showMessageDialog(null, "格式不正确,请重新输入！！") ;
				txtDate.setText("") ;
				return ;
			}
			String sql = "insert into state values(?,?,?)";
			boolean b=dataHandle.update(sql, new String[]{flightId,fDate,fDiscribe});
			if(b){
				int num= JOptionPane.showConfirmDialog(null, "创建航班动态成功！是否继续？");
				if(num==JOptionPane.YES_OPTION){
					taStates.setText("");
				}else{
					taStates.setText("");
					this.dispose();
					return ;
				}
			}else{
				JOptionPane.showMessageDialog(null, "创建航班动态失败！");
			}
		}
		//取消就返回上级菜单
		if(e.getSource()==jbCancel){
			this.dispose();
			return ;
		}
	}
//	public static void main(String[] args) {
//		new StateAddDialog().setVisible(true);
//		
//	}
}
