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
const int MAXN=500005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;

vector<int>G[MAXN];
vector<int>path;
int pa[MAXN];
int pb[MAXN];
int n,a,b;
ll cnt=0;
void dfs(int u,vector<int>& path){
	path.push_back(u);
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		dfs(v,path);
	}
	pa[u]++;
	pb[u]++;
	int t=path.size();
	if(t-1-a>=0){
		pa[path[t-1-a]]+=pa[u];
	}
	if(t-1-b>=0){
		pb[path[t-1-b]]+=pb[u];
	}
	path.pop_back();
}
int main(){
	int idx=1;
	int T;gi(T);while(T--){
		cnt=0;
		gi3(n,a,b);
		for(int i=1;i<=n;i++){
			G[i].clear();
			pa[i]=pb[i]=0;
		}
		for(int i=2;i<=n;i++){
			int x;
			gi(x);
			G[x].push_back(i);
		}
		dfs(1,path);
		double ans=0.0;
		for(int i=1;i<=n;i++){
			ans+=1.0*pa[i]/n+1.0*pb[i]/n-1.0*pa[i]/n*pb[i]/n;
		}
		
		printf("Case #%d: %.7lf\n",idx++,ans);
	}
	return 0;
}