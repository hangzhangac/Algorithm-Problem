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
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e9+7;
const ll inf=100000000000000000;
const int MAX_LOG_V=17;
int n,m;
int f1[MAXN];
vector<int>book;
typedef pair<ll,int> P;
vector<P>G[MAXN];
vector<P>T[MAXN];
ll d[50][MAXN];
ll dis[MAXN];
int dep[MAXN];
int parent[MAX_LOG_V][MAXN];
int find1(int x){
	if(x==f1[x])return x;
	return f1[x]=find1(f1[x]);
}
struct Node{
	int u,v;
	ll w;
}node[MAXN];
void init(){
	gi2(n, m);
	for(int i=1;i<=n;i++){
		f1[i]=i;
	}
}
void dijkstra(int s,int id){
	priority_queue<P ,vector<P>, greater<P> >que;
	fill(d[id],d[id]+MAXN-1,inf);
	d[id][s]=0;
	que.push(P(0LL,s));
	while(!que.empty()){
		P p=que.top();que.pop();
		int v=p.second;
		if(d[id][v]<p.first)continue;
		for(int i=0;i<G[v].size();i++){
			P e=G[v][i];
			if(d[id][e.second]>d[id][v]+e.first){
				d[id][e.second]=d[id][v]+e.first;
				que.push(P(d[id][e.second],e.second));
			}
		}
	}
}

void dfs(int v,int p,int d){
	parent[0][v]=p;
	dep[v]=d;
	for(int i=0;i<T[v].size();i++){
		if(T[v][i].second!=p){
			dis[T[v][i].second]=dis[v]+T[v][i].first;
			dfs(T[v][i].second,v,d+1);
		}
	}
}
void INIT(){
	dis[1]=0;
	dfs(1,-1,0);
	for(int k=0;k+1<MAX_LOG_V;k++){
		for(int v=1;v<=n;v++){
			if(parent[k][v]<0)parent[k+1][v]=-1;
			else parent[k+1][v]=parent[k][parent[k][v]];
		}
	}
}
int LCA(int u,int v){
	if(dep[u]>dep[v])swap(u, v);
	for(int k=0;k<MAX_LOG_V;k++){
		if((dep[v]-dep[u])>>k&1){
			v=parent[k][v];
		}
	}
	if(u==v)return u;
	for(int k=MAX_LOG_V-1;k>=0;k--){
		if(parent[k][u]!=parent[k][v]){
			u=parent[k][u];
			v=parent[k][v];
		}
	}
	return parent[0][u];
}
int main(){
	init();
	for(int i=1;i<=m;i++){
		gi2(node[i].u, node[i].v);
		gll(node[i].w);
		int fx=find1(node[i].u),fy=find1(node[i].v);
		G[node[i].u].push_back(P(node[i].w,node[i].v));//原图
		G[node[i].v].push_back(P(node[i].w,node[i].u));
		if(fx==fy){
			book.push_back(i);
			continue;
		}
		f1[fx]=fy;
		T[node[i].u].push_back(P(node[i].w,node[i].v));
		T[node[i].v].push_back(P(node[i].w,node[i].u));//生成一棵树
	}
	
	INIT();
	int cnt=0;
	int num[100];
	for(int i=0;i<book.size();i++){
		int t=book[i];
		int u=node[t].u,v=node[t].v;
		num[cnt++]=u;
		num[cnt++]=v;
	}
	sort(num,num+cnt);
	cnt=unique(num, num+cnt)-num;
	for(int i=0;i<cnt;i++){
		dijkstra(num[i], i);
	}
	int q;gi(q);
	while(q--){
		int u,v;
		gi2(u, v);
		int lca=LCA(u, v);
		ll ans=dis[u]+dis[v]-2ll*dis[lca];
		for(int i=0;i<cnt;i++){
			ans=min(ans,d[i][u]+d[i][v]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}































