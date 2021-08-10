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

int main() {
	int T;gi(T);
	while(T--){
		ll n,x,t;
		cin>>n>>x>>t;
		ll s=t/x;
		int flag=0;
		if(s>n-1){
			flag=1;
			s=n-1;
		}
		ll ans=(1+s)*s/2;
		if(flag==0)
			ans+=(n-s-1)*s;
		cout<<ans<<endl;
	}
	return 0;
	
}