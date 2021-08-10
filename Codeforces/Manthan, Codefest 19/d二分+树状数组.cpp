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
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll sum[MAXN];
int n;
ll a[MAXN];
int lowbit(int x){
	return x&-x;
}
void update(int x,int v){
	while(x<=n){
		sum[x]+=v;
		x+=lowbit(x);
	}
}
ll query(int x){
	ll s=0;
	while(x>=1){
		s+=sum[x];
		x-=lowbit(x);
	}
	return s;
}
int main(){
	gi(n);
	for(int i=1;i<=n;i++){
		gll(a[i]);
	}
	for(int i=1;i<=n;i++){
		update(i, i);
	}
	for(int i=n;i>=1;i--){
		int ans=0;
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(query(mid)<=a[i]){
				l=mid+1;
				ans=mid;
			}
			else r=mid-1;
		}
		update(ans+1,-ans-1);
		a[i]=ans+1;
	}
	for(int i=1;i<=n;i++){
		printf("%lld ",a[i]);
	}
	return 0;
}