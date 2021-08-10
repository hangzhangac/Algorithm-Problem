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
int n,k;
int a[MAXN];
int C(int mid){
	
	for(int i=1;i<=n;i++){
		int s=a[i];
		int t=a[i]+mid+mid;
		int id=upper_bound(a+i, a+n+1, t)-a-1;
		if(id-i+1>=k+1){
			return a[i]+mid;
		}
	}
	return -1;
	
}
int main(){
	
	int T;
	gi(T);
	while(T--){
		gi2(n,k);
		for(int i=1;i<=n;i++){
			gi(a[i]);
		}
		int l=0,r=a[n]-a[1]+1;
		int ans=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(C(mid)!=-1){
				r=mid-1;
				ans=mid;
			}
			else{
				l=mid+1;
			}
		}
		printf("%d\n",C(ans));
	}
	
	return 0;
}