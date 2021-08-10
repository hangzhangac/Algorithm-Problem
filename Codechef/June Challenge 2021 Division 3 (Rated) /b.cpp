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

int main(){
	
	int T;gi(T);
	while(T--){
		ll D,d,P,Q;
		cin>>D>>d>>P>>Q;
		ll ans=D*P;
		ll t=(D-1)/d-1;
		ans+=(0+t)*(t+1)/2*Q*d;
		ans+=(D-(t+1)*d)*Q*(t+1);
		cout<<ans<<endl;
	}
	
	
	
	return 0;
}


