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
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
vector<int>G[MAXN];
ll ans[MAXN];
ll dp[MAXN];
int cnt=0;
bool cmp(ll a,ll b){
	return a>b;
}
void dfs(int u,int f){
	ll res=1;
	for(auto &v:G[u]){
		if(v==f)continue;
		dfs(v,u);
	}
	cnt=0;
	for(auto &v:G[u]){
		if(v==f)continue;
		ans[cnt++]=dp[v];
	}
	sort(ans, ans+cnt,cmp);
	
	for(int i=0;i<cnt;i++){
		res+=ans[i]*(i+1);
	}
	dp[u]=res;
}
int main(){
	
	int T;gi(T);while(T--){
		cnt=0;
		
		int n,x;
		gi2(n,x);
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			gi2(u, v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,0);
		cout<<dp[1]%mod*x%mod<<endl;
		
	}
	
	return 0;
}


















