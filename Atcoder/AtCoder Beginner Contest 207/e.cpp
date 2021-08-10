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
const int MAXN=3005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
ll dp[MAXN][MAXN];
ll a[MAXN];
//ll sum[MAXN];
int sum[MAXN][MAXN];
ll ms[MAXN][MAXN];
int main() {
	int n;
	gi(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum[i][j]=(sum[i-1][j]+a[i])%j;
		}
	}
	ms[1][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			dp[i][j]=(ms[j][sum[i][j]]+dp[i][j])%mod;
			ms[j+1][sum[i][j+1]]=(ms[j+1][sum[i][j+1]]+dp[i][j])%mod;
		}
	}
	ll cnt=0;
	for(int i=1;i<=n;i++){
		cnt=(cnt+dp[n][i])%mod;
	}
	cout<<cnt<<endl;
	
	return 0;
}
















