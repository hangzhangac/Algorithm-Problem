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
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=25;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN],b[MAXN];
int n,h;
ll ans=0;
ll suma[MAXN],sumb[MAXN];
ll pp[MAXN];
void dfs(int u,ll cur0,ll cur1){
	if(u==n+1){
		if(cur0>=h&&cur1>=h){
			ans++;
		}
		return;
	}
	if(suma[u]+cur0<h||sumb[u]+cur1<h) return;
	if(cur0>=h&&cur1>=h){
		ans+=pp[n-u+1];
		return;
	}
	dfs(u+1,cur0+a[u],cur1);
	dfs(u+1,cur0,cur1+b[u]);
	dfs(u+1,cur0+a[u],cur1+b[u]);
}
int main(){
	int T,cnt=1;
	gi(T);
	pp[0]=1;
	for(int i=1;i<=21;i++){
		pp[i]=pp[i-1]*3;
	}
	while(T--){
		ans=0;
		suma[n+1]=sumb[n+1]=0;
		printf("Case #%d: ",cnt++);
		gi2(n,h);
		for(int i=1;i<=n;i++){
			gi(a[i]);
		}
		for(int i=1;i<=n;i++){
			gi(b[i]);
		}
		for(int i=n;i>=1;i--){
			suma[i]=suma[i+1]+a[i];
			sumb[i]=sumb[i+1]+b[i];
		}
		dfs(1,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}