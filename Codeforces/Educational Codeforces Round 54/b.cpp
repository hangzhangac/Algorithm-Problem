#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
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

ll primeFactor(ll n){

	for(ll i = 3; i <= sqrt(n); i += 2){
		while(n % i == 0){
			return i;
			n /= i;
		}
	}
	return n;
}
int main(){
	
	ll n,ans;
	cin>>n;
	int s=sqrt(n);
	if(n&1){
		ll t=primeFactor(n);
		ans=1;
		n-=t;
		ans+=n/2;
	}
	else{
		ans=n/2;
	}
	printf("%lld\n",ans);
	return 0;
}












