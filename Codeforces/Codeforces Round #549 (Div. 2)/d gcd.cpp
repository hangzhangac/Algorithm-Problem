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
ll gcd(ll a,ll b){
	if(b==0)return a;
	else return gcd(b,a%b);
}
ll minn=1000000000000;
ll maxn=0;
ll n,k;
void solve(ll x){
	ll s=gcd(x,n*k);
	maxn=max(s,maxn);
	minn=min(s,minn);
}
int main(){
	
	
	cin>>n>>k;
	ll a,b;
	cin>>a>>b;
	ll ans1=n*k;
	
	for(ll x=0;x<=n-1;x++){
		solve(a+b+x*k);
		solve(b-a+(x+1)*k);
		solve(a-b+(x+1)*k);
		solve(-a-b+(x+2)*k);
	}
	if(b>a){
		solve(b-a);
	}
	solve(k-b-a);
	printf("%lld %lld\n",ans1/maxn,ans1/minn);
	return 0;
}









