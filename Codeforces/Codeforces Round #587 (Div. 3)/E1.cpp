
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
int k;
int cal(int x){
	int cnt=0;
	while(x){
		cnt++;
		x/=10;
	}
	return cnt;
}
ll solve(int mid){
	ll ans=0;
	for(int i=1,j=mid;i<=mid;i++,j--){
		int cnt=cal(i);
		ans+=1LL*cnt*j;
	}
	return ans;
}
bool C(int mid){
	ll ans=solve(mid);
	if(ans<=k){
		return true;
	}
	return false;
}
int main(){
	int q;gi(q);while(q--){
		gi(k);
		int l=1,r=100000;
		int ans=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(C(mid)){
				ans=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		if(solve(ans)==k){
			printf("%d\n",ans%10);
		}
		else{
			k-=solve(ans);
			int flag=-1;
			for(int i=1;i<=ans+1;i++){
				int t=cal(i);
				if(k<=t){
					int a[10];
					while(i){
						a[t--]=i%10;
						i/=10;
					}
					printf("%d\n",a[k]);
					break;
				}
				else{
					k-=t;
				}
			}
		}
	}
	return 0;
}