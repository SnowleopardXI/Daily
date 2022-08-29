#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include "ext.h"
//  因为防止报错
void addOut(){};
void changeOut(){};
void delOut(){};


void addIn(){};
void changeIn(){};
void delIn(){};
void showIn(){};

void showRest(){}; 
void cleanOut(){};
void cleanIn(){}; 
//  下面是主菜单的第三个查询功能后的子菜单代码
void showOut(){
		abcd :;  //这里使用了 goto ： 是为了每次执行了功能后返回到第一步重新打印子菜单 也可以用更好的逻辑实现循环 而不用goto函数
	MOUSEMSG m;//定义鼠标变量 m
	//菜单
	initgraph(800,600); //定义画布大小也就是黑框大小
	setbkcolor(WHITE);//设置背景颜色
	cleardevice();//刷新一次 略等于那个system(cls)
	setfillcolor(LIGHTBLUE); //设置后面用函数画出方框的背景颜色 这里设置成了浅蓝色
	//     (左上角)x1 y1 (右下角)x2 y2
	fillrectangle(200,140,600,160);
	fillrectangle(200,200,600,220);
	fillrectangle(200,260,600,280);
	fillrectangle(200,320,600,340);
	fillrectangle(200,380,600,400);
	fillrectangle(200,440,600,460);
	settextstyle(15,0,"楷体");//设置文字大小 格式 
	setbkmode(TRANSPARENT);// 去掉文字背景
	//下面是输出字体 参数：（起始位置x 起始位置y “带输出的字符串”）
	outtextxy(250,142,"查询某一年的总支出");
	outtextxy(250,202,"查询某年某月的总支出");
	outtextxy(250,262,"查询某年某月某日的支出");
	outtextxy(250,322,"根据关键字查询支出情况");
	outtextxy(250,382,"列出所有支出情况");
	outtextxy(250,442,"返回主菜单");
//进入触发条件的循环
	while(1){
	//
		
	//
		m = GetMouseMsg();
		if(m.x>=200 && m.x<= 600 && m.y >=140&& m.y<=160){//检测鼠标的位置 是否满足条件
			setlinecolor(RED);//满足后 设置新的边框为红色
			rectangle(190,135,610,165);//画新的边框
			//如果点击了 年份
			if(m.uMsg==WM_LBUTTONDOWN){
				//yearOut();//响应功能
				goto abcd;//功能实现后 跳转到 最开头
			}
		}else if(m.x>=200 && m.x<= 600 && m.y >=200&& m.y<=220){
			setlinecolor(RED);
			rectangle(190,195,610,225);
			//如果点击了月
			if(m.uMsg==WM_LBUTTONDOWN){
			//	monthOut();
				goto abcd;
			}
		}else if(m.x>=200 && m.x<= 600 && m.y >=260&& m.y<=280){
			setlinecolor(RED);
			rectangle(190,255,610,285);
			//点击了日
			if(m.uMsg==WM_LBUTTONDOWN){
			//	dayOut();
				goto abcd;
			}
		}else if(m.x>=200 && m.x<= 600 && m.y >=320&& m.y<=340){
			setlinecolor(RED);
			rectangle(190,315,610,345);
			//点击了关键字
			if(m.uMsg==WM_LBUTTONDOWN){
			//	memOut();
				goto abcd;
			}
		}
		//
		else if(m.x>=200 && m.x<= 600 && m.y >=380&& m.y<=400){//
			setlinecolor(RED);
			rectangle(190,375,610,405);
			//点击了列出所有
			if(m.uMsg==WM_LBUTTONDOWN){
			//	show();
				goto abcd;
			}
		}else if(m.x>=200 && m.x<= 600 && m.y >=440&& m.y<=460){//
			setlinecolor(RED);
			rectangle(190,435,610,465);
			//点击了返回
			if(m.uMsg==WM_LBUTTONDOWN){
				goto abcde;
			}
		}
		//一旦鼠标不在相应位置 将画出白色边框 覆盖之前的红色边框
		else {
			setlinecolor(WHITE);
			rectangle(190,135,610,165);
			rectangle(190,195,610,225);
			rectangle(190,255,610,285);
			rectangle(190,315,610,345);
			rectangle(190,375,610,405);
			rectangle(190,435,610,465);
		}
	}
	abcde:;//点击退出按钮 就跳转到这里退出子菜单 返回主菜单
}

//下面是主菜单的实现 实现的细节和子菜单的类似 
void drawMenu(){
	abcd :;
	MOUSEMSG m;
	//菜单
		initgraph(800,600);
		setbkcolor(WHITE);
		cleardevice();//刷新一次 略等于那个system(cls)
		setfillcolor(LIGHTBLUE);
		//           左边1 高1 左边2 高2
		fillrectangle(300,10,500,30);
		fillrectangle(300,50,500,70);
		fillrectangle(300,90,500,110);
		fillrectangle(300,130,500,150);
		
		fillrectangle(300,200,500,220);
		fillrectangle(300,240,500,260);
		fillrectangle(300,280,500,300);
		fillrectangle(300,320,500,340);
	
		fillrectangle(300,390,500,410);
		fillrectangle(300,430,500,450);
		fillrectangle(300,470,500,490);	
	
		settextstyle(15,0,"楷体");//设置文字格式
		setbkmode(TRANSPARENT);// 去掉文字背景
	
		outtextxy(370,15,"添加支出");
		outtextxy(370,55,"删除支出");
		outtextxy(370,95,"查询支出");
		outtextxy(370,135,"修改支出");


		outtextxy(370,205,"添加收入");
		outtextxy(370,245,"删除收入");
		outtextxy(370,280,"查询收入");
		outtextxy(370,320,"修改收入");

		outtextxy(380,395,"结算");
		outtextxy(355,433,"清空支出信息");
		outtextxy(355,472,"清空收入信息");

		settextcolor(BLACK);
			settextstyle(45,0,"楷体");
		outtextxy(120,530,"家庭财务管理系统V1.0(三组)");

	while(1){
		//
		
		//
		m = GetMouseMsg();
		if(m.x>=300 && m.x<= 500 && m.y >=10&& m.y<=30){
			setlinecolor(RED);
			rectangle(295,5,505,35);
			//如果点击了添加
			if(m.uMsg==WM_LBUTTONDOWN){
				addOut();
				goto abcd;
			}
		}
		 else if(m.x>=300 && m.x<= 500 && m.y >=50&& m.y<=70){
			setlinecolor(RED);
			rectangle(295,45,505,75);
			//如果点击了删除
			if(m.uMsg==WM_LBUTTONDOWN){
				delOut();
				goto abcd;
			}
		}else if(m.x>=300 && m.x<= 500 && m.y >=90&& m.y<=110){
			setlinecolor(RED);
			rectangle(295,85,505,115);
			//点击了查询
			if(m.uMsg==WM_LBUTTONDOWN){
				showOut();
				goto abcd;
			}
		}else if(m.x>=300 && m.x<= 500 && m.y >=130&& m.y<=150){
			setlinecolor(RED);
			rectangle(295,125,505,155);
			//点击了修改
			if(m.uMsg==WM_LBUTTONDOWN){
				changeOut();
				goto abcd;
			}
		}
		//
		else if(m.x>=300 && m.x<= 500 && m.y >=200&& m.y<=220){//
			setlinecolor(RED);
			rectangle(295,195,505,225);
			//点击了添加In
			if(m.uMsg==WM_LBUTTONDOWN){
				addIn();
				goto abcd;
			}
		}else if(m.x>=300 && m.x<= 500 && m.y >=240&& m.y<=260){//
			setlinecolor(RED);
			rectangle(295,235,505,265);
			//点击了删除In
			if(m.uMsg==WM_LBUTTONDOWN){
				delIn();
				goto abcd;
			}
		}else if(m.x>=300 && m.x<= 500 && m.y >=280&& m.y<=300){
			setlinecolor(RED);
			rectangle(295,275,505,305);
				//点击了查询In
			if(m.uMsg==WM_LBUTTONDOWN){
				showIn();
				goto abcd;
			}
		}else if(m.x>=300 && m.x<= 500 && m.y >=320&& m.y<=340){
			setlinecolor(RED);
			rectangle(295,315,505,345);
				//点击了修改In
			if(m.uMsg==WM_LBUTTONDOWN){
				changeIn();
				goto abcd;
			}

		}else if(m.x>=300 && m.x<= 500 && m.y >=390&& m.y<=410){
			setlinecolor(RED);
			rectangle(295,385,505,415);
				//点击了结算
			if(m.uMsg==WM_LBUTTONDOWN){
				showRest();
				goto abcd;
			}
		}else if(m.x>=300 && m.x<= 500 && m.y >=430&& m.y<=450){
			setlinecolor(RED);
			rectangle(295,425,505,455);
				//点击了清空Out
			if(m.uMsg==WM_LBUTTONDOWN){
				cleanOut();
				goto abcd;
			}
		}else if(m.x>=300 && m.x<= 500 && m.y >=470&& m.y<=490){
			setlinecolor(RED);
			rectangle(295,465,505,495);
				//点击了清空In
			if(m.uMsg==WM_LBUTTONDOWN){
				cleanIn();
				goto abcd;
			}
		}
		

		else {
			setlinecolor(WHITE);
			rectangle(295,5,505,35);
			rectangle(295,45,505,75);
			rectangle(295,85,505,115);
			rectangle(295,125,505,155);

			rectangle(295,235,505,265);
			rectangle(295,275,505,305);
			rectangle(295,315,505,345);
			rectangle(295,195,505,225);
	
			rectangle(295,385,505,415);
			rectangle(295,425,505,455);
			rectangle(295,465,505,495);
		}
	}
	getchar();
	closegraph();
}
int main(){
	drawMenu();
}