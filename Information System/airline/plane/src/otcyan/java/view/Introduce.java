package otcyan.java.view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;

import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;

import otcyan.java.tools.Tookit;

public class Introduce extends JPanel{

	JPanel jPanel = null ;
	public Introduce(){
		this.init();
	}

	private void init() {
		
		JPanel jPanel = new JPanel(new BorderLayout()) ;
		JLabel jLabel = new JLabel("飞机订票系统");
		jLabel.setFont(new Font("微软雅黑", Font.BOLD, 24)) ;
		jPanel.add(jLabel,BorderLayout.NORTH) ;
		
		JPanel center = new JPanel(new BorderLayout()) ;
		JLabel picture = new JLabel(new ImageIcon("image/jianjie.jpg")) ;
		//center.setPreferredSize(new Dimension(315,155)) ;
		JLabel text = new JLabel("<html>航空公司(Airlines)是以各种航空飞行器为运输工具为乘客和货物<br>提供民用航空服务的企业，它们一般需要<br>一个官方认可的运行证书或批准。航空公司使用的飞行器可以是它们自己<br>拥有的，也可以是租来的，它们可以独立<br>提供服务，或者与其它航空公司合伙或者组成联盟。<br>航空公司的规模可以从只有一架运输邮件或货物的飞机到拥有数百架飞机<br>提供各类全球性服务的国际航空公司。航空公司的服务<br>范围可以分洲际的、洲内的、国内的，也可以分航<br>班服务和包机服务。</html>");
		text.setFont(Tookit.getFont1());
		center.add(picture,BorderLayout.WEST) ;
		center.add(text) ;
		
		center.setOpaque(false) ;
		jPanel.add(center) ;
		jPanel.setOpaque(false) ;
		//this.setOpaque(false) ;
		this.add(jPanel) ;
		this.setSize(1008,680) ;
		this.setBackground(new Color(0x498DF8)) ;
	
	}

	public JPanel getjPanel() {
		return jPanel;
	}
	
}
