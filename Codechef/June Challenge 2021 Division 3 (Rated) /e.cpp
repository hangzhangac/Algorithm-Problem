#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
int n;
struct Node{
	int x,y;
}node[MAXN];
bool cmp(Node a,Node b){
	return a.x<b.x;
}
bool cmp1(Node a,Node b){
	return a.y<b.y;
}
int max_x[MAXN];
int min_x[MAXN];
int max_y[MAXN];
int min_y[MAXN];
int max_x1[MAXN];
int min_x1[MAXN];
int max_y1[MAXN];
int min_y1[MAXN];
void solve(ll &ans){
	max_x[n+1]=-1;max_y[n+1]=-1;
	min_x[n+1]=inf;min_y[n+1]=inf;
	for(int i=n;i>=1;i--){
		max_x[i]=max(node[i].x,max_x[i+1]);
		max_y[i]=max(node[i].y,max_y[i+1]);
		min_x[i]=min(node[i].x,min_x[i+1]);
		min_y[i]=min(node[i].y,min_y[i+1]);
	}
	max_x1[0]=-1;max_y1[0]=-1;
	min_x1[0]=inf;min_y1[0]=inf;
	for(int i=1;i<=n;i++){
		max_x1[i]=max(node[i].x,max_x1[i-1]);
		max_y1[i]=max(node[i].y,max_y1[i-1]);
		min_x1[i]=min(node[i].x,min_x1[i-1]);
		min_y1[i]=min(node[i].y,min_y1[i-1]);
	}
	for(int i=1;i<=n;i++){
		ll w=max_x1[i]-min_x1[i];
		ll h=max_y1[i]-min_y1[i];
		ll cnt=w*h;
		if(i!=n){
			w=max_x[i+1]-min_x[i+1];
			h=max_y[i+1]-min_y[i+1];
			cnt+=w*h;
		}
		ans=min(ans,cnt);
	}
}
int main(int argc, char *argv[]) {
	int T;gi(T);
	while(T--){
		gi(n);
		for(int i=1;i<=n;i++){
			gi2(node[i].x, node[i].y);
		}
		ll ans=1e18;
		sort(node+1,node+n+1,cmp);
		solve(ans);
		sort(node+1,node+n+1,cmp1);
		solve(ans);
		cout<<ans<<endl;
	}
	return 0;
}



















