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
int a[MAXN];
int sum[MAXN];
int main(){
	
	int T;
	gi(T);int cnt=1;
	while(T--){
		printf("Case #%d: ",cnt++);
		int n,k;
		gi2(n,k);
		for(int i=1;i<=n;i++){
			gi(a[i]);
		}
		sort(a+1,a+n+1);
		ll minn=inf;
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
			if(i-k+1<1)continue;
			int id=i-k;
			ll ans=1LL*a[i]*k-(sum[i]-sum[id]);
			//if(1LL*a[i]*sum[i]-sum[id])
			minn=min(ans,minn);
		}
		printf("%lld\n",minn);
	}
	
	
	
	return 0;
}
