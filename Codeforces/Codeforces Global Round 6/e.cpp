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
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
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
int a[MAXN],book[MAXN];
map<int,int>ms[MAXN];
int main(){
	//freopen("in.txt","r",stdin);
	int n;
	gi(n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		gi(a[i]);
		ans+=a[i];
	}
	int q;gi(q);
 
	while(q--){
		int s,t,u;
		gi3(s,t,u);
		int id=ms[s][t];
		if(id!=0){
			ms[s][t]=0;
			book[id]--;
			if(book[id]<a[id]){
				ans++;
			}
		}
		if(u!=0){
			ms[s][t]=u;
			if(book[u]<a[u]){
				ans--;
			}
			book[u]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}