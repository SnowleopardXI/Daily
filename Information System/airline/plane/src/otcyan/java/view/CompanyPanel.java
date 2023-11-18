package otcyan.java.view;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JPanel;

import otcyan.java.tools.ImagePanel;
/**
 * 显示公司的简介信息
 * @author Administrator
 *
 */
public class CompanyPanel extends JPanel{

	private ImagePanel iPanel = null; 
	public CompanyPanel(){
		
		
	}
	
	public JPanel getPanel(){
		return iPanel ;
	}
}


