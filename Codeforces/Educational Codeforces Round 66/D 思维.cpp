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
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n,k;
ll a[MAXN];
ll sum[MAXN];
ll ans=0;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	int n,k;
	gi2(n,k);
	k--;
	for(int i=1;i<=n;i++){
		gll(a[i]);
		ans+=a[i];
	}
	for(int i=n;i>=1;i--){
		sum[i]=sum[i+1]+a[i];
	}
	for(int i=1;i<=n-1;i++){
		sum[i]=sum[i+1];
	}
	sort(sum+1,sum+n,cmp);
	for(int i=1;i<=k;i++){
		ans+=sum[i];
	}
	printf("%lld\n",ans);
	
	
	
	
	
	
	
	
	return 0;
}







