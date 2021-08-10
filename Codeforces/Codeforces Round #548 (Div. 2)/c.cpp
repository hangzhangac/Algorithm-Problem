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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
typedef  pair<int,int>  P;
vector<int>G[MAXN];
int book[MAXN];
int n,k;
int ans=0;
void dfs(int u){
	ans++;
	book[u]=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(book[v])continue;
		dfs(v);
	}
}

int main(){
	
	gi2(n,k);
	for(int i=1;i<=n-1;i++){
		int u,v,x;
		gi3(u,v,x);
		if(x==1)continue;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ll cnt=1;
	for(int i=1;i<=k;i++){
		cnt=cnt*n%mod;
	}
	for(int i=1;i<=n;i++){
		ans=0;
		if(book[i])continue;
		dfs(i);
		ll t=1;
		for(int j=1;j<=k;j++){
			t=t*ans%mod;
		}
		cnt=((cnt-t)%mod+mod)%mod;
	}
	printf("%lld\n",(cnt+mod)%mod);
	return 0;
}












