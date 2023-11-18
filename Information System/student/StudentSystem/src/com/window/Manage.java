package com.window;

import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Toolkit;
import java.awt.event.ActionListener;
import java.util.Vector;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableColumnModel;

import com.Thread.RunGetAccountStart;
import com.event.LoginEvent;
import com.event.WindowsEven;

import static javax.swing.JFrame.*;

public class Manage extends JFrame {
	//定义布局
	FlowLayout flowlayout;//定义一个布局

	
	//定义窗口的高度和宽度
	//窗口变量  
	final int WIDTH=800;//设置顶层框架的宽度
	final int HEIGHT=725;//设置顶层框架的高度
	//定义标签
	JLabel bgimg;//顶层的图片
	//定义菜单栏
	JMenuBar menubar;//顶一个菜单条
	JMenu menu,menu1;//定义一个菜单
	JMenuItem item1,item2,item3,item4;
	JMenuItem item1_1,item1_2;
	//定义一个盘子
	javax.swing.JPanel jpanel_1;//放图片和其他的盘子
	javax.swing.JPanel jpanel_2;//用来放表格
	//定义标签
	JLabel name;
	public static JTextField nametext;
	ButtonGroup group=null;
	public static JRadioButton Men,Women,allsex;
	JLabel age;
	public static JTextField agetext;
	
	JLabel grade;
	public static JTextField gradetext;
	
	JLabel number;
	public static JTextField numbertext;
	
	JButton add,del,change,show,reset;
	
	JLabel numbecondition;//学号条件
	public static JTextField numbeconditiontext;//学号条件文本
	
	public static JTextArea resultText;//显示结果
	
	//表格的数据
	Object columns[] ={"姓名","性别","年龄","班级","学号"};//标题信息
	JTable tableL=null;
	JScrollPane jscrollpane;	
	static Vector rwo;
	static Object a[][];
	static int row ;
	public static DefaultTableModel  model;
	static TableColumnModel columnModel;
	
	//定义一个监听
	ActionListener lintener_1;
	//定义一个窗口监听
	WindowsEven lintener_2;
	
	public  Manage() {
		init();
		setVisible(true); //设置当前窗口是否可显示 
		setResizable(false);//窗口的大小不可边
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);//设置默认关闭方式
		validate();//让组件生效
		
	}
	void init() {
	
		//定义布局
		flowlayout=new FlowLayout(FlowLayout.CENTER);//居中对齐 
		//第一步设置最底层的布局
		this.setLayout(null);
		this.setTitle("毕业生信息信息管理系统");
		// 设置当前窗口的大小
		Toolkit kit =Toolkit.getDefaultToolkit();//获取对象大小	//设置窗口位置
		Dimension screenSize=kit.getScreenSize();
		int width=screenSize.width;
		int height=screenSize.height;//获取屏幕高度和宽度
		int x=(width-WIDTH)/2;
		int y=(height-HEIGHT)/2;
		this.setBounds(x, y, WIDTH, HEIGHT);
		//设置背景图片
		ImageIcon img=new ImageIcon("src/img/3.jpg");//将图片读取放到img变量里面
		bgimg=new JLabel(img);
		bgimg.setBounds(0,0,img.getIconWidth(),100);//设置背景图片 设置背景位置
		//添加菜单栏
		menubar=new JMenuBar();//构造菜单条
		menu=new JMenu("管理");
		menu1=new JMenu("账号");
		item1=new JMenuItem("查看在线的账号",new  ImageIcon("src/img/I1.gif"));
		item2=new JMenuItem("查看所有账号",new  ImageIcon("src/img/I2.gif"));
		item3=new JMenuItem("更改毕业生账号信息",new  ImageIcon("src/img/I3.gif"));
		item4=new JMenuItem("更改当前账户密码",new  ImageIcon("src/img/I4.gif"));
		item1_1=new JMenuItem("退出",new  ImageIcon("src/img/I1_1.jpg"));
		item1_2=new JMenuItem("注销",new  ImageIcon("src/img/I1_2.jpg"));
		 //
		
		
		
		menu.add(item1);
		menu.add(item2);
		menu.add(item3);
		menu.add(item4);
		
		menu1.add(item1_1);
		menu1.add(item1_2);
		
		
		menubar.add(menu);
		menubar.add(menu1);
		//初始化第一个箱子
		jpanel_1  =new javax.swing.JPanel();
		jpanel_1.setLayout(flowlayout);//居中对齐
		jpanel_1.setBorder(BorderFactory.createTitledBorder("基本信息处理"));
		jpanel_1.setBounds(0, 100, WIDTH-14, 100);
		//添加按钮
		name=new JLabel("姓名");
		
		
		//添加文本
		
		nametext=new JTextField(12);
		//添加性别

		group=new ButtonGroup();
		Men=new JRadioButton("男");
		Women=new JRadioButton("女");
		allsex=new JRadioButton("全部");
		group.add(Men);
		group.add(Women);
		group.add(allsex);
		//添加年龄
		age=new JLabel("年龄");
		
		//添加年龄文本
		agetext=new JTextField(12);
		
		//添加班级
		grade=new JLabel("班级");
		
		//添加班级文本
		gradetext=new JTextField(8);
		
		//添加学号
		number=new JLabel("学号");
		
		//添加学号文本
		numbertext=new JTextField(8);

		//添加5个按钮
	
		add=new JButton("增加数据");
		del=new JButton("删除数据");
		change=new JButton("修改数据");
		show=new JButton("查找数据");
		reset=new JButton("重置数据");
		numbecondition=new JLabel("按学号查找：");//学号条件
		numbeconditiontext=new JTextField(14);//学号条件文本
		

		
		//设置第二个箱子的布局
		jpanel_2  =new javax.swing.JPanel();
		jpanel_2.setLayout(flowlayout);
		jpanel_2.setBounds(0, 200, WIDTH-14, 400);
		jpanel_2.setBorder(BorderFactory.createTitledBorder("学生数据信息显示"));
		
		
		table();
		//添加显示结果信息文本框
		resultText=new JTextArea();
		resultText.setBounds(10,510 , WIDTH-30, 150);
		resultText.setBorder(BorderFactory.createTitledBorder("账号信息显示"));
		resultText.setEditable(false); 
		
		jpanel_1.add(name);
		jpanel_1.add(nametext);
		jpanel_1.add(Men);
		jpanel_1.add(Women);
		jpanel_1.add(allsex);
		jpanel_1.add(age);
		jpanel_1.add(agetext);
		
		jpanel_1.add(grade);
		jpanel_1.add(gradetext);
		
		jpanel_1.add(number);
		jpanel_1.add(numbertext);
		
		jpanel_1.add(numbecondition);
		jpanel_1.add(numbeconditiontext);
		
		jpanel_1.add(add);
		jpanel_1.add(del);
		jpanel_1.add(change);
		jpanel_1.add(show);
		jpanel_1.add(reset);
		

		
		jpanel_2.add(jscrollpane);
		this.add(jpanel_2);
		this.add(jpanel_1);
		this.add(menubar);
		this.add(bgimg);
		this.setJMenuBar(menubar);
		this.add(resultText);
		setAllName();
		allEvent();
	}
	void table() {
		tableL=getTable();
		jscrollpane=new JScrollPane(tableL);//添加一个浏览窗格
		jscrollpane.setPreferredSize(new Dimension(WIDTH-30,250));//给窗格设置大小
		tableL.setPreferredSize(new Dimension(WIDTH-30,10000));//给表格设置大小
		jscrollpane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);//将滑动组件显示在窗口中
	
	}
	JTable getTable() {
		if(tableL==null) {
			tableL=new JTable();//创建 
			int[] columnWidth={150,150,150,150,150};//设置列宽
			model=new DefaultTableModel(){
				public boolean isCellEditable(int row, int column)
				{
				return false;
				}
				};//列宽 和行数  并且让表格不可编辑
			model.setColumnIdentifiers(columns);
			tableL.setModel(model);//设置为表格的模式
			columnModel=tableL.getColumnModel();//获取到表格的控制
			tableL.getTableHeader().setReorderingAllowed(false);//让表格不可拖动
			tableL.getTableHeader().setResizingAllowed(false);//让表格不可拖动
			int count=columnModel.getColumnCount();//返回列数和行数
			for(int i=0;i<count;i++){
				javax.swing.table.TableColumn column=columnModel.getColumn(i);//返回列表中的对象
				column.setPreferredWidth(columnWidth[i]);
			}
			 rwo = new Vector(5);
		}
		return tableL;
	}
	void allEvent() {
		lintener_1=new LoginEvent();
		lintener_2=new WindowsEven();
		item1.addActionListener(lintener_1);
		
		item2.addActionListener(lintener_1);
		item3.addActionListener(lintener_1);
		item4.addActionListener(lintener_1);
		item1_1.addActionListener(lintener_1);
		item1_2.addActionListener(lintener_1);
		add.addActionListener(lintener_1);
		del.addActionListener(lintener_1);
		change.addActionListener(lintener_1);
		show.addActionListener(lintener_1);
		reset.addActionListener(lintener_1);
		this.addWindowListener(lintener_2);
		
	}
	void setAllName() {
		item1.setName("item1");
		item2.setName("item2");
		item3.setName("item3");
		item4.setName("item4");
		item1_1.setName("item1_1");
		item1_2.setName("item1_2");

		add.setName("add");
		del.setName("del");
		change.setName("chan");
		show.setName("show");
		reset.setName("reset");
		show.setName("show");
		reset.setName("reset");
	
		
		
	}

}
