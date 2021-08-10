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
const int MAXN=300005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;


ll a[MAXN];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll sum=a[1];
	ll sum2=a[1]*a[1];
	ll ans=0;
	for(int i=2;i<=n;i++){
		ans+=a[i]*a[i]*(i-1);
		ans+=sum2;
		ans-=a[i]*2*sum;
		sum+=a[i];
		sum2+=a[i]*a[i];
	}
	cout<<ans<<endl;
	
	return 0;
}



















