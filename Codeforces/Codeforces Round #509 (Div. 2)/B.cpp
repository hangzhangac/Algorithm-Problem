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
ll gcd(ll a,ll b){
	if(b==0)return a;
	else return gcd(b,a%b);
}
int main(){
	ll a,b,x,y;
	cin>>a>>b>>x>>y;
	//ll ans=b/y;
	ll t=gcd(x,y);
	x/=t;
	y/=t;
	ll ans=min(b/y,a/x);
	printf("%lld\n",ans);
	
	
	
}