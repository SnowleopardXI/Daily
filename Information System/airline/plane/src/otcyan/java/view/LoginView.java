package otcyan.java.view;

import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Date;
import java.util.Vector;

import javax.swing.Box;
import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JSpinner;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.border.EtchedBorder;
import javax.swing.border.TitledBorder;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.plaf.synth.Region;

import otcyan.java.bean.User;
import otcyan.java.dao.DbHandle;
import otcyan.java.model.CheckInfo;
import otcyan.java.model.DataHandle;
import otcyan.java.model.FileOperation;
import otcyan.java.tools.MyLoginPanel;
import otcyan.java.tools.Tookit;

public class LoginView extends JFrame implements MouseListener{
	
	private JTextField userNameField = null;
	private JPasswordField userPasswdField = null ;
    private  JPanel jp ;
    private FileOperation fileOperation  ;
    private Vector<String> loginNames ;
   // private JScrollPane autoTipPane ;
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new LoginView().setVisible(true);
	}
	
	public LoginView(){
		UIManager.put("TextField.font", Tookit.getFont1()) ;
		UIManager.put("Label.font", Tookit.getFont1()) ;
		UIManager.put("Button.font", Tookit.getFont1()) ;
		fileOperation = new FileOperation();
		//从文件中加载用户名过来
		loginNames = fileOperation.loading("path/loginName") ;
		this.init();
	}

	private void init() {
		//上面 的panel
		JPanel top = new JPanel() ;
		JLabel jTop = new JLabel(new ImageIcon("image/logo.gif")) ;
		top.add(jTop) ;
		this.add(top,BorderLayout.NORTH) ;
		//下面的panel
		JPanel buttom = new JPanel(new BorderLayout()) ;
		//左边
		buttom.add(this.leftPanel()) ;
		//右边
		buttom.add(this.rightPanel(),BorderLayout.EAST);
		 
		this.add(buttom) ;
		this.setSize(823, 500) ;
		this.setLocationRelativeTo(null) ;
		this.setResizable(false) ;
		this.setIconImage(new ImageIcon("image/1.png").getImage()) ;
		this.setTitle("飞机订票系统") ;
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE) ;
	}
	/**
	 * 处理左边登录面板
	 * @return
	 */
	public JPanel leftPanel(){
		JPanel jPanel = new JPanel(new BorderLayout()) ;
		//上面
		JLabel jLogin = new JLabel(new ImageIcon("image/enter_font1.jpg"),JLabel.CENTER) ;
		jPanel.add(jLogin,BorderLayout.NORTH) ;//加一个jlable
		//中间
		MyLoginPanel myPanel = new MyLoginPanel() ;
		myPanel.setLayout(null) ;
	
		final JLabel userName = new JLabel("登录名：",JLabel.CENTER) ;
		userName.setBounds(135, 70, 65, 15) ;
		userName.setFont(Tookit.getFont1()) ;
		myPanel.add(userName) ;
		//加一个面板   可以 存入多个jlabel
		jp = new JPanel() ;
		jp.setOpaque(false) ;
		//jp.setPreferredSize(new Dimension(140, 200)) ;
		//autoTipPane = new JScrollPane(jp) ;
		jp.setBounds(200, 89, 140, 200) ;
		//autoTipPane.setOpaque(false) ;
		//autoTipPane.getViewport().setOpaque(false) ;
		myPanel.add(jp) ;
		userNameField = new JTextField(12) ;
		userNameField.setBounds(200, 68, 140, 21) ;
		
		userNameField.getDocument().addDocumentListener(new DocumentListener() {
			
			//创建一个存入 jlabel的集合
			//Vector<JLabel> jLabels = new Vector<JLabel>() ;
			
			@Override
			public void removeUpdate(DocumentEvent e) {
				//每删除一个 字母
				LoginView.this.autoTip() ;
			}
			
			@Override
			public void insertUpdate(DocumentEvent e) {
				
				LoginView.this.autoTip() ;
			}
			
			@Override
			public void changedUpdate(DocumentEvent e) {
					
			}
		}) ;
		
		myPanel.add(userNameField) ;
		if(userNameField.getText().trim().equals("")){
			
		}
//		center.add(userName) ;
//		center.add(userNameField) ;
		JLabel userPasswd = new JLabel("密    码：",JLabel.CENTER) ;
		userPasswd.setFont(Tookit.getFont1()) ;
		userPasswd.setBounds(135, 124, 65, 15) ;
		userPasswdField = new JPasswordField(12) ;
		userPasswdField.setBounds(200, 124, 140, 21) ;
		myPanel.add(userPasswd) ;
		myPanel.add(userPasswdField) ;
		
		JLabel userGrade = new JLabel("身    份：",JLabel.CENTER) ;
		userGrade.setFont(Tookit.getFont1()) ;
		userGrade.setBounds(135, 166, 65, 15) ;
		final JComboBox jcb = new JComboBox(new String[]{"旅客","管理员"}) ;
		jcb.setBounds(200, 163, 71, 27) ;
		myPanel.add(userGrade) ;
		jcb.setFont(Tookit.getFont1()) ;
		myPanel.add(jcb) ;

		JButton login = new JButton("登录");
		login.setBounds(151, 215, 81, 30) ;
		myPanel.add(login) ;
		login.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {

				//取出用户名跟密码以及角色
				if(userName.getText().trim().equals("") ||String.valueOf(userPasswdField.getPassword()).trim().equals("")){
					JOptionPane.showMessageDialog(LoginView.this, "用户名或密码不能为空！！") ;
					return ;
				}
				//发送数据到数据库验证  数据库处理   
				DataHandle loginHandle = new DataHandle() ;
				//权限
				String power = ((String)jcb.getSelectedItem()).equals("旅客")?"0":"1" ;
				//用户名
				String userId = userNameField.getText().trim() ;
				//密码
				String userPasswd = String.valueOf(userPasswdField.getPassword()) ;
				User user = loginHandle.getUser(
						"select * from users where u_id=?",
						new String[] { userId });
				if(user!=null && user.getU_password().equals(userPasswd) && user.getU_power().equals(power)){
					//表示验证成功
					//得到用户姓名
					String userName = user.getU_name() ;
					String userSex = user.getU_sex() ;
					String userCall = userSex.equals("男")?"先生":"女士" ;
					if(power.equals("0")){
						//表示旅客
						JOptionPane.showMessageDialog(LoginView.this, "欢迎旅客"+userName+userCall+"登录") ;
						new GuestMainView(user).setVisible(true) ;
					}else {
						JOptionPane.showMessageDialog(LoginView.this, "欢迎管理员"+userName+userCall+"登录") ;
						new MangerMainView(user).setVisible(true) ;
					}
					//登录成功  将用户名加入到集合里  
					if(!loginNames.contains(userId)){
						//表示文件这个Id不存在
						loginNames.add(userId) ;
					}
					//序列到文件
					boolean b = fileOperation.save("path/loginName", loginNames) ;
					if(!b){
						JOptionPane.showMessageDialog(LoginView.this, "序列化文件失败");
						return ;
					}
					LoginView.this.dispose() ;
					
				}else{
					//验证不成功
					JOptionPane.showMessageDialog(LoginView.this, "用户名、密码与身份不匹配！！") ;
					userPasswdField.setText("") ;
				}
				
			}
		}) ;
		login.setPreferredSize(new Dimension(80, 30)) ;
		login.setBackground(new Color(0x71B8EC)) ;
		JButton exit = new JButton("退出");
		exit.setBounds(265, 215, 81, 30) ;
		myPanel.add(exit) ;
		exit.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				//可以在这里加一个滚动条  ？？
				System.exit(0) ;
			}
		}) ;
		exit.setPreferredSize(new Dimension(80, 30)) ;
		exit.setBackground(new Color(46,116,188)) ;
		jPanel.add(myPanel) ;
		return jPanel ;
	}
/**
 * 将右边设置为卡片布局
 * @return
 */
	public JPanel rightPanel(){
		
		final CardLayout card = new CardLayout() ;
		final JPanel right = new JPanel(card) ;
		right.setBorder(new TitledBorder(new EtchedBorder(), "新用户注册")) ;
		right.setPreferredSize(new Dimension(269, 363)) ;
		//right.setBackground(new Color(0xFFFFCC)) ;
		
		Box box = Box.createVerticalBox() ;
		box.add(Box.createHorizontalStrut(32)) ;
		
		JLabel jLabel = new JLabel() ;
		jLabel.setText("<html>" +"<h2>新用户注册</h2><hr>"+
				"1、免费注册<br> 2、实名注册 <br>3、注册用户可享受个性化服务<br><br> " +
				"</html>") ;
		box.add(jLabel) ;
		
		JButton regist = new JButton("注册") ;
		regist.setPreferredSize(new Dimension(100, 30)) ;
		regist.setBackground(new Color(0xFFFFCC)) ;
		box.add(regist) ;
		JPanel jpOne = new JPanel() ;
		jpOne.setOpaque(false) ;
		jpOne.add(box) ;
		right.add(jpOne,"one") ;
		//第二个panel
		JPanel jpTwo = new JPanel() ;
		jpTwo.setOpaque(false) ;
		jpTwo.setLayout(new BorderLayout()) ;
		String info ="<html>1、服务条款的确认<br>您点击服务条款页面下的“我同意”按钮，<br>即视为您已阅读、了解并完全同意服务条款<br>中的各项内容，包括本网站对服务条款所<br>作的任何修改。除另行明确声明外，本网站<br>任何服务范围或功能的变化均受服务条款约束。<br>2、服务条款的修改<br>本网站在必要时可修改服务条款，并在网站<br>进行公告，一经公告，立即生效。如您继续<br>使用服务，则视为您已接受修订的服务条款。<br>3、用户注册<br>考虑到本网站用户服务的重要性，您同意在<br>注册时提供真实、完整及准确的个人资料，<br>并及时更新。 如您提供的资料不准确，或<br>本网站有合理的理由认为该资料不真实、不<br>完整、不准确，本网站有权暂停或终止您的<br>注册身份及资料，并拒绝您<br>使用本网站的服务。4、用户资料及保密<br>注册时，请您选择填写用户名和密码，<br>并按页面提示提交相关信息。您负有对用户<br>名和密码保密的义务，并对该用户名和密<br>码下发生的所有活动承担责任。您同意邮件<br>服务的使用由您自己承担风险。本网站不<br>会向您所使用服务所涉及相关方之外的其他<br>方公开或透露您的个人资料，法律法规规定除外。 <html>" ;
		JLabel jLabel2 = new JLabel(info) ;
		jLabel2.setFont(Tookit.getFont1()) ;
		jpTwo.add(jLabel2) ;
		JPanel jpButton = new JPanel() ;
		jpButton.setOpaque(false) ;
		JButton accept = new JButton("同意") ;
		accept.setPreferredSize(new Dimension(100, 30)) ;
		accept.setBackground(new Color(0xFFFFCC)) ;
		jpButton.add(accept) ;
		JButton unaccept = new JButton("不同意") ;
		unaccept.setPreferredSize(new Dimension(100, 30)) ;
		unaccept.setBackground(new Color(0xFFFFCC)) ;
		jpButton.add(unaccept) ;
		jpTwo.add(jpButton,BorderLayout.SOUTH);
		right.add(new JScrollPane(jpTwo),"two") ;
		//第三个panel
		JPanel jpThree = new JPanel(new BorderLayout()) ;
		//jpThree.setOpaque(false) ;
		//jpThree.setPreferredSize(new Dimension(269,300)) ;
		JPanel infoPanel = new JPanel(new GridLayout(9, 2)) ;
		JLabel userId = new JLabel("用户名：",JLabel.CENTER);
		userId.setFont(Tookit.getFont1()) ;
		infoPanel.add(userId) ;
		final JTextField userIdField = new JTextField() ;
		infoPanel.add(userIdField) ;
		JLabel userPasswd = new JLabel("密码：",JLabel.CENTER);
		userPasswd.setFont(Tookit.getFont1()) ;
		infoPanel.add(userPasswd) ;
		final JPasswordField userPasswdField = new JPasswordField() ;
		infoPanel.add(userPasswdField) ;
		JLabel userPasswd1 = new JLabel("确认密码：",JLabel.CENTER);
		userPasswd1.setFont(Tookit.getFont1()) ;
		infoPanel.add(userPasswd1) ;
		final JPasswordField userPasswd1Field = new JPasswordField() ;
		infoPanel.add(userPasswd1Field) ;
		JLabel userName = new JLabel("姓   名：",JLabel.CENTER);
		userName.setFont(Tookit.getFont1()) ;
		infoPanel.add(userName) ;
		final JTextField userNameField = new JTextField() ;
		infoPanel.add(userNameField) ;
		//用户性别
		JLabel userSex = new JLabel("性别：",JLabel.CENTER) ;
		userSex.setFont(Tookit.getFont1()) ;
		JPanel jSex = new JPanel() ;
		jSex.setOpaque(false) ;
		final JRadioButton boy = new JRadioButton("男") ;
		boy.setOpaque(false) ;
		boy.setFont(Tookit.getFont1()) ;
		final JRadioButton girl = new JRadioButton("女") ;
		girl.setOpaque(false) ;
		girl.setFont(Tookit.getFont1()) ;
		ButtonGroup gbGroup = new ButtonGroup();
		gbGroup.add(boy) ;
		gbGroup.add(girl) ;
		jSex.add(boy) ;
		jSex.add(girl) ;
		infoPanel.add(userSex);
		infoPanel.add(jSex) ;
		JLabel tel = new JLabel("电话号码:",JLabel.CENTER);
		tel.setFont(Tookit.getFont1()) ;
		infoPanel.add(tel) ;
		final JTextField telField = new JTextField() ;
		infoPanel.add(telField) ;
		JLabel addr = new JLabel("地址：",JLabel.CENTER);
		addr.setFont(Tookit.getFont1()) ;
		infoPanel.add(addr) ;
		final JTextField addrField = new JTextField() ;
		infoPanel.add(addrField) ;
		JLabel email = new JLabel("电子邮件：",JLabel.CENTER);
		email.setFont(Tookit.getFont1()) ;
		infoPanel.add(email) ;
		final JTextField emailField = new JTextField() ;
		infoPanel.add(emailField) ;
		JLabel identity = new JLabel("身份证号：",JLabel.CENTER);
		identity.setFont(Tookit.getFont1()) ;
		infoPanel.add(identity) ;
		final JTextField identityField = new JTextField() ;
		infoPanel.add(identityField) ;
		jpThree.add(infoPanel) ;

		JPanel subMitPanel = new JPanel() ;
		JButton submit = new JButton("提交注册信息") ;
		submit.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				//得到所有的数据   9个数据
				String uId=userIdField.getText().trim();
				String uPassword=String.valueOf(userPasswdField.getPassword());
				String uName = userNameField.getText().trim();
				String uSex  = null;
				if(boy.isSelected()){
					uSex=boy.getText().trim();
				}
				if(girl.isSelected()){
					uSex=girl.getText().trim();
				}
				String uTelephone=telField.getText().trim();
				String uAddress  =addrField.getText().trim();
				String uEmail   = emailField.getText().trim();
				String uIdcard = identityField.getText().trim();
				
				//判断所有的是否为空
				if(uId.isEmpty()||uPassword.isEmpty()||userPasswd1Field.getPassword().toString().equals("")||uName.isEmpty()||uSex.isEmpty()||uTelephone.isEmpty()||uAddress.isEmpty()||uEmail.isEmpty()||uIdcard.isEmpty()){
					JOptionPane.showMessageDialog(null, "所填项不能为空！");
					return;
				}
				System.out.println(String.valueOf(userPasswd1Field.getPassword())+"-------"+uPassword);
				//做出判断   二次密码是 不是一样
				if(String.valueOf(userPasswd1Field.getPassword()).equals(uPassword)==false){
					JOptionPane.showMessageDialog(null, "两次密码不一致！");
					return;
				}
				//创建一个User
				User user = new User(uId, uPassword, uName, uSex, uTelephone, uAddress, uEmail, uIdcard, "0");
				CheckInfo checkInfo =new CheckInfo() ;
				boolean b = checkInfo.checkRegistInfo(user) ;
				System.out.println(b);
				if(b==true){
					//表示 数据 格式 是 正确的  此时连接数据库操作
					String sql="insert into users values(?,?,?,?,?,?,?,?,?)";
					String[] ss={uId, uPassword, uName, uSex, uTelephone, uAddress, uEmail, uIdcard, 0+""};
					
					DataHandle dataHandle=new DataHandle();
					boolean iss=dataHandle.update(sql, ss);
					if(iss){
						 JOptionPane.showConfirmDialog(null, "注册成功！是否继续?");
						card.show(right, "one") ;
					}else{
						JOptionPane.showMessageDialog(null, "注册失败！");
						return;
					}
				}	
//				}else{
//					JOptionPane.showMessageDialog(null, "格式不正确");
//				}
			}
		}) ;
		submit.setFont(Tookit.getFont1()) ;
		//submit.setPreferredSize(new Dimension(100, 30)) ;
		submit.setBackground(new Color(0xFFFFCC)) ;
		subMitPanel.add(submit) ;
		JButton reset = new JButton("重置") ;
		reset.setFont(Tookit.getFont1()) ;
		reset.setPreferredSize(new Dimension(100, 30)) ;
		reset.setBackground(new Color(0xFFFFCC)) ;
		subMitPanel.add(reset) ;
		jpThree.add(subMitPanel,BorderLayout.SOUTH) ;
		right.add(jpThree,"three") ;
		
		reset.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				userIdField.setText("") ;
				userNameField.setText("") ;
				userPasswdField.setText("") ;
				userPasswd1Field.setText("") ;
				telField.setText("") ;
				addrField.setText("") ;
				emailField.setText("") ;
				identityField.setText("") ;
			}
		}) ;
		regist.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				//点击了注册 
				card.show(right, "two") ;
			}
		}) ;
		accept.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				card.show(right, "three") ;
			}
		}) ;
		unaccept.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				card.show(right, "one") ;
			}
		}) ;
		return right ;
	}
	
	public void autoTip(){
		System.out.println("===");
		//清除面板所有 的 组件
		jp.removeAll() ;
		//jLabels.removeAllElements() ;
		//得到 文本域 的名
		String str = userNameField.getText().trim() ;
		
		for(String loginName :loginNames){
			if(loginName.startsWith(str) && !str.equals("")){
				//创建一个jlabel
				JLabel jLabel = new JLabel(loginName) ;
				jLabel.addMouseListener(LoginView.this) ;
				jLabel.setPreferredSize(new Dimension(140, 20));
				//jLabels.add(jLabel) ;
				jp.add(jLabel) ;	
			}
		}
		jp.repaint() ;
		//autoTipPane.repaint() ;
		jp.validate() ;//刷新界面
	//	autoTipPane.validate() ;
	}

	@Override
	public void mouseClicked(MouseEvent e) {
		
		userNameField.setText(((JLabel)e.getSource()).getText()) ;
		//设置面板属性	
		jp.removeAll() ;
		this.remove(jp) ;
		this.repaint() ;
		this.validate() ;

		//设置面板的宽度
		//jp.setBackground(Color.red) ;
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		JLabel jLabel = (JLabel)e.getSource() ;
		jLabel.setForeground(Tookit.getColor()) ;
		jLabel.setCursor(new Cursor(Cursor.HAND_CURSOR)) ;
	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		JLabel jLabel = (JLabel)e.getSource() ;
		jLabel.setForeground(Color.black) ;
		jLabel.setCursor(new Cursor(Cursor.DEFAULT_CURSOR)) ;
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
