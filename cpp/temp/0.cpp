#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#define MaxSize 99
char calc[MaxSize],expr[MaxSize];
int i,t;
struct {
    char data[MaxSize];
    int top;
} Sym;
struct {
    double data[MaxSize];
    int top;
} Num;
double ston(char x[],int *p) {
    int j=*p-1,i;
    double n=0,m=0;
    while(x[j]>='0'&&x[j]<='9') {
        j--;
    }
    if(x[j]!='.') {
        for(i=j+1; i<=*p; i++) {
            n=10*n+(x[i]-'0');
        }
    } else {
        for(i=j+1; i<=*p; i++) {
            m=m+pow(0.1,i-j)*(x[i]-'0');
        }
        if(x[j]=='.') {
            *p=--j;
            while(x[j]>='0'&&x[j]<='9') {
                j--;
            }
            for(i=j+1; i<=*p; i++) {
                n=10*n+(x[i]-'0');
            }
        }
    }
    *p=j;
    if(x[*p]=='-') return(-(n+m));
    return(n+m);
}
void InitStack() {
    Sym.top=Num.top=-1;
}
void SymPush() {
    if(Sym.top<MaxSize-1) {
        Sym.data[++Sym.top]=calc[i--];
    } else {
        printf("Sym栈满\n");
        return;
    }
}
void SymPop() {
    if(Sym.top>=0) {
        expr[++t]=Sym.data[Sym.top--];
    } else {
        printf("Sym栈空\n");
        return;
    }
}
void NumPush() {
    if(Num.top<MaxSize-1) {
        Num.data[++Num.top]=ston(expr,&i);
    } else {
        printf("Num栈满\n");
        return;
    }
}
void NumPop() {
    if(Num.top>=0) {
        if(expr[i]!=' ') {
            switch(expr[i]) {
                case '+':
                        Num.data[Num.top-1]=Num.data[Num.top]+Num.data[Num.top-1];
                    break;
                case '-':
                        Num.data[Num.top-1]=Num.data[Num.top]-Num.data[Num.top-1];
                    break;
                case '*':
                        Num.data[Num.top-1]=Num.data[Num.top]*Num.data[Num.top-1];
                    break;
                case '/':
                        Num.data[Num.top-1]=Num.data[Num.top]/Num.data[Num.top-1];
                    break;
                case '^':
                        Num.data[Num.top-1]=pow(Num.data[Num.top],Num.data[Num.top-1]);
                    break;
            }
            Num.top--;
        }
    } else {
        printf("Num栈空\n");
        return;
    }
}
int main(void) {
    char ch;
    loop1:
    i=0,t=-1;
    system("cls");
    printf("中缀表达式：");
    InitStack(),gets(calc);
    while(calc[i]!='\0') {
        i++;
    }
    while(i>=0) {
        if(calc[i]>='0'&&calc[i]<='9') {
            while((i>=0)&&((calc[i]>='0'&&calc[i]<='9')||(calc[i]=='.'))) {
loop2:
                expr[++t]=calc[i--];
            }
            if((i>=0)&&((i==0&&calc[i]!='(')||(calc[i]=='+'||calc[i]=='-')&&!(calc[i-1]>='0'&&calc[i-1]<='9')&&calc[i-1]!=')')) goto loop2;
            expr[++t]=' ';
        } else if(calc[i]==')') {
            SymPush();
        } else if(calc[i]=='(') {
            while(Sym.data[Sym.top]!=')') {
                SymPop();
                expr[++t]=' ';
            }
            Sym.data[Sym.top--]='\0';
            i--;
        } else if(calc[i]=='+'||calc[i]=='-') {
            while(Sym.top>=0&&Sym.data[Sym.top]!=')'&&Sym.data[Sym.top]!='+'&&Sym.data[Sym.top]!='-') {
                SymPop();
                expr[++t]=' ';
            }
            SymPush();
        } else if(calc[i]=='*'||calc[i]=='/') {
            while(Sym.top>=0&&Sym.data[Sym.top]=='^') {
                SymPop();
                expr[++t]=' ';
            }
            SymPush();
        } else if(calc[i]=='^') {
            SymPush();
        } else {
            i--;
        }
    }
    while(Sym.top>=0) {
        SymPop();
        expr[++t]=' ';
    }
    expr[++t]=Sym.data[++Sym.top]='\0';
    for(i=0; i<=(t-2)/2; i++) {
        ch=expr[i];
        expr[i]=expr[(t-2)-i];
        expr[(t-2)-i]=ch;
    }
    printf("前缀表达式：%s\n",expr);
    for(i=t-2; i>=0; i--) {
        if((expr[i]>='0'&&expr[i]<='9')||((expr[i]=='+'||expr[i]=='-')&&(expr[i+1]>='0'&&expr[i+1]<='9'))) {
            NumPush();
        } else {
            NumPop();
        }
    }
    printf("运算结果为：%g\n",Num.data[0]);
    printf("Continue(y/n) ");
    ch=getch();
    switch(ch) {
        case 'y': {
                system("cls");
                goto loop1;
            }
            case 'n':
                default :
                        exit(0);
    }
    getch();
    return(0);
}