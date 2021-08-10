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
ll a[MAXN];
ll solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		gll(a[i]);
	}
	sort(a+1,a+n+1);
	ll ans=0;
	ll last=0;
	for(int i=2;i<=n;i++){
		ll x=a[i]-a[i-1];
		ans+=x;
		ll cur=last+x*(i-1);
		last=cur;
		ans-=cur;
	}
	return ans;
	
}
int main(int argc, char *argv[]) {
	int T;gi(T);
	while(T--){
		cout<<solve()<<endl;
	}
}