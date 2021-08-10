#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
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
int n;
vector<int>G[MAXN];
int siz[MAXN];
int cnt=0;
void dfs(int u,int f){
	siz[u]=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f)continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
	if(siz[u]%2==0)cnt++;
}
int main(){
	
	gi(n);
	
	for(int i=1;i<=n-1;i++){
		int x,y;
		gi2(x,y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	if(n&1){
		printf("-1\n");
		return 0;
	}
	dfs(1,-1);
	printf("%d\n",cnt-1);
	
	return 0;
}











