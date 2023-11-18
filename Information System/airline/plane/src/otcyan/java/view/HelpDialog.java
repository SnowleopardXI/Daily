package otcyan.java.view;

import java.awt.Color;

import javax.swing.ImageIcon;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import otcyan.java.tools.Tookit;

public class HelpDialog extends JDialog{

	public HelpDialog(JFrame owner){
		super(owner) ;
		this.init() ;
	}
	
	public void init(){
		 
		 
		 JPanel jPanel = new JPanel() ;
		jPanel.setBackground(new Color(0xA9CAF3)) ;
		 
		 JLabel picture = new JLabel(new ImageIcon("image/logo.jpg"));
		 JLabel text = new JLabel() ;
		 text.setFont(Tookit.getFont1()) ;
		 text.setText("<html>这是普通旅客的客户端程序主要分为四个功能：<br>1.航班查询及预订：旅客输入出发城市跟到达城市可以查询<br>所有这个路线的航班信息并点击预订即可预订<br>2.取票查询：旅客根据身份证号码跟票号查询出所订的飞机票<br>3.航班动态：旅客输入出发城市跟到达城市可以查询所有这个<br>路线的航班信息，并跟踪动态<br>4.退票处理：输入身份证号跟票号进行前台退票</html>") ;
		 jPanel.add(picture) ;
		 jPanel.add(text) ;
		 this.add(jPanel) ;
		 
		 setSize(500,300);
		 setTitle("帮助");
		 this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		 this.setLocationRelativeTo(null);
		 this.setResizable(false);
		 this.setModal(true) ;
		 this.setVisible(true) ;
	}
}
