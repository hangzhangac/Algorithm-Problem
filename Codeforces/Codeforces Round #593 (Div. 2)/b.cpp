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
ll binaryPow(ll a, ll b, ll m){
	ll ans = 1;
	while(b > 0){
		if(b & 1){
			ans = ans * a % m;
		}
		a = a * a % m;
		b >>= 1; 
	} 
	return ans;
}

int main(){
	
	ll n,m;
	cin>>n>>m;
	ll t=binaryPow(2,(m),mod)-1;
	t+=mod;
	t%=mod;
	cout<<binaryPow(t, n, mod)<<endl;
	
	
	
	
	return 0;
}











