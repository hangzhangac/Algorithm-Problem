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
vector< pair<ll,ll> >q;
set<ll>s;
int main(){
	
	int T;int cnt1=1;gi(T);
	while(T--){
		ll n;
		cin>>n;
		q.clear();s.clear();
		n*=2;
		for(ll i=1;i*i<=n;i++){
			if(n%i==0){
				q.push_back({i,n/i});
				if(n/i!=i){
					q.push_back({n/i,i});
				}
			}
		}
		ll cnt=0;
		for(auto v:q){
			ll a=v.first,b=v.second;
			ll i=b-1;
			a-=i;
			if(a%2==0&&a/2>=1){
				cnt++;
			}
		}
		
		
		printf("Case #%d: ",cnt1++);
		printf("%lld\n",cnt);
		
	}

	return 0;
}