#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int main(){
	
	ll n,q;
	cin>>n>>q;
	while(q--){
		ll x,y;
		gll2(x,y);
		ll ans=0;
		if(n&1){
			ll t=n/2;//第二行
			ll l2=t*2+1;
			if((x+y)%2==0){
				ll x1=x-1;
				ans=x1/2*l2;
				if(x1&1){
					ans+=t+1;
				}
				if(x&1){
					ans+=(y+1)/2;
				}
				else{
					ans+=(y)/2;
				}
			}
			else{
				ans=n*n/2+1;
				ll x1=x-1;
				ans+=x1/2*l2;
				if(x1&1){
					ans+=t;
				}
				if(x&1){
					ans+=(y)/2;
				}
				else{
					ans+=(y+1)/2;
				}
			}
		}
		else{
			int t=n/2;
			if((x+y)%2==0){
				//每一行放n/2
				ans=(x-1)*t;
				ans+=(y+1)/2;
			}
			else{
				ans=(x-1)*t;
				ans+=(1LL*n*n+1)/2;
				ans+=(y+1)/2;
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
