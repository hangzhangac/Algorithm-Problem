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
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int dp[MAXN][3];
int a[MAXN];
vector<int>G[MAXN];
int cnt=0;
int red=0,blue=0;
void dfs(int u,int f){
	dp[u][a[u]]=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f)continue;
		dfs(v,u);
		if(dp[v][1]==0&&dp[v][2]==blue||dp[v][2]==0&&dp[v][1]==red){
			cnt++;
		}
		dp[u][1]+=dp[v][1],dp[u][2]+=dp[v][2];
	}
}
int main(){
	
	int n;gi(n);
	
	for(int i=1;i<=n;i++){
		gi(a[i]);
		if(a[i]==1)red++;
		else if(a[i]==2)blue++;
	}
	for(int i=1;i<n;i++){
		int u,v;
		gi2(u,v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,-1);
	printf("%d\n",cnt);
	
	
	
	
	return 0;
}






