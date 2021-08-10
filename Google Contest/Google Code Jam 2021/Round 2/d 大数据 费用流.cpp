//https://icpcgate.org/viewproblem.php?pid=1383&cid=108
//最小费用最大流模版.求最大费用最大流建图时把费用取负即可。
//无向边转换成有向边时需要拆分成两条有向边。即两次加边。
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
const int maxn = 105; //点的最大值
const int maxm = 20005; //边的最大值
const int inf = 0x3f3f3f3f;
using namespace std;
struct Edge
{
	int v, cap, cost, next;
	int from;
}p[maxm << 1];
int e, sumFlow, n, m, st, en; //sumFlow记录最大流 n是点的个数
int head[maxn], dis[maxn], pre[maxn];
bool vis[maxn];
void init()
{
	e=0;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int cap,int cost)
{
	p[e].from=u;
	p[e].v = v; p[e].cap = cap; p[e].cost = cost;
	p[e].next = head[u]; head[u] = e++;
	p[e].from=v;
	p[e].v = u; p[e].cap = 0; p[e].cost = - cost;
	p[e].next = head[v]; head[v] = e++;
}
bool spfa(int s,int t, int n)
{
	int u,v;
	queue<int>q;
	memset(vis,false,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	for(int i = 0; i <= n; ++i) 
		dis[i] = inf;
	vis[s] = true;
	dis[s] = 0;
	q.push(s);
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = head[u]; i != -1; i = p[i].next)
		{
			v = p[i].v;
			if(p[i].cap && dis[v] > dis[u] + p[i].cost)
			{
				dis[v] = dis[u] + p[i].cost;
				pre[v] = i;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=true;
				}
			}
		}
	}
	if(dis[t] == inf) 
		return false;
	return true;
}
pair<int,int> MCMF(int s,int t,int n)
{
	int flow = 0; // 总流量
	int minflow, mincost;
	mincost=0;
	while(spfa(s,t,n))
	{
		minflow = inf + 1;
		for(int i = pre[t]; i != -1; i = pre[p[i^1].v])
			if(p[i].cap < minflow)
				minflow = p[i].cap;
		flow += minflow;
		for(int i=pre[t];i!=-1;i=pre[p[i^1].v])
		{
			p[i].cap -= minflow;
			p[i^1].cap += minflow;
		}
		mincost += dis[t] * minflow;
	}
	sumFlow = flow; // 最大流
	return {mincost,sumFlow};
}
char a[12][12],b[12][12];
int id(int i,int j,int m){
	return i*m+j;
}
int manh(int i,int j,int x,int y){
	return abs(i-x)+abs(j-y);
}
int main(){
	int cnt1=1;
	int T;gi(T);
	while(T--){
		init();
		int n,m,f,s;
		cin>>n>>m>>f>>s;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int j=0;j<n;j++){
			cin>>b[j];
		}
		vector< pair<int,int> >mm,gg;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]=='M'&&b[i][j]=='G')
					mm.push_back({i,j});
				else if(a[i][j]=='G'&&b[i][j]=='M')
					gg.push_back({i,j});
			}
		}
		int source=n*m,sink=source+1;
		for(int i=0;i<mm.size();i++){
			addedge(source,id(mm[i].first,mm[i].second,m),1,0);
			for(int j=0;j<gg.size();j++){
				addedge(id(mm[i].first,mm[i].second,m), id(gg[j].first,gg[j].second,m),\
						1,min(2*f,s*manh(mm[i].first,mm[i].second,gg[j].first,gg[j].second)) );
			}
		}
		for(int j=0;j<gg.size();j++){
			addedge(id(gg[j].first,gg[j].second,m),sink,1,0);
		}
		printf("Case #%d: ",cnt1++);
		
		pair<int,int>tmp=MCMF(source,sink,n*m+1);
		int ans=tmp.first;
		int num=tmp.second;
		ans+=(max(gg.size(),mm.size())-num)*f;
		cout<<ans<<endl;
	}
	
	
	return 0;
}
