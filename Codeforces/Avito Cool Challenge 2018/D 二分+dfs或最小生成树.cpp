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
#include <stack>
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
vector<int>G[MAXN];
struct Node{
	int u,v,w;	
}node[MAXN];
int book[MAXN];
int a[MAXN];
int n,m,k;
int cnt=0;
void dfs(int u){
	book[u]=1;
	if(a[u])cnt++;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(!book[v]){
			dfs(v);
		}
	}
}
int st;
bool C(int mid){
	for(int i=1;i<=n;i++){
		G[i].clear();
		book[i]=0;
	}
	for(int i=1;i<=m;i++){
		if(node[i].w<=mid&&node[i].u!=node[i].v){
			G[node[i].u].push_back(node[i].v);
			G[node[i].v].push_back(node[i].u);
		}
	}
	cnt=0;
	dfs(st);
	return cnt==k;
}
int main(){
	
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		int x;gi(x);
		st=x;
		a[x]=1;
	}
	int l=inf,r=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		gi3(u, v, w);
		node[i].u=u,node[i].v=v,node[i].w=w;
		l=min(l,w);
		r=max(r,w);
	}
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(C(mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;	
		}
	}
	for(int i=1;i<=k;i++){
		printf("%d ",ans);
	}
	
	return 0;
}







