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
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=200005;
const ll mod=998244353;
const int inf=0x3f3f3f3f;


ll dp[MAXN];
ll sum[MAXN][2];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return ans;
}
int main(){
	
	int n;gi(n);
	ll inv=qpow(2, mod-2);
	sum[0][0]=inv;
	sum[0][1]=0;
	for(int i=1;i<=n;i++){
		if(i&1)
			dp[i]=sum[i-1][0];
		else dp[i]=sum[i-1][1];
		sum[i][0]=sum[i-1][0];
		sum[i][1]=sum[i-1][1];
		if(i&1){
			sum[i][1]=(sum[i][1]+dp[i])%mod;
		}
		else sum[i][0]=(sum[i][0]+dp[i])%mod;
		sum[i][1]*=inv;
		sum[i][0]*=inv;
		sum[i][1]%=mod;
		sum[i][0]%=mod;
	}
	cout<<dp[n]<<endl;
	
	
	return 0;
}























