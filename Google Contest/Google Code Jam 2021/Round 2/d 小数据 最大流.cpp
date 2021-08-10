#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 210;
const int MAXM = 210 * 210;
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
char a[12][12],b[12][12];
int id(int i,int j,int m){
	return i*m+j;
}
int manh(int i,int j,int x,int y){
	return abs(i-x)+abs(j-y);
}
int main(){
	int cnt1=1;
	int T;cin>>T;
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
			add(source,id(mm[i].first,mm[i].second,m),1);
			for(int j=0;j<gg.size();j++){
				if(manh(mm[i].first,mm[i].second,gg[j].first,gg[j].second)>1)continue;
				//cout<<mm[i].first<<' '<<mm[i].second<<' '<<gg[j].first<<' '<<gg[j].second<<endl;
				add(id(mm[i].first,mm[i].second,m), id(gg[j].first,gg[j].second,m),1);
			}
		}
		for(int j=0;j<gg.size();j++){
			add(id(gg[j].first,gg[j].second,m),sink,1);
		}
		printf("Case #%d: ",cnt1++);
		
		int ans=Dinic(source,sink);
		ans=(gg.size()+mm.size()-ans);
		cout<<ans<<endl;
	}
	
	
	return 0;
}
