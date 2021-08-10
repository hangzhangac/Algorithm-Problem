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

ll p[MAXN];
ll a[MAXN];
long long quick_pow(long long a, long long b) {
	a %= mod;
	long long res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
ll inv(int t){
	return quick_pow(t*1LL, mod-2);
}
int main(int argc, char *argv[]) {
	p[0]=1;
	for(int i=1;i<=200000;i++){
		p[i]=p[i-1]*2%mod;
	}
	
	int T;gi(T);while(T--){
		int n,k;cin>>n>>k;
		a[0]=1;
		for(int i=0;i<=n-1;i++){
			a[i+1]=(n-i)*a[i]%mod*inv(i+1)%mod;
		}
		ll ans=0;
		ll last=1;
		ll cal=0;
		if(n&1){
			for(int i=1;i<n;i+=2){
				cal=(cal+a[i])%mod;
				
			}
			cal=((quick_pow(2, n)-cal)%mod+mod)%mod;
			for(int i=k;i>=1;i--){
				last=(last*cal)%mod;
			}
			ans=(ans+last)%mod;
		}
		else{
			
			for(int i=0;i<=n-2;i+=2){
				cal=(cal+a[i])%mod;
			}
			
			for(int i=k;i>=1;i--){
				ans+=last*quick_pow(2,1LL*n*(i-1));
				ans%=mod;
				last=(last*cal)%mod;
			}
			ans=(ans+last)%mod;
		}
		cout<<ans<<endl;
	}
}