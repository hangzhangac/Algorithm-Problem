#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <time.h>
#include <map>
#include <set>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int root=1;
int belong[MAXN],tot;
int dfn[MAXN],low[MAXN],num;
int stack[MAXN],top;
bool instack[MAXN];
vector<int>G[MAXN];
void tarjan(int u,int fa){
	
	dfn[u]=low[u]=++num;
	stack[++top]=u;
	instack[u]=true;
	int tto;
	for(auto v:G[u]){
		if(v==fa)continue;
		if(!dfn[tto=v]){
			tarjan(tto,u);
			low[u]=min(low[u],low[tto]);
		}
		else low[u]=min(dfn[tto],low[u]);
	}
	if(low[u]==dfn[u]){
		int tan=stack[top];
		++tot;
		while(tan!=u){
			belong[tan]=tot;
			instack[tan]=false;
			tan=stack[--top];
		}
		--top;
		belong[u]=tot;
		instack[u]=false;
	}
	return ;
}
int val[MAXN];
int book[MAXN];
ll num1[MAXN],g[MAXN],f[MAXN];
int uu[MAXN],vv[MAXN],siz[MAXN];
bool flag[MAXN];
void dfs(int u,int ff){
	ll s=0,cnt=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==ff)continue;
		dfs(v,u);
		if(flag[v]){
			f[u]+=f[v];
			cnt++;
		}
		else{
			s=max(s,g[v]);
		}
	}
	if(siz[u]==1&&cnt==0){
		flag[u]=0;
		f[u]=0;
		g[u]=s+num1[u];
	}
	else{
		flag[u]=1;
		g[u]=f[u]+num1[u];
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];if(v==ff)continue;
			g[u]=max(g[u],f[u]-f[v]+g[v]+num1[u]);
		}
		f[u]+=num1[u];
	}
	return;
}
int main(){
	int m, u, v, n;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)scanf("%d",&val[i]);
	for(int i=0; i<m; i++){
		cin>>u>>v;
		uu[i]=u,vv[i]=v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int root;scanf("%d",&root);
	tarjan(1, -1);
	root=belong[root];
	for(int i=1;i<=n;i++){
		G[i].clear();
		num1[belong[i]]+=val[i];
		siz[belong[i]]++;
	}
	n=0;
	for(int i=0;i<m;i++){
		int u=uu[i],v=vv[i];
		n=max(n,max(belong[u],belong[v]));
		if(belong[v]!=belong[u]){
			G[belong[u]].push_back(belong[v]);
			G[belong[v]].push_back(belong[u]);
		}
	}
	for(int i=1;i<=n;i++){
		sort(G[i].begin(),G[i].end());
		G[i].erase(unique(G[i].begin(),G[i].end()), G[i].end());
	}
	dfs(root,-1);
	cout<<g[root]<<endl;
	return 0;
}
/*
6 6
1 2
2 3
3 4
4 5
5 6
4 6
*/