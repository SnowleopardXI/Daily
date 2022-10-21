#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <fstream>//文件流
#define N 100
using namespace std;

//关于顶点集和边集 
struct vertex{
	int name;
};//顶点结构
int vertexCount=0;
vertex vertexSet[N]; 

struct edge{
	int V1,V2;
}; //边结构 
int edgeCount=0;
edge edgeSet[N]; 

//读取数据 
void loadData(){
	FILE *fp;
	fp=fopen("input.txt","r");
	if(fp==NULL){
		printf("ERROE!");
	}
	fscanf(fp,"%d\n",&vertexCount);//第一行是顶点个数 
	int i;
	for(i=0;i<vertexCount;i++){
		vertexSet[i].name=i+1;//顶点名字从1开始 
	}
	while(!feof(fp)){
		fscanf(fp,"%d,%d\n",&edgeSet[edgeCount].V1,&edgeSet[edgeCount].V2);
		edgeCount++;
	}
}

//打印读入的数据
void printDate(){
	printf("vertexCount is %d\n",vertexCount);
	int i;
	for(i=0;i<edgeCount;i++){
		printf("%d,%d\n",edgeSet[i].V1,edgeSet[i].V2);
	}
} 

//构建双亲表示法结点结构 
struct parentTree{
	int name;//结点本身的信息 
	int parentIndex;//下标 
	int k;//层数k 
};
parentTree parentNode[N];

#define unknow -1000
void BuildParentTree(){
	int i,j,k;
	for(i=0;i<vertexCount;i++){
		parentNode[i].name=vertexSet[i].name;
		parentNode[i].parentIndex=unknow;
	}
	parentNode[0].parentIndex=-1;
	for(i=0;i<vertexCount;i++){
		for(j=1;j<vertexCount;j++){
			for(k=0;k<edgeCount;k++){
				if(
					(edgeSet[k].V1==parentNode[i].name&&
					 edgeSet[k].V2==parentNode[j].name&&
					 parentNode[i].parentIndex!=unknow&&
					 parentNode[j].parentIndex==unknow)
					 ||
					 (edgeSet[k].V1==parentNode[j].name&&
					  edgeSet[k].V2==parentNode[i].name&&
					  parentNode[i].parentIndex!=unknow&&
					  parentNode[j].parentIndex==unknow)
					)
				{
					parentNode[j].parentIndex=i; 
				}
		}
	}
}

//求层数
for(i=0;i<vertexCount;i++){
	parentNode[i].k=0;
	for(j=i;parentNode[j].parentIndex!=-1;j=parentNode[j].parentIndex){
		parentNode[i].k++;	
	}
} 
}
//凹凸表示法
void printParentTree(int v)
{
	if(v==0){
		printf("%d\n",parentNode[v].name);
	}
	int i,j;
	for(i=0;i<vertexCount;i++){
		if(parentNode[i].parentIndex==v){
			for(j=0;i<parentNode[i].k;j++){
				printf("\t");
			}
			printf("%d\n",parentNode[i].name);
			printParentTree(i);
		}
	}
} 

//孩子兄弟表示法树的建立
struct BrotherChildTree{
	int name;
	BrotherChildTree *firstchild;
	BrotherChildTree *nextsibling;
}; 
void buildBCTree(int index,BrotherChildTree *T){
	int tIndex;
	int i;
	//找孩子
	for(i=0;i<vertexCount;i++){
		if(parentNode[i].parentIndex==index){
			BrotherChildTree *p=(BrotherChildTree*)malloc(sizeof(BrotherChildTree));
			p->name=parentNode[i].name;
			p->firstchild=NULL;
			p->nextsibling=NULL;
			T->firstchild=p;
			T->nextsibling=NULL;
			tIndex=i;
			break;
		}
	} 
	if(T->firstchild!=NULL){
		buildBCTree(tIndex,T->firstchild);
	}
	//找兄弟
	for(i=index+1;i<vertexCount;i++){
		if(parentNode[i].parentIndex==parentNode[index].parentIndex){
			BrotherChildTree *p=(BrotherChildTree *)malloc(sizeof(BrotherChildTree));
			p->name=parentNode[i].name;
			p->firstchild=NULL;
			p->nextsibling=NULL;
			T->nextsibling=p;
			tIndex=i;
			break;
		}
	} 
	if(T->nextsibling!=NULL){
		buildBCTree(tIndex,T->nextsibling);
	}
}

//括号表示法输出
void printBCTree(BrotherChildTree *root,char *string){
	strcat(string,"(");
	char buf[2]=" ";
	itoa(root->name,buf,10);
	strcat(string,buf);
	if(root->firstchild != NULL){
	strcat(string,",");
	printBCTree(root->firstchild,string);
 	} 
	if(root->nextsibling != NULL){
	strcat(string,",");
	printBCTree(root->nextsibling,string);
 	}
	strcat(string,")");
}

int main()
{
    loadData();
    BuildParentTree();
    printParentTree(0);
    BrotherChildTree *root =(BrotherChildTree*)malloc(sizeof(BrotherChildTree));
    root->name=parentNode[0].name;
    root->firstchild=NULL;
    root->nextsibling=NULL;
    buildBCTree(0, root);
    char string[1000]=" ";
    printBCTree(root,string);
    //create a file
    ofstream outfile("output.txt");
    outfile<<string;
    outfile.close();
    return 0;
}
