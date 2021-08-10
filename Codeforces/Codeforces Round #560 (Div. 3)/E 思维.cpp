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
const int MAXN=200005;
const ll mod=998244353;
const int inf=0x3f3f3f3f;
ll a[MAXN],b[MAXN];
priority_queue<ll, vector<ll>, less<ll> >q;
int main(){
	
	int n;
	gi(n);
	for(int i=1;i<=n;i++){
		gll(a[i]);
		q.push(a[i]*i*(n-i+1));
	}
	for(int i=1;i<=n;i++){
		gll(b[i]);
	}
	sort(b+1,b+n+1);
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=(q.top()%mod)*b[i]%mod;
		ans%=mod;
		q.pop();
	}
	printf("%lld\n",ans);
	
	
	
	
}