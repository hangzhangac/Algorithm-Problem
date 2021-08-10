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

pair<ll,ll>a[MAXN];
int main() {
	
	int n;gi(n);
	for(int i=1;i<=n;i++){
		gll2(a[i].second,a[i].first);//second is number
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	ll cnt=0;
	ll ans=0;
	while(l<=r){
		while(l<=r&&cnt<a[l].first){
			ll num=min(a[l].first-cnt,a[r].second);
			ans+=num*2;
			a[r].second-=num;
			cnt+=num;
			if(a[r].second==0)r--;
		}
		if(l>r)break;
		cnt+=a[l].second;
		ans+=a[l].second;
		l++;
	}
	cout<<ans<<endl;
	return 0;
	
}













