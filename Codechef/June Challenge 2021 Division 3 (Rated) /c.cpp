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
long long quick_pow(long long a, long long b, long long mod) {
	a %= mod;
	long long res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int main(){
	
	int T;gi(T);
	while(T--){
		ll n,m;
		cin>>n>>m;
		ll ans=quick_pow(2, n, mod);
		ans=(ans-1+mod)%mod;
		ans=quick_pow(ans, m, mod);
		cout<<ans<<endl;
	}
	return 0;
}



