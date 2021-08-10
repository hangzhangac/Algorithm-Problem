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

ll n,k,ans=0;
bool C(ll mid){
	ll k1=k;
	if(k1<=mid){
		return true;
	}
	ll t=k/mid*mid;
	ll s;
	if(t==k){
		s=k/mid;
	}
	else s=k/mid+1;
	
	return s<=n;
}
int main(){
	
	
	gll2(n,k);
	ll l=1,r=1e18;
	while(l<=r){
		ll mid=(l+r)/2;
		if(C(mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}



























