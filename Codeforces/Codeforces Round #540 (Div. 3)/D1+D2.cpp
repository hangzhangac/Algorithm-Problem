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
int n,m;
bool cmp(ll a,ll b){
	return a>b;
}
int C(int mid){
	ll sum=0;
	for(int i=0;i<n;i++){
		sum+=max(0LL,a[i]-i/mid);
		if(sum>=m)return 1;
	}
	return 0;
}
int main(){
	gi2(n,m);
	for(int i=0;i<n;i++){
		gll(a[i]);
	}
	sort(a,a+n,cmp);
	int l=1,r=n;
	int ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(C(mid)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}








