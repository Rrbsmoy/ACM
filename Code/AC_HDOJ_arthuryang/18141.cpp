////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-13 23:03:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1814
////Problem Title: 
////Run result: Accept
////Run time:2531MS
////Run memory:2344KB
//////////////////System Comment End//////////////////
/*
HDU 1814
����ֵ�����С�Ľ�
C++ 2652ms 2316K

*/
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=16010;
const int MAXM=100000;
struct Node
{
    int a,b,pre,next;
}E[MAXM],E2[MAXM];
int _n,n,m;
int V[MAXN],ST[MAXN][2],Q[MAXN],Q2[MAXN],vst[MAXN];
bool res_ex;
void init_d()
{
    for(int i=0;i<n;i++)
      E[i].a=E[i].pre=E[i].next=E2[i].a=E2[i].pre=E2[i].next=i;
    m=n;
}
void add_edge(int a,int b)
{
    E[m].a=a;E[m].b=b;E[m].pre=E[a].pre;E[m].next=a;E[a].pre=m;E[E[m].pre].next=m;
    E2[m].a=b;E2[m].b=a;E2[m].pre=E2[b].pre;E2[m].next=b;E2[b].pre=m;E2[E2[m].pre].next=m;
    m++;
}
void solve()
{//1
    for(int i=0;i<n;i++)
    {
        V[i]=0;
        vst[i]=0;
    }
    res_ex=1;
    int i,i1,i2,j,k,front,rear,front2,rear2;
    int len;
    bool ff;
    for(int _i=0;_i<_n;_i++)
    {//2
        if(V[_i<<1]==1||V[(_i<<1)+1]==1)continue;//��һ��δȷ���ĵ�
        i=_i<<1;len=0;
        if(!V[i])
        {//3
            ST[len][0]=i;
            ST[len++][1]=1;
            if(!V[i^1])
            {
                ST[len][0]=i^1;
                ST[len++][1]=2;
            }
            Q[front=rear=0]=i;
            vst[i]=i1=n+i;
            Q2[front2=rear2=0]=i^1;
            vst[i^1]=i2=(n<<1)+i;
            ff=1;
            for(;front<=rear;front++)
            {//4
                j=Q[front];
                for(int p=E[j].next;p!=j;p=E[p].next)
                {//5
                    k=E[p].b;
                    if(V[k]==2||vst[k]==i2||V[k^1]==1||vst[k^1]==i1)
                    {ff=0;break;}
                    if(vst[k]!=i1)
                    {//6
                        Q[++rear]=k;vst[k]=i1;
                        if(!V[k])
                        {
                            ST[len][0]=k;
                            ST[len++][1]=1;
                        }
                    }//6
                    if(vst[k^1]!=i2)
                    {//6
                        Q2[++rear2]=k^1;vst[k^1]=i2;
                        if(!V[k])
                        {
                            ST[len][0]=k^1;
                            ST[len++][1]=2;
                        }
                    }//6
                }//5
                if(!ff)break;
            }//4
            if(ff)
            {//4
                for(;front2<=rear2;front2++)
                {//5
                    j=Q2[front2];
                    for(int p=E2[j].next;p!=j;p=E2[p].next)
                    {//6
                        k=E2[p].b;
                        if(V[k]==1||vst[k]==i1)
                        {ff=0;break;}
                        if(vst[k]!=i2)
                        {
                            vst[k]=i2;Q2[++rear]=k;
                            if(!V[k])
                            {
                                ST[len][0]=k;
                                ST[len++][1]=2;
                            }
                        }
                    }//6
                    if(!ff)break;
                }//5
                if(ff)
                {
                    for(int j=0;j<len;j++)V[ST[j][0]]=ST[j][1];
                    continue;
                }
            }//4
        }//3
        i=(_i<<1)+1;len=0;

//********************************************
//������κ�������ȫһ���ģ����Ը��ơ�����Ҫ��֤����д��
//********************************************
        if(!V[i])
        {//3
            ST[len][0]=i;
            ST[len++][1]=1;
            if(!V[i^1])
            {
                ST[len][0]=i^1;
                ST[len++][1]=2;
            }
            Q[front=rear=0]=i;
            vst[i]=i1=n+i;
            Q2[front2=rear2=0]=i^1;
            vst[i^1]=i2=(n<<1)+i;
            ff=1;
            for(;front<=rear;front++)
            {//4
                j=Q[front];
                for(int p=E[j].next;p!=j;p=E[p].next)
                {//5
                    k=E[p].b;
                    if(V[k]==2||vst[k]==i2||V[k^1]==1||vst[k^1]==i1)
                    {ff=0;break;}
                    if(vst[k]!=i1)
                    {//6
                        Q[++rear]=k;vst[k]=i1;
                        if(!V[k])
                        {
                            ST[len][0]=k;
                            ST[len++][1]=1;
                        }
                    }//6
                    if(vst[k^1]!=i2)
                    {//6
                        Q2[++rear2]=k^1;vst[k^1]=i2;
                        if(!V[k])
                        {
                            ST[len][0]=k^1;
                            ST[len++][1]=2;
                        }
                    }//6
                }//5
                if(!ff)break;
            }//4
            if(ff)
            {//4
                for(;front2<=rear2;front2++)
                {//5
                    j=Q2[front2];
                    for(int p=E2[j].next;p!=j;p=E2[p].next)
                    {//6
                        k=E2[p].b;
                        if(V[k]==1||vst[k]==i1)
                        {ff=0;break;}
                        if(vst[k]!=i2)
                        {
                            vst[k]=i2;Q2[++rear]=k;
                            if(!V[k])
                            {
                                ST[len][0]=k;
                                ST[len++][1]=2;
                            }
                        }
                    }//6
                    if(!ff)break;
                }//5
                if(ff)
                {
                    for(int j=0;j<len;j++)V[ST[j][0]]=ST[j][1];
                    continue;
                }
            }//4
        }//3
//**************************************************************
        if(V[_i<<1]+V[(_i<<1)+1]!=3){res_ex=0;break;}
    }//2
}//1
//��ı�ű����0��ʼ��2*i��2*i+1��һ��sat
int main()
{
    int M;
    int x,y;
    while(scanf("%d%d",&_n,&M)!=EOF)
    {
        n=_n<<1;
        init_d();
        while(M--)
        {
            scanf("%d%d",&x,&y);
            x--;
            y--;
            if(x!=(y^1))
            {
                add_edge(x,y^1);
                add_edge(y,x^1);
            }
        }
        solve();
        if(res_ex)
        {
            for(int i=0;i<n;i++)//VΪ0Ϊ��ȷ����1Ϊȷ��ѡ��2Ϊȷ����ѡ��
            if(V[i]==1)printf("%d\n",i+1);
        }
        else printf("NIE\n");
    }
    return 0;
}