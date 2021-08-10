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
const int MAXN=500005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll a[MAXN];
ll q_pow(ll a, ll n, ll m)
{
	long long ans = 1;
	while(n){
		if(n&1){
			ans = (ans * a) % m;
		}
		a = (a * a) % m;
		n >>= 1;
	}
	return ans;
}

int main()
{
	int num=0;
	ll n,x;
	scanf("%lld%lld",&n,&x);
	
		num=0;
		for(ll i=2;i*i<=n;i++){ 
			 if(n%i==0){
				  a[num++]=i;
				  while(n%i==0)
					  n=n/i;
			 }
		}
		if(n>1)
			a[num++]=n;
		ll cnt=1;
		ll te=1e18;
		for(int i=0;i<num;i++){
			ll t=a[i];
			ll ans=0;
			while(1){
				if(x/t<1)break;
				ans+=x/t;
				if(te/a[i]<t)break;
				t=t*a[i];
			}
			cnt*=q_pow(a[i],ans,mod);
			cnt%=mod;
		}
		printf("%lld\n",cnt%mod);
		
	
	return 0;
}













