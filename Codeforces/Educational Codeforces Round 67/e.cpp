#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <time.h>
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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
vector<int>G[MAXN];
int a[MAXN];
int siz[MAXN];
int n;
ll ans=0;
void dfs(int u,int f){
	siz[u]=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f)continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
	ans+=siz[u];
}
void dfs1(int u,int f,ll val){
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f)continue;
		ll t=val-siz[v]+n-siz[v];
		ans=max(ans,t);
		dfs1(v,u,t);
	}
}
int main(){
	gi(n);
	for(int i=1;i<=n-1;i++){
		int x,y;
		gi2(x,y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	dfs1(1,0,ans);
	printf("%lld\n",ans);
	
	
	
	
	return 0;
}