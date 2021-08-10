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
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
vector<int>G[MAXN];
vector<int>T[MAXN];
int dp[MAXN][10];
int best[MAXN][10];
int a[MAXN];
int maxn=1;
int d;
int pri[MAXN];
void check(){
	for(int i=2;i<2e5;i++){
		if(pri[i]==0){
			T[i].push_back(i);
			int j=i*2;
			while(j<2e5){
				pri[j]=1;
				T[j].push_back(i);
				j+=i;
			}
		}
	}
}
void dfs(int u,int f){
	for(int p=0;p<T[a[u]].size();p++){
		dp[u][p]=1;
	}
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f)continue;
		dfs(v,u);
		for(int p=0;p<T[a[u]].size();p++){
			for(int q=0;q<T[a[v]].size();q++){
				if(T[a[u]][p]==T[a[v]][q]){
					dp[u][p]=max(dp[u][p],dp[v][q]+1);
					maxn=max(dp[v][q]+1+best[u][p],maxn);
					best[u][p]=max(best[u][p],dp[v][q]);
					maxn=max(dp[u][p],maxn);
					break;
				}
			}
		}
	}
}
int main(){
	
	int n;
	gi(n);
	check();
	int flag=0;
	for(int i=1;i<=n;i++){
		gi(a[i]);
		if(a[i]!=1){
			flag=1;
		}
	}
	int x,y;
	for(int i=1;i<=n-1;i++){
		gi2(x,y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	if(flag==0){
		printf("0\n");
		return 0;
	}
	dfs(1,-1);
	printf("%d\n",maxn);
	return 0;
}


