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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll a[MAXN];
int main(){
	
	int n;ll T;
	gi(n);gll(T);
	for(int i=1;i<=n;i++){
		gll(a[i]);
	}
	ll ans=0;
	while (T) {
		ll cnt=0;
		ll num=0;
		int flag=0;
		for(int i=1;i<=n;i++){
			if(T>=a[i]){
				flag=1;
				T-=a[i];
				cnt+=a[i];
				num++;
			}
		}
		if(flag==0)break;
		ans+=num;
		ans+=T/cnt*num;
		T%=cnt;
	}
	printf("%lld\n",ans);
	
	
	
	return 0;
}









