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



int main() {
	
	
	ll p,b,c;
	ll a[3];
	int t;cin>>t;while(t--){
		cin>>p>>a[0]>>a[1]>>a[2];
		ll ans=1e18;
		ans+=10;
		for(int i=0;i<=2;i++){
			if(p%a[i]==0){
				ans=0;break;
			}
			else{
				ans=min((p/a[i]+1)*a[i]-p,ans);
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}















