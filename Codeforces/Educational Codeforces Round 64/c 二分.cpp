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
int n,z;
ll a[MAXN];
int main(){
	gi2(n,z);
	for(int i=1;i<=n;i++){
		gll(a[i]);
	}
	sort(a+1,a+n+1);
	int ans=0;
	int l=1,r=n/2;
	while(l<=r){
		int mid=(l+r)/2;
		bool ok=true;
		for(int i=1;i<=mid;i++){
			if(a[i]+z>a[n-mid+i]){
				ok=false;
				break;
			}
		}
		ok? (l=mid+1,ans=mid):r=mid-1;
		
	}
	printf("%d\n",ans);
	
	
	
	return 0;
}








