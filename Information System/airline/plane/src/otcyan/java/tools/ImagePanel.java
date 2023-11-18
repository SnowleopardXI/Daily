/*
 * 这是一个可以动态加载图片作JPanel的背景
 */
package otcyan.java.tools;
import java.awt.*;
import javax.swing.*;
import javax.imageio.*;
import java.io.*;
public class ImagePanel extends JPanel{
	Image im;
	Dimension dimension ;
	public ImagePanel(Image im,Dimension dimension)
	{
		this.im=im;
		this.dimension = dimension ;
		//设置要画的Panel大小
		//自适应屏幕
		this.setSize(dimension);
	}
	//画出背景，自动调用
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		g.drawImage(im,0,0,dimension.width,dimension.height,this);
	}
}
