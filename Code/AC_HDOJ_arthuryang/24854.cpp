////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-05-21 14:34:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2485
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:268KB
//////////////////System Comment End//////////////////

//hdu 2485 Destroying the bus stations
//����(��������)
//û�з����

#include <stdio.h>
#include <string.h>


#define N 55
#define INF 1<<30
#define eps 1e-5

int n_node, n_edge, limit, len;//len ��¼�������·�ĳ���
int limit_depth;    //��¼��ǰ�������Ƶ����
bool success;       //����Ƿ��ҵ���


int que[N], road[N][N]; //que����ʱ�õĶ���,road(i, j)��ʾ���Ϊiʱ�Ĺ��ѵ����·
int pre[N]; //pre��¼����·��
int end[4005], head[N], next[4005], tot;  //�ڽӱ�
bool del[N];    //��¼��ɾ�ĵ�

void add_edge(int from, int to)     //add edge into adjacency list
{
    end[++tot] = to;
    next[tot] = head[from];
    head[from] = tot;
}

bool bfs()   //breadth first search
{
    for(int i = 1; i <= n_node; ++i)
        pre[i] = 0;
    int top = 0, tail = 0;
    que[++top] = 1;
    while(tail < top)
    {
        int now = que[++tail];
        for(int i = head[now]; i != -1; i = next[i])
        {
            int point = end[i];
            if(del[point] == false && pre[point] == 0)
            {
                pre[point] = now;       //��¼����·��
                que[++top] = point;         //���
                if(point == n_node)
                    return true;
            }
        }
    }
    return false;
}

void dfs(int dep)   //depth first search
{
    if(success == true)
        return;
    bool find = bfs();   //���������

    if(find == false)      //�Ҳ������·��
    {
        success = true;
        return;
    }
    int cnt = 0;    //��¼���·�ĳ���
    //que[top]Ϊ���һ���ڵ�,i == 1ʱ������ѭ��������û�а��������յ�
    for(int i = pre[n_node]; i != 1; i = pre[i])
        road[dep][cnt++] = i;
    if(cnt >= limit)
    {
        success = true;
        return;
    }

    if(dep > limit_depth)   //��ȴ������Ƶ���ȣ�Ҳ���ǲ�����ɾ����
        return;

    //������ɾ���һ��(i=cnt-2�ĵ�)�͵�һ���ڵ�(i=0�ĵ�)
    for(int i = cnt - 1; i >= 0; --i)
    {
        int del_point = road[dep][i];
        del[del_point] = true;
        dfs(dep + 1);
        del[del_point] = false;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    bool have[N][N];
    while(scanf("%d%d%d", &n_node, &n_edge, &limit), n_node || n_edge || limit)
    {
        tot = 0;    //�ڽӱ��±�
        memset(have, false, sizeof(have));

        for(int i = 0; i <= n_node; ++i)    //��ʼ��
        {
            head[i] = -1;
            del[i] = false;
        }

        for(int i = 0; i < n_edge; ++i)
        {
            int from, to;
            scanf("%d%d", &from, &to);
            if(have[from][to] == false)
            {
                have[from][to] = true;
                add_edge(from, to);
            }
        }

        int m = n_node - 2;
        success = false;
        //���������������������Ϊi�����������ɾi����
        for(int i = 0; i <= m; ++i)
        {
            limit_depth = i;
            dfs(1);
            if(success == true)
                break;
        }
        printf("%d\n", limit_depth);
    }
    return 0;
}