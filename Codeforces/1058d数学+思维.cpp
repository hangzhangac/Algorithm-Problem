//https://www.cnblogs.com/markleaf/p/7808817.html
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
	if(!b)return a;
	return gcd(b,a%b);
}
ll t;
ll n,m,k;

int main(){
	
	cin>>n>>m>>k;
	t=2*n*m;
	if(t%k!=0){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	printf("0 0\n");
	ll x,y;
	ll g=gcd(2*n,k);
	if(g>=2){
		x=2*n/g;
		k/=g;
		y=m/k;
	}
	else{
		y=2*m/k;
		x=n;
	}
	printf("%lld 0\n",x);
	printf("0 %lld\n",y);
	return 0;
}


























