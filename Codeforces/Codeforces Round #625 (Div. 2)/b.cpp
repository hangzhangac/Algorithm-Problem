#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>
#define lson i<<1
#define rson i<<1|1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define gc(x) scanf("%c",&x)
#define gc2(x,y) scanf("%c%c",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const double PI = acos(-1.0); 
const int MAXN=200005;
const ll mod=1e7+9;
const ll llinf = (ll)(1e18) + 500;
const int inf=0x3f3f3f3f;
int n;
int b[MAXN];
map<int,int>ms;
 
ll cnt[MAXN*2];
int main(){
	gi(n);
	ll maxn=1;
	for(int i=1;i<=n;i++){
		gi(b[i]);
		maxn=max(maxn,1LL*b[i]);
	}
	int cnt1=1;
	for(int i=1;i<=n;i++){
		int t=i-b[i];
		if(ms[t]==0){
			ms[t]=cnt1;
			cnt1++;
		}
		int q=ms[t];
		cnt[q]+=b[i];
		maxn=max(maxn,cnt[q]);
	}
	printf("%lld\n",maxn);
	
	
	return 0;
}
