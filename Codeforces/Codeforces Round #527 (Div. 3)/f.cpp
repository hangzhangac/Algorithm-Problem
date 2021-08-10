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
#include <stack>
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
ll a[MAXN];
ll maxn=0;
ll sum1=0;
ll cnt=0;
ll sum[MAXN];
void dfs(int u,int f,int d){
	sum[u]=a[u];
	maxn+=1LL*d*a[u];
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f)continue;
		dfs(v,u,d+1);
		sum[u]+=sum[v];
	}
}

void dfs1(int u,int f,ll s){
	sum1=max(sum1,s);
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f)continue;
		dfs1(v,u,s-sum[v]+cnt-sum[v]);
	}
}

int main(){
	
	int n;gi(n);
	for(int i=1;i<=n;i++){
		gll(a[i]);
		cnt+=a[i];
	}
	
	for(int i=1;i<=n-1;i++){
		int u,v;
		gi2(u,v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,-1,0);
	dfs1(1,-1,maxn);
	printf("%lld\n",sum1);
	return 0;
}






