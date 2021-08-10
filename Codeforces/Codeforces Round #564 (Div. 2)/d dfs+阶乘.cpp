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
const ll mod=998244353;
const int inf=0x3f3f3f3f;
int n;
vector<int>G[MAXN];
ll book[MAXN];
ll dfs(int u,int f){
	int son=0;
	ll ans=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f)continue;
		son++;
		ans*=dfs(v,u);
		ans%=mod;
	}
	if(u==1)ans*=book[son];
	else ans*=book[son+1];
	ans%=mod;
	return ans;
	
}
int main(){
	
	gi(n);
	book[0]=book[1]=1;
	for(int i=2;i<=n;i++){
		book[i]=i*book[i-1]%mod;
	}
	for(int i=1;i<=n-1;i++){
		int u,v;
		gi2(u,v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout<<n*dfs(1,-1)%mod<<endl;
	return 0;
}