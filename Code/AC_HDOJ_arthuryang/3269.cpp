////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-07-03 21:29:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3269
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:324KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
//����������ֱ��˵input��
//��һ������test����
//��������N��T��N�����������T����ִ����T��
//������ʱK��S��K�����ʼ������������S�����ļ����ݴ�С,��ע�⣺���ͼ��һ���ͻ����������ˣ���Ҳ�ͱ����һ��������)
//Ȼ���Ǹ�n*n����a[i][j]��ʾi��j��a[i][j]����ÿ��
//������n�У�����n̫���Ե�������״̬��ʱ��������� 
//������ʱm��ָ�ÿ��ָ���������֣���ʾ��x̨���Դӵ�y�뿪ʼִ�����أ���ʱ��ǵݼ�����
//ִ�����غʹ������̨���Լ�סһ��Ҫͬʱ���� 
bool online[21][1001];//��������������״̬
int N,T,K,S;//n�ǵ�������T��ִ��ʱ��,K�Ƿ�����������S���ļ��Ĵ�С 
bool server[21];//��ʾ�Ƿ��Ƿ�����
int speed[21][21];//speed[i][j]��ʾ��i��j�ĵ�λʱ���ڴ���������
int m;//m��ʾ����ָ����
vector<int>v[1001];//�ڵ�i��Ҫִ����������ĵ��� 
int download[21];//����ÿ̨�������ص�������
bool start[21];//��ʼ���ص�ʱ��     
int main()
{
    int i,j,k,t,x,y,test;
    while(scanf("%d",&test)!=EOF)
    {
          while(test--)
          {                       
                scanf("%d%d",&N,&T);
                for(i=1;i<=N;i++)start[i]=0;      
                for(i=0;i<=T;i++)v[i].clear();                         
                for(i=1;i<=N;i++){server[i]=0;download[i]=0;}                         
                for(i=1;i<=N;i++)for(j=0;j<=T;j++)online[i][j]=0;
                scanf("%d%d",&K,&S);
                for(i=1;i<=K;i++){scanf("%d",&x);server[x]=1;download[x]=S;}
                for(i=1;i<=N;i++)for(j=1;j<=N;j++)scanf("%d",&speed[i][j]);
                for(i=1;i<=N;i++)
                {
                    scanf("%d",&t);
                    for(j=1;j<=t;j++)
                    {
                        scanf("%d%d",&x,&y);
                        for(k=x;k<y;k++)online[i][k]=1;             
                        }             
                    }
                scanf("%d",&m);
                for(i=1;i<=m;i++){scanf("%d%d",&x,&y);v[x].push_back(y);}
                for(i=0;i<=T;i++)
                {
                    for(j=0;j<v[i].size();j++)start[v[i][j]]=1;
                    for(x=1;x<=N;x++)
                    {
                        if(start[x]==0||online[x][i]==0)continue;                 
                        for(k=1;k<=N;k++)if(online[k][i]&&server[k])download[x]+=speed[x][k];                                                    
                        } 
                    for(x=1;x<=N;x++)if(download[x]>=S)server[x]=1;               
                    }                                 
                for(i=1;i<=N;i++)
                {
                    double tmp;
                    if(download[i]>=S)tmp=100;
                    else tmp=100.0*download[i]/S;
                    printf("%d",(int)floor(tmp));cout<<"%"<<endl;             
                    }             
                }
          }
    return 0;
    } 