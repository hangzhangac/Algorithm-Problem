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
const int MAXN=5005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll n,k;
void cal(int n){
	while(n!=0){
		book[n]++;
		if(n&1){
			n--;
		}
		else{
			n/=2;
		}
	}
}

bool C_2(ll mid){
	ll xi=1;
	ll cnt=0;
	while(1){
		if(n*1.0/xi<mid){
			break;
		}
		ll base=xi*mid;
		ll maxn=base+xi*2-1;
		if(maxn<=n)cnt+=xi*2;
		else{
			cnt+=n-base+1;
			break;
		}
		xi*=2;
	}
	return cnt>=k;
}
bool C_1(ll mid){
	ll xi=1;
	ll cnt=0;
	while(1){
		if(n*1.0/xi<mid){
			break;
		}
		ll base=xi*mid;
		ll maxn=base+xi-1;
		if(maxn<=n)cnt+=xi;
		else{
			cnt+=n-base+1;
			break;
		}
		xi*=2;
	}
	return cnt>=k;
}
int main(){
	cin>>n>>k;
	ll l=0;
	ll r=0;
	if(n&1)r=n/2;
	else r=(n-1)/2;
	ll ans1=1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(C_1(2*mid+1)){
			ans1=2*mid+1;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	l=1;
	r=n/2;
	ll ans2=0;
	while(l<=r){
		ll mid=(l+r)/2;
		if(C_2(2*mid)){
			ans2=2*mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%lld\n",max(ans1,ans2));
	return 0;
}








