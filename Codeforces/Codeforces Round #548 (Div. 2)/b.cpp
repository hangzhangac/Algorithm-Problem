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
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll a[MAXN];
int main(){
	
	int n;
	gi(n);
	for(int i=1;i<=n;i++){
		gll(a[i]);
	}
	ll ans=a[n];
	ll maxn=a[n];
	for(int i=n-1;i>=1;i--){
		ll t=min(maxn-1,a[i]);
		if(t<=0)break;
		ans+=t;
		maxn=t;
	}
	printf("%lld\n",ans);
	
	
	
	
	
	
	
	return 0;
}












