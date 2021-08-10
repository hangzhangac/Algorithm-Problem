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
vector< pair<ll,int> >v;
ll ans[MAXN];
int main() {
	
	int n,q;
	gi(n);gi(q);
	for(int i=1;i<=n;i++){
		gll(a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=q;i++){
		ll k;
		cin>>k;
		v.push_back({k,i});
	}
	sort(v.begin(),v.end());
	a[0]=0;
	a[n+1]=2e18;
	int k=0;
	ll cnt=0;
	for(int i=1;i<=n+1;i++){
		if(a[i]==a[i-1])continue;
		ll tmp=cnt;
		cnt+=a[i]-a[i-1]-1;
		while(k<v.size()&&v[k].first<=cnt){
			ans[v[k].second]=a[i-1]+v[k].first-tmp;
			k++;
		}
		
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	
	
	
	
	
	
	return 0;
}





















