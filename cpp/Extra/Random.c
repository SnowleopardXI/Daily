#include "stdio.h"
#include "stdlib.h"
#include <time.h>
int* GetRand(int* buf,int count,int range,int down,int up)
{
    int i=0,j,r,flag=0;
	srand((unsigned)time(NULL));   //用当前时间作为随机种子 
	while(i<count)
	{
		r=rand() % (up+1-down)+down;  //生成一个1-36的随机数 
        if(r==0)
        {
            if(flag==0)
            {
                flag=1;
                buf[i]=r;
                i++;
                continue;
            }
        }
		for(j=i;j>=0;j--)
		{
			if(r==buf[j])     //与之前已存的随机数比较 
				break;
		}
		if(j<0)             //没有重复即保存到数组中 
		{
			buf[i]=r;
			i++;
		}
	}
    return buf;
}

struct All
{
    char name[16];
    int id;
}Al[35]={
    {"刘起瑞",20205040},
    {"高宇",20212528},
    {"郭家旗",20212529},
    {"郭晔",20212530},
    {"国文赫",20212531},
    {"李长金",20212532},
    {"李晨阳",20212533},
    {"李会彬",20212534},
    {"廖梓杰",20212535},
    {"林杰",20212536},
    {"龙翔",20212537},
    {"马润超",20212538},
    {"马志远",20212539},
    {"彭林康",20212540},
    {"曲成义",20212541},
    {"王凯涵",20212542},
    {"吴拓",20212543},
    {"肖天旭",20212544},
    {"徐率淇",20212545},
    {"徐子涵",20212546},
    {"阳冉升",20212547},
    {"杨广毅",20212548},
    {"张翔睿",20212549},
    {"张宇龙",20212550},
    {"周浩然",20212551},
    {"程佳梦",20212552},
    {"赖婷",20212553},
    {"刘烁宣",20212554},
    {"孙海燕",20212555},
    {"王安诺",20212556},
    {"王春畅",20212557},
    {"王玮琪",20212558},
    {"许婧慧",20212559},
    {"赵城雪",20212560},
    {"周桂聪",20212561},
};

void main(){
    int i,j,male=0,female=0,all,menu,CNT,num;
    printf("Author: 3awallstudio--Steve Ephraim Adam\nContact: yjzawall@gmail.com\nFile: name.c\nTime: 2022/03/02 15:41:05\nSoftware: Visual Code\n");
    printf("请选择一个选项:\n1:全局随机\n2:性别分类随机\n");
    scanf("%d",&menu);
    switch (menu)
    {
    case 1:
        printf("请输入要随机的人数:\n");
        scanf("%d",&CNT);
        if(CNT<1||CNT>35)
        {
            printf("输入错误，");
            break;
        }
        int* buf = (int*)malloc(sizeof(int)* CNT);
        buf = GetRand(buf, CNT, 35, 0,34);
        for (i = 0; i < CNT; i++)
        {
            if(buf[i]>=0&&buf[i]<=24)
                male++;
            else
                female++;
        }
        printf("共抽取%d名男生，%d名女生：\n",male,female);
        for (int j = 0; j < CNT; j++)
        {
            num = buf[j];
            printf("%d\t%d\t%s\n",num,Al[num].id,Al[num].name);
        }
        break;
    case 2:
        printf("请分别输入需随机的男生人数和女生人数:（本班共有10名女生，25名男生）\n");
        scanf("%d%d",&male,&female);
        if(male<0||male>25||female<0||female>10)
        {
            printf("输入错误，");
            break;
        }
        CNT=male;
        int* mbuf = (int*)malloc(sizeof(int)* CNT);
        mbuf = GetRand(mbuf, CNT, 25, 0,24);
        if(male!=0)
        {
            printf("男生随机结果：\n");
            for (int j = 0; j < CNT; j++)
            {
                num = mbuf[j];
                printf("%d\t%d\t%s\n",num,Al[num].id,Al[num].name);
            }
        }
        CNT=female;
        int* buff = (int*)malloc(sizeof(int)* CNT);
        buff = GetRand(buff, CNT, 10, 25,34);
        if(female!=0)
        {
            printf("女生随机结果：\n");
            for (int j = 0; j < CNT; j++)
            {
                num = buff[j];
                printf("%d\t%d\t%s\n",num,Al[num].id,Al[num].name);
            }
        }
        break;
    default:
        printf("输入错误，");
        break;
    }
    printf("请按回车键结束\n");
    getchar();
    getchar();
}