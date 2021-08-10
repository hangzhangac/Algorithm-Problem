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
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
vector<int>G[MAXN];
int n,in[MAXN];
int maxx=0;
int dp[MAXN][3];

void dfs(int u,int f){
	int cnt=0;
	dp[u][1]=dp[u][2]=0;
	int maxn1=0,maxn2=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f)continue;
		dfs(v,u);
		if(in[v]==1){
			dp[u][1]++;
			dp[u][2]++;
		}
		else if(in[v]>=2){
			int t=dp[v][1];
			cnt++;
			if(t>maxn1){
				maxn2=maxn1;
				maxn1=t;
			}
			else if(t<=maxn1&&t>maxn2){
				maxn2=t;
			}
		}
	}
	dp[u][1]+=maxn1+1;
	dp[u][2]+=maxn2+maxn1+1;
	if(cnt>=1){
		dp[u][1]+=cnt-1;
		dp[u][2]+=cnt-1;
	}
	if(cnt>=2)dp[u][2]--;
	int t=0;
	if(f!=-1){
		t=1;
	}
	maxx=max(dp[u][2]+t,maxx);
	maxx=max(dp[u][1]+t,maxx);
	
}
int main(){
	
	int q;gi(q);while(q--){
		maxx=2;
		gi(n);
		
		for(int i=1;i<=n-1;i++){
			int x,y;
			gi2(x,y);
			G[x].push_back(y);G[y].push_back(x);
			in[x]++,in[y]++;
		}
		dfs(1,-1);
		cout<<maxx<<endl;
		for(int i=1;i<=n;i++){
			in[i]=0;
			G[i].clear();
		//	cout<<i<<" : "<<dp[i][1]<<' '<<dp[i][2]<<endl;
		}
	}
	return 0;
}