#include <stdio.h>
#include <stdlib.h>
#define null 0
#define max 100
typedef struct  /*定义字符栈*/
{
   char sk[max];
   int top;
}seqstack;
typedef struct  /*定义数据栈*/
{
   int sk[max];
   int top;
}stack;
void push(seqstack *s,char x) /*符号进栈*/
{
   if(s->top==max-1)
     printf("符号栈满！\n");

   s->top++;
   s->sk[s->top]=x;
}
void spush(stack *s,double x) /*数据进栈*/
{
  if(s->top==max-1)
    printf("数据栈满！\n");
    s->top++;
    s->sk[s->top]=x;
}
char pop(seqstack *s ,char c) /*符号出栈*/
{
  if(s->top==-1)
   {printf("没有剩余符号！\n");
    return 0;
   }
  else
  {
     c=s->sk[s->top];
     s->top--;
     return c;
   }
}
int spop(stack *s ,double c) /*数据出栈*/
{
  if(s->top==-1)
   {
     printf("没有剩余数字！\n");
     return 0;
   }
  else
  {
    c=s->sk[s->top];
    s->top--;
    return c;
  }
}
int pp(char c) /*判断字符*/
{
  switch(c)
  {
    case '#':return 0;break;
    case '+':return 2;break;
    case '-':return 2;break;
    case '*':return 3;break;
    case '/':return 3;break;
    case '(':return 1;break;
    case ')':return 4;break;
    default:return 9;break;
  }
}
int yunsuan(double a,char b,double c) /*运算*/
{
  switch(b)
   {


     case '+':return a+c;break;
     case '-':return a-c;break;
     case '*':return a*c;break;
     case '/':return a/c;break;
     default:if(c==0) return 0; //除数为0
   }
   return 0;

}
char bijiao(seqstack *s,char c) /*比较优先级*/
{
    int m,n;
    char w;

    m=pp(c);
    w=s->sk[s->top];
    n=pp(w);
    if(m>n)
        return '1';
    else
        return '0';
}
int main()
{
  int x;
  int q=0,w=0;
  int p
  ; /*标示变量*/
  char ch,th='\0',d='\0';
  seqstack *h;
    h=(seqstack*)malloc(sizeof(seqstack));

    h->top=-1;
  stack *g;
    g=(stack*)malloc(sizeof(stack));

    g->top=-1;
    push(h,'#');
    printf("请输入要计算的式子\n");
    ch=getchar();
   while(ch!='\n')
   {

    if(pp(ch)==9)
   {
       spush(g,ch-48);

   }
   if(pp(ch)==1)
   {
       push(h,ch);
       p=0;
   }
   if(pp(ch)==4)//括号内运算
   {
      while(pp(h->sk[h->top])!=1)
      {
         q=spop(g,q);
         w=spop(g,w);
         th=pop(h,th);
         spush(g,yunsuan(w,th,q));
      }
      d=pop(h,d);
      p=0;
   }
   if(pp(ch)!=9&& pp(ch)!=1&& pp(ch)!=4)
   {
       switch(bijiao(h,ch))
       {
        case '1':push(h,ch);p=0;break;
        case '0':
             while(pp(h->sk[h->top])!=pp(ch))
             {
               q=spop(g,q);
               w=spop(g,w);
               th=pop(h,th);
               spush(g,yunsuan(w,th,q));
             }
             push(h,ch); p=0;break;
        default:p=0;break;
       }

   }
   ch=getchar();
   }

   while(ch=='\n'&& h->sk[h->top]!='#')//...
   {
     q=spop(g,q);
     w=spop(g,w);
     th=pop(h,th);
     x=yunsuan(w,th,q);
     spush(g,x);

   }

   printf("结果为: %d\n",g->sk[g->top]);
   return 0;
}
