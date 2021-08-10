#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>
#define lson i<<1
#define rson i<<1|1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define gc(x) scanf("%c",&x)
#define gc2(x,y) scanf("%c%c",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const double PI = acos(-1.0); 
const int MAXN=100005;
const ll mod=1e7+9;
const ll llinf = (ll)(1e18) + 500;
const int inf=0x3f3f3f3f;

ll a[MAXN];
int n;
int k;
bool C(ll mid,int k){
	for(int i=n-1;i>=1;i--){
		ll dif=a[i+1]-a[i];
		if(dif<=mid)continue;
		ll lx=dif/mid;
		ll rx=1e9+1;
		ll x=1e9;
		while(lx<=rx){
			ll mm=(lx+rx)/2;
			if(mm*mid>=dif){
				x=mm;
				rx=mm-1;
			}
			else lx=mm+1;
		}
		if(k>=(x-1)){
			k-=(x-1);
		}
		else return false;
	}
	return true;
}
int main(){
	
	int T;gi(T);
	int cnt1=1;
	while(T--){
		gi2(n,k);
		ll maxn=0;
		for(int i=1;i<=n;i++){
			gll(a[i]);
			if(i>=2){
				maxn=max(maxn,a[i]-a[i-1]);
			}
		}
		if(maxn<=1){
			printf("Case #%d: %lld\n",cnt1++,maxn);
			continue;
		}
		ll l=1,r=maxn;
		
		ll ans=maxn;
		while(l<=r){
			ll mid=(l+r)/2;
			if(C(mid,k)){
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		printf("Case #%d: %lld\n",cnt1++,ans);
		
	}
	
	
	return 0;
}