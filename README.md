Four-Operation-Expression-Analysis
==================================
#include <stdio.h>

char s[100],str[100];
int num[100];
int i=0,pn=0,pc=-1;
int calc(int a,int b,char ch)
{
    switch (ch)
    {
        case '/' :return a/b;
                  break;
        case '*' :return a*b;
                  break;
        case '+' :return a+b;
                  break;
        case '-' :return a-b;
                  break;
    }
}
void put(void)
{
    pn--;
    num[pn-1] = calc(num[pn-1],num[pn],str[pc]);
    pc--;
}
int rate(char ch)
{
    switch (ch)
    {
        case '/' :
        case '*' :return 2;
                  break;
        case '+' :
        case '-' :return 1;
                  break;
        case '(' :return 0;
                  break;
        case ')' :return 0;
    }
}
int gets_num(void)
{
    int num =0 ;
    while (s[i]-48>=0 && s[i]-48<=9)
    {
        num =10*num+s[i]-48;
        i++;
    }
    return num;
}
int main(void)
{
	char ch;
	
    gets(s);
    while (s[i] != '=')
    {
    	if ((s[0] =='(') && (i==0))
    	{
    		while (s[i] == '(')
    		{
                   pc++;  str[pc] = s[i];
                   i++;   			
    		}
    	}
        num[pn] = gets_num();
        pn++;
        while (!(s[i]-48>=0 && s[i]-48<=9))
        {
            ch = s[i];
			if (ch == '=') break;
            if ( pc==-1 || rate(ch) >= rate(str[pc]) || ch == '(')
               {
                   pc++;  str[pc] = ch;
                   i++;
               }
            else
            {
                while (rate(ch) < rate(str[pc]))
                {
                        put();
                        if (	(ch == ')') 	&& 	(str[pc]=='(')	)
                        {
                            pc--;  break;
                        }
                }
                if (ch != ')')
				{
					pc++;  str[pc] = ch;
				}
                i++;
        	}
        }
    }
    
    while (pc >= 0 ) put();
    printf("%d",num[0]);
    
    return 0;
}


Exercise: Four-Operation Expression Analysis
