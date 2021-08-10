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
const int MAXN=100005;
const ll mod=1e9+7;
const ll inf=1e18+1;
ll dp[MAXN][3];
int n;
int b[MAXN];
vector<int>G[MAXN];
struct Node{
	ll a,b;
	ll diff;
	Node(ll aa,ll bb){
		a=aa,b=bb;
		diff=a-b;
	}
};
bool cmp(Node a,Node b){
	return a.diff>b.diff;
}
//dp[u][0] 自己和孩子都没点亮
//dp[u][2] 自己没点亮 孩子亮了
//
//dp[u][1] 自己点亮

void dfs(int u,int f){
	vector<Node>ans;
	dp[u][1]=b[u];
	dp[u][0]=dp[u][2]=0;
	ll cnt=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];if(v==f)continue;
		dfs(v,u);
		ll t=-inf;
		if(G[v].size()>=2)t=dp[v][2];
		dp[u][1]+=max(max(dp[v][1],dp[v][0]+b[v]),t);
		dp[u][0]+=max(dp[v][0],dp[v][2]);
		cnt+=max(dp[v][0],dp[v][2]);
		ans.push_back(Node(dp[v][1],max(dp[v][0],dp[v][2])));
	}
	if(ans.size()==0)return;
	sort(ans.begin(),ans.end(),cmp);
	cnt+=ans[0].diff+b[u];
	for(int i=1;i<ans.size();i++){
		if(ans[i].diff<=0)break;
		cnt+=ans[i].diff;
	}
	dp[u][2]=cnt;
	ans.clear();
	return;
}
int main(){
	int T,cnt=1;gi(T);while(T--){
		gi(n);
		for(int i=1;i<=n;i++){
			gi(b[i]);
		}
		for(int i=1;i<=n-1;i++){
			int x,y;
			gi2(x,y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1,-1);
		printf("Case #%d: ",cnt++);
		printf("%lld\n",max(max(dp[1][2],dp[1][1]),dp[1][0]));
		for(int i=1;i<=n;i++){
			G[i].clear();
		}
	}
	return 0;
}