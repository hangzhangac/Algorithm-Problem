#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 710;
const int MAXM = 710*710*2;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int v, f;
	int next;
}edge[MAXM];

int cnt;

int first[MAXN], level[MAXN];

void init()
{
	cnt = 0;
	memset(first, -1, sizeof(first));
}

void add(int u, int v, int f)
{
	edge[cnt].v = v, edge[cnt].f = f;
	edge[cnt].next = first[u], first[u] = cnt++;
	edge[cnt].v = u, edge[cnt].f = 0;  //增加一条反向弧，容量为0
	edge[cnt].next = first[v], first[v] = cnt++;
}

int bfs(int s, int t) //构建层次网络
{
	memset(level, 0, sizeof(level));
	level[s] = 1;
	queue<int>q;
	q.push(s);
	while (!q.empty())
	{
		int x = q.front();q.pop();
		if (x == t) return 1;
		for (int e = first[x]; e != -1; e = edge[e].next)
		{
			int v = edge[e].v, f = edge[e].f;
			if (!level[v] && f)
			{
				level[v] = level[x] + 1;
				q.push(v);
			}
		}
	}
	return 0;
}

int dfs(int u, int maxf, int t)
{
	if (u == t) return maxf;
	int ret = 0;
	for (int e = first[u]; e != -1; e = edge[e].next)
	{
		int v = edge[e].v, f = edge[e].f;
		if (level[u] + 1 == level[v] && f)
		{
			int Min = min(maxf - ret, f);
			f = dfs(v, Min, t);
			edge[e].f -= f;
			edge[e^1].f += f;
			ret += f;
			if (ret == maxf) return ret;
		}
	}
	if(!ret)level[u] = 0;
	return ret;
}

int Dinic(int s, int t) //Dinic
{
	int ans = 0;
	while (bfs(s, t)) ans += dfs(s, INF, t);
	return ans;
}
int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int main(){
	
	int T=1;while(T--){
		init();
		int n,m,t;
		cin>>n>>m>>t;
		int source=0,sink=2*(n+m+t)+1;
		for(int i=1;i<=t;i++){
			cin>>a[i]>>b[i]>>c[i]>>d[i];
			add(2*n+i, 2*n+i+t, 1);
			for(int r=a[i];r<=c[i];r++){
				add(r+n, 2*n+i, 1);
			}
			for(int co=b[i];co<=d[i];co++){
				add(2*n+i+t, 2*n+2*t+co, 1);
			}
		}
		for(int i=1;i<=n;i++){
			add(source, i, 1);
			add(i, i+n, 1);
		}
		for(int i=1;i<=m;i++){
			add(2*n+2*t+i, 2*n+2*t+i+m, 1);
			add(2*n+2*t+i+m, sink, 1);
		}
		cout<<Dinic(source, sink)<<endl;
	}
	
	return 0;
}
















