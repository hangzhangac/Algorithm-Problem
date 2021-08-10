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
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
map<ll,int>ms[MAXN];
int n;
ll a[MAXN];
vector<int>G[MAXN];
ll gcd(ll x,ll y){
	if(!y)return x;
	return gcd(y,x%y);
}
ll ans=0;
void dfs(int u,int f){
	ms[u][a[u]]++;
	for(auto p:ms[f]){
		ll g = gcd(a[u],p.first);
		ms[u][g]+=p.second;
		ans=(ans+p.second*g)%mod;
	}
	ans=(ans+a[u])%mod;
	for(int v:G[u]){
		if(v==f)continue;
		dfs(v,u);
	}
}
int main(){
	
	gi(n);
	for(int i=1;i<=n;i++){
		gll(a[i]);
	}
	for(int i=1;i<=n-1;i++){
		int x,y;
		gi2(x,y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	
	
	
	
	return 0;
}

