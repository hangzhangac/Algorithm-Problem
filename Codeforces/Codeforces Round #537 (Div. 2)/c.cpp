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
int n,k,A,B;
ll a[MAXN];
ll dfs(int l,int r){
	int ll=lower_bound(a, a+k, l)-a;
	int rr=upper_bound(a, a+k, r)-a-1;
	if(rr==-1||ll==k||rr<ll)return A;
	long long ge=rr-ll+1;
	long long minn=1LL*ge*B*(r-l+1);
	int mid=(r+l-1)/2;
	if(r==l)return minn;
	else return min(minn,dfs(l,mid)+dfs(mid+1,r));
}
int main(){
	gi2(n,k);gi2(A,B);
	for(int i=0;i<k;i++){
		gll(a[i]);
	}
	sort(a,a+k);
	ll ans=dfs(1,1<<n);
	printf("%lld\n",ans);
	return 0;
}






















