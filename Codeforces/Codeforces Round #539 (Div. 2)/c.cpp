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
ll a[MAXN];
ll sum[MAXN];
map<ll,int>ms[2];
int main(){
	
	int n;
	gi(n);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		gll(a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	ll ans=0;
	ms[0][0]++;
	for(int i=1;i<=n;i++){
		int t=i&1;
		ans+=ms[t][sum[i]]++;
	}
	printf("%lld\n",ans);
	
	
	
	
	return 0;
}


















