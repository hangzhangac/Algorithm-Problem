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
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=200005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;

ll a[MAXN],b[MAXN];
ll gcd(ll x,ll y){
	if(y==0)
		return x;
	else
		return gcd(y,x%y);
}
int main(){
	int n,m;
	gi2(n,m);
	for(int i=0;i<n;i++)gll(a[i]);
	sort(a,a+n);
	for(int i=0;i<m;i++)gll(b[i]);
	if(n==1){
		for(int i=0;i<m;i++)cout<<a[0]+b[i]<<' ';
		cout<<endl;
	}
	else{
		ll g=a[1]-a[0];
		for(int i=2;i<n;i++){
			ll diff=a[i]-a[i-1];
			g=gcd(g,diff);
		}
		for(int i=0;i<m;i++)cout<<gcd(a[0]+b[i],g)<<' ';
		cout<<endl;
	}
	
	return 0;
}





















