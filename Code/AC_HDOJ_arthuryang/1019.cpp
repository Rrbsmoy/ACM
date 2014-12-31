////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-13 14:05:25
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1019
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}    
int main()
{
    int T;
    int n,a,b,i;
    int cnt;
    scanf("%u",&T);
    while(T--)
    {
        scanf("%d",&n);
        cnt=a=1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&b);
            cnt=a/gcd(a,b)*b;//��һ�£��ȳ���ˣ����������� 
            a=cnt;
        } 
        printf("%d\n",cnt);   
    }    
    return 0;
}