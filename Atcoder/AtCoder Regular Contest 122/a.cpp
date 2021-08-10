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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
ll dp[MAXN][2];
ll a[MAXN];
int f[MAXN];
int main() {

	int n;
	gi(n);
	for(int i=1;i<=n;i++)gll(a[i]);
	dp[1][0]=1;
	for(int i=2;i<=n;i++){
		dp[i][0]=(dp[i-1][1]+dp[i-1][0])%mod;
		dp[i][1]=(dp[i-1][0])%mod;
	}
	ll ans=0;
	ans=(dp[n][1]+dp[n][0])*a[1]%mod;
	for(int i=2;i<=n;i++){
		int l=i-1;
		ll num=(dp[l][0]+dp[l][1])%mod;
		int r=n-i+1;
		num=(num*(dp[r][0]+dp[r][1]))%mod;
		ans=(ans+num*a[i])%mod;
		
		num=dp[l][0]*dp[r][0]%mod;
		ans=((ans-num*a[i])%mod+mod)%mod;
	}
	cout<<ans<<endl;

	return 0;
}