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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll a[MAXN];
ll sum[MAXN];
int main(){
	int T;gi(T);
	int cnt=1;
	while(T--){
		printf("Case #%d: ",cnt++);
		int w;
		ll n;
		cin>>w>>n;
		for(int i=1;i<=w;i++){
			cin>>a[i];
		}
		sort(a+1,a+w+1);
		for(int i=1;i<=w;i++){
			sum[i]=sum[i-1]+a[i];
		}
		ll cur=0;
		for (int i=2;i<=w;i++) {
			cur+=n-a[i]+a[1];
		}
		ll ans=cur;
		for(int i=1;i<=w;i++){
			ll q=0;
			ll t=a[i];
			int l=i+1,r=w;
			while(l<=r){
				int mid=(l+r)/2;
				if(2*a[mid]<=2*a[i]+n){
					l=mid+1;
				}
				else r=mid-1;
			}
			ll tmp=-(sum[w]-sum[r])+(t+n)*(w-r);
			q+=tmp;
			int l1=1,r1=i-1;
			while(l1<=r1){
				int mid=(l1+r1)/2;
				if(2*a[mid]<=2*a[i]-n){
					l1=mid+1;
				}
				else r1=mid-1;
			}
			tmp=r1*(n-t)+sum[r1];
			q+=tmp;
			q+=(sum[r]-sum[i])-(r-i)*t;
			q+=(i-r1)*t-(sum[i]-sum[r1]);
			ans=min(ans,q);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}