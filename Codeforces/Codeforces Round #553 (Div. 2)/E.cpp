//去找一个点可以做多少个区间的左端点

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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n;
ll a[MAXN];
int main(){
	gi(n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		gll(a[i]);
		if(a[i]>a[i-1]){
			ans+=(a[i]-a[i-1])*(n-a[i]+1);
		}
		else if(a[i]<a[i-1]){
			ans+=(a[i-1]-a[i])*a[i];
		}
	}
	printf("%lld\n",ans);
	
	
	
	
	return 0;
}














