#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
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
const int MAXN=100005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;



int main(){
	int T;cin>>T;
	while(T--){
		int l,r;
		cin>>l>>r;
		int t=r-2*l;
		if(t<0){
			cout<<0<<endl;
			continue;
		}
		if(t==0){
			cout<<1<<endl;
			continue;
		}
		int flag=0;
		if(t%2==0){
			flag=1;
			t--;
		}
		int x=(1+t)/2+1;
		ll y=1LL*(1-t)*x/2;
		ll ans=1ll*(1ll*r-2*l)*x;
		ans+=y;
		if(flag==0){
			x--;
		}
		cout<<ans*2-x<<endl;
		
	}
	
	
	return 0;
}