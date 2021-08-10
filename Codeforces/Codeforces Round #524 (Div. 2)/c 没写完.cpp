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
#include <stack>
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
ll n,m;
ll cntw,cntb;
ll calb(ll x,ll y){
	if(x<1||y<1)return 0;
	cntw=((y-1)/2+1)*((x+1)/2);
	cntw+=y/2*(x/2);
	cntb=x*y-cntw;
	return cntb;
}
ll calw(ll x,ll y){
	if(x<1||y<1)return 0;
	cntw=((y-1)/2+1)*((x+1)/2);
	cntw+=y/2*(x/2);
	cntb=x*y-cntw;
	return cntw;
}
int main(){
	int T;gi(T);
	while(T--){
		ll n,m;
		gll2(n,m);
		ll _cntb=calb(m, n);
		ll _cntw=calw(m, n);
		ll xx1,yy1;
		ll xx2,yy2;
		ll xx3,yy3;
		ll xx4,yy4;
		cin>>xx1>>yy1>>xx2>>yy2>>xx3>>yy3>>xx4>>yy4;
		ll b12=calb(xx1-1,yy1-1)+calb(xx2, yy2)-calb(xx1-1,yy2)-calb(xx2,yy1-1);
		
		ll w34=calw(xx3-1,yy3-1)+calw(xx4, yy4)-calw(xx3-1,yy4)-calw(xx4,yy3-1);
		
	}
	return 0;
}