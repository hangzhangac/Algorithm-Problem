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
vector<int>ans;
int n,m;
int f[MAXN];
void init(){
	ans.clear();
	for(int i=1;i<=n;i++){
		f[i]=i;
		G[i].clear();
	}
}
int find1(int x){
	if(x==f[x])return x;
	return f[x]=find1(f[x]);
}
void dfs(int u,int flag,int f){
	if(flag==1){
		ans.push_back(u);
	}
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f)continue;
		dfs(v,flag^1,u);
	}
}
int main(){
	int T;gi(T);
	while(T--){
		gi2(n,m);
		init();
		for(int i=1;i<=m;i++){
			int u,v;
			gi2(u,v);
			int fu=find1(u),fv=find1(v);
			if(fu==fv)continue;
			f[fu]=fv;
			G[u].push_back(v);
			G[v].push_back(u);
			//cout<<u<<' '<<v<<endl;
		}
		if(n==2){
			printf("1\n1\n");
			continue;
		}
		dfs(1,1,-1);
		int t=ans.size();
		if(t>n/2){
			ans.clear();
			dfs(1,0,-1);
			t=ans.size();
		}
		printf("%d\n",t);
		for(int i=0;i<ans.size();i++){
			printf("%d%c",ans[i],(i==ans.size()-1)?'\n':' ');
		}
	}
	
	
	
	
	
	return 0;
}







