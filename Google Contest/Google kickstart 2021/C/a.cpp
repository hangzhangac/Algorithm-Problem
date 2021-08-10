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
char s[MAXN];
int main(){
	int T;int cnt1=1;gi(T);
	while(T--){
		int n,k;
		cin>>n>>k;
		cin>>(s+1);
		a[0]=1;
		for(int i=1;i<=n;i++){
			a[i]=(a[i-1]*k)%mod;
		}
		ll ans=0;
		int q=n/2;
		if(n&1)q++;
		for(int i=1;i<=q;i++){
			ll t=s[i]-'a';
			ans+=(t*a[q-i])%mod;
			ans%=mod;
		}
		int flag=1;
		int j=n/2+1;
		if(n&1)j++;
		int i=n/2;
		while(j<=n&&s[j]==s[i]){
			j++;i--;
		}
		if(j<=n&&s[j]>s[i]){
			flag=0;
		}
		if(!flag&&n!=1)ans=(ans+1)%mod;
		printf("Case #%d: ",cnt1++);
		printf("%lld\n",ans);
	}
	return 0;
}