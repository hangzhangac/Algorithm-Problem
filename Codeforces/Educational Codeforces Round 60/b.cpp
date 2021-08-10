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

ll n,m,k;
ll a[MAXN];
int main(){
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		gll(a[i]);
	}
	sort(a+1,a+n+1);
	ll num=k*a[n]+a[n-1];
	ll cnt=m/(k+1);
	ll ans=num*cnt;
	cnt=m%(k+1);
	ans+=cnt*a[n];
	printf("%lld\n",ans);
	
	
	
	
	return 0;
}













