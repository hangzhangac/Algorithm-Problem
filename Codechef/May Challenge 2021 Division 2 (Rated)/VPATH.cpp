#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
int n;
vector<int>G[MAXN];
int dp[MAXN];
ll ans=0;
void dfs(int u,int f){
	ll sum=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f)continue;
		dfs(v,u);
		ans+=(2*(sum*dp[v])+dp[v])%mod;
		sum+=dp[v];
		sum%=mod;
	}
	dp[u]=(2*sum+1)%mod;
}
int main(int argc, char *argv[]) {
	
	int T;gi(T);while(T--){
		gi(n);
		ans=0;
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			gi2(u, v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,0);
		ans=(ans+n)%mod;
		cout<<ans<<endl;
	}
	
}