////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-06-22 13:49:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:328KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

#define MAX 10
char maze[MAX][MAX];
int N,M,T;
int dx,dy;//�Թ����� 
bool escape;//�Ƿ��н� 

void dfs(int sx,int sy,int t)
{
    if(sx<=0 || sx>N || sy<=0 || sy>M)//��ֹԽ�� 
 return;
    if(escape==true || (sx==dx && sy==dy && t==0))//�������� 
 {
        escape=true;
        return;
    }
    
    int temp=t-abs(sx-dx)-abs(sy-dy);
    if(temp<0 || temp&1)//��ż�Լ�֦ 
 return;
    
    maze[sx][sy]='X';//�߹���·������� 
    //���� 
 if(maze[sx+1][sy] != 'X'){
        dfs(sx+1,sy,t-1);
        if(escape) return;}
    if(maze[sx][sy+1] != 'X'){
        dfs(sx,sy+1,t-1);
        if(escape) return;}
    if(maze[sx-1][sy] != 'X'){
        dfs(sx-1,sy,t-1);
        if(escape) return;}
    if(maze[sx][sy-1] != 'X'){
        dfs(sx,sy-1,t-1);
        if(escape) return;}
    maze[sx][sy]='.';//���ݣ�����ȡ����� 
}

int main()
{
    int sx,sy;//�Թ���� 
 while(cin >> N >> M >> T)
    {
        if(N==0 && M==0 && T==0)
            break;
        
        int wall=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                cin >> maze[i][j];
                if(maze[i][j]=='X')
                    wall++;
                if(maze[i][j]=='S'){//�ҳ��Թ���� 
 sx=i;sy=j;}
                else if(maze[i][j]=='D'){
                    dx=i;dy=j;}
            }
        }
        
        if(N*M-wall<=T){//��֦����֮һ�����߷������ȹ涨ʱ�仹�� 
 cout << "NO\n";
            continue;}
        
        escape=false;
        dfs(sx,sy,T);//�ص� 
 if(escape)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}