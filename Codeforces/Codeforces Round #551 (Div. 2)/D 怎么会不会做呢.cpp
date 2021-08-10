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
int n;
vector<int>G[MAXN];
int a[MAXN];
int cnt=0;
int dfs(int u,int f){
	if(G[u].size()==0){
		cnt++;
		return 1;
	}
	if(a[u]==1){//MAX
		int num=n;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(v==f)continue;
			num=min(num,dfs(v,u));
		}
		return num;
	}
	else{//MIN
		int num=0;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(v==f)continue;
			num+=dfs(v,u);
		}
		return num;
	}
}
int main(){
	gi(n);
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	for(int i=2;i<=n;i++){
		int x;gi(x);
		G[x].push_back(i);
	}
	int t=dfs(1,-1);
	printf("%d\n",cnt-t+1);
	
	return 0;
}





