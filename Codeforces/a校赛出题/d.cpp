#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <time.h>
#include <map>
#include <set>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll a[MAXN],sum[MAXN],ss[MAXN];
int n;
ll k;
bool C(int mid,ll t){
	ll x=sum[mid+1]-1LL*(n-mid)*a[mid];
	if(t>=x)return true;
	return false;
}
int main(){
	gi(n);gll(k);
	for(int i=1;i<=n;i++){
		gll(a[i]);
	}
	sort(a+1,a+n+1);
	
	for(int i=n;i>=1;i--){
		sum[i]=sum[i+1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ss[i]=ss[i-1]+a[i];
	}
	ll minn=a[n]-a[1];
	
	for(int i=1;i<=n;i++){
		ll sum1=a[i]*(i-1)-ss[i-1];
		ll t=k-sum1;
		if(t<0)break;
		int l=i,r=n;
		int id=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(C(mid,t)){
				id=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		minn=min(minn,a[id]-a[i]);
	}
	printf("%lld\n",minn);
	
	
	
	return 0;
}






