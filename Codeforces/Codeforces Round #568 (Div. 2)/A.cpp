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
int main(){
	
	ll a[4];
	for(int i=0;i<3;i++){
		gll(a[i]);
	}
	ll d;gll(d);
	sort(a,a+3);
	ll ans=10000000000000000;
	ll aa=0;
	ll c=max(a[0]+d,a[1]);
	aa+=c-a[1];
	c=max(c+d,a[2]);
	aa+=c-a[2];
	ans=min(ans,aa);
	aa=0;
	ll q=min(a[1]-d,a[0]);
	aa+=a[0]-q;
	q=max(a[1]+d,a[2]);
	aa+=q-a[2];
	ans=min(ans,aa);
	aa=0;
	c=min(a[2]-d,a[1]);
	aa+=a[1]-c;
	c=min(c-d,a[0]);
	aa+=a[0]-c;
	ans=min(ans,aa);
	
	
	cout<<ans<<endl;
	return 0;
}



