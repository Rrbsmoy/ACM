/* ***********************************************
Author        :kuangbin
Created Time  :2013-9-5 9:45:17
File Name     :F:\2013ACM��ϰ\ר��ѧϰ\LCA\POJ1330_3.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
/*
 * POJ 1330
 * LCA �����㷨
 */
const int MAXN = 10010;
const int DEG = 20;

struct Edge
{
    int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
int fa[MAXN][DEG];//fa[i][j]��ʾ���i�ĵ�2^j������
int deg[MAXN];//�������

void BFS(int root)
{
    queue<int>que;
    deg[root] = 0;
    fa[root][0] = root;
    que.push(root);
    while(!que.empty())
    {
        int tmp = que.front();
        que.pop();
        for(int i = 1;i < DEG;i++)
            fa[tmp][i] = fa[fa[tmp][i-1]][i-1];
        for(int i = head[tmp]; i != -1;i = edge[i].next)
        {
            int v = edge[i].to;
            if(v == fa[tmp][0])continue;
            deg[v] = deg[tmp] + 1;
            fa[v][0] = tmp;
            que.push(v);
        }

    }
}
int LCA(int u,int v)
{
    if(deg[u] > deg[v])swap(u,v);
    int hu = deg[u], hv = deg[v];
    int tu = u, tv = v;
    for(int det = hv-hu, i = 0; det ;det>>=1, i++)
        if(det&1)
            tv = fa[tv][i];
    if(tu == tv)return tu;
    for(int i = DEG-1; i >= 0; i--)
    {
        if(fa[tu][i] == fa[tv][i])
            continue;
        tu = fa[tu][i];
        tv = fa[tv][i];
    }
    return fa[tu][0];
}
bool flag[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int n;
    int u,v;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        init();
        memset(flag,false,sizeof(flag));
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
            flag[v] = true;
        }
        int root;
        for(int i = 1;i <= n;i++)
            if(!flag[i])
            {
                root = i;
                break;
            }
        BFS(root);
        scanf("%d%d",&u,&v);
        printf("%d\n",LCA(u,v));
    }
    return 0;
}
