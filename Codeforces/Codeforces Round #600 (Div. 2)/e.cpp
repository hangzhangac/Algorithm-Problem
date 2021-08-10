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
const int MAXN=85;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n,m;
int dp[100005];
struct Node{
	int x,s;
	int l,r;
}node[MAXN];
bool cmp(Node a,Node b){
	return a.l<b.l;
}
int main(){
	gi2(n,m);
	mem(dp,0x3f);
	for(int i=1;i<=n;i++){
		gi2(node[i].x,node[i].s);
		node[i].l=max(1,node[i].x-node[i].s);
		node[i].r=min(m,node[i].x+node[i].s);
	}
	sort(node+1,node+n+1,cmp);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=node[i].r;j--){
			int inc=j-node[i].r;
			int id=max(0,node[i].l-inc-1);
			dp[j]=min(dp[j],dp[id]+inc);
		}
		int minn=0x3f3f3f3f;
		for(int j=0;j<node[i].l;j++){
			minn=min(minn,dp[j]+node[i].l-j-1);
			dp[j]=min(dp[j],minn);
			int t=min(m,node[i].r+node[i].l-j-1);
			dp[t]=min(dp[t],minn);
		}
		dp[node[i].l]=min(dp[node[i].l],minn);
		for(int j=node[i].l+1;j<=node[i].r;j++){
			dp[j]=min(dp[j],dp[node[i].l]);
		}
	}	
	cout<<dp[m]<<endl;
	
	return 0;
}