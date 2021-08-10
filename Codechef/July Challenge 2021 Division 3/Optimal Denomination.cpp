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
ll a[MAXN];
ll pre[MAXN];
ll suf[MAXN];
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b, a%b);
}
int main() {
	int T;gi(T);while(T--){
		int n;gi(n);
		for(int i=1;i<=n;i++)gll(a[i]);
		if(n==1){
			printf("1\n");
			continue;
		}
		suf[n+1]=0;
		ll sum=0,ans=0;
		ll maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			maxn=max(a[i],maxn);
			pre[i]=gcd(pre[i-1], a[i]);
		}
		for(int i=n;i>=1;i--){
			suf[i]=gcd(suf[i+1], a[i]);
		}
		ans=sum-maxn+1;
		for(int i=1;i<=n;i++){
			ll tmp=sum-a[i];
			ll g=gcd(pre[i-1],suf[i+1]);
			ans=min(ans,tmp/g+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
