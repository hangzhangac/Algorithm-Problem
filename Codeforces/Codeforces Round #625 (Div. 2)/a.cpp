#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>
#define lson i<<1
#define rson i<<1|1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define gc(x) scanf("%c",&x)
#define gc2(x,y) scanf("%c%c",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const double PI = acos(-1.0); 
const int MAXN=100005;
const ll mod=1e7+9;
const ll llinf = (ll)(1e18) + 500;
const int inf=0x3f3f3f3f;

int n;
int b[MAXN];
int r[MAXN];
int a[MAXN];
int q[MAXN];
int main(){
	gi(n);
	for(int i=1;i<=n;i++){
		gi(r[i]);
	}
	int flag=0;
	for(int i=1;i<=n;i++){
		gi(b[i]);
		if(b[i]==1){
			a[i]=1;
		}
		if(b[i]>=r[i]);
		else flag=1;
	}
	if(flag==0){
		printf("-1\n");
		return 0;
	}
	int ans=-1;
	int l=1,rr=2e9;
	for(int i=1;i<=n;i++){
		q[i]=a[i];
	}
	while(l<=rr){
		for(int i=1;i<=n;i++){
			a[i]=q[i];
		}
		int mid=(l+rr)/2;
		ll cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				a[i]=mid;
			}
		}
		ll cnt1=0;
		ll cnt2=0;
		for(int i=1;i<=n;i++){
			if(r[i])cnt1+=a[i];
			if(b[i])cnt2+=a[i];
		}
		if(cnt1>cnt2){
			ans=mid;
			rr=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	printf("%d\n",ans);
	
	return 0;
}
