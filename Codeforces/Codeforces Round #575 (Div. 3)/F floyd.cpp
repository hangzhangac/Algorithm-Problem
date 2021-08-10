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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll c[805][805];
int book[MAXN];
void floyd(int n){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
			}
		}
	}
	return ;
}
struct Node{
	int u,v;
	int w;
}node[MAXN];
ll ans[802*802];
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int main(){
	
	int n,m,k;
	gi3(n,m,k);
	mem(c,inf);
	for(int i=1;i<=800;i++)c[i][i]=0;
	for(int i=1;i<=m;i++){
		gi3(node[i].u,node[i].v,node[i].w);
	}
	sort(node+1,node+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=min(k,m);i++){
		int u=node[i].u,v=node[i].v,w=node[i].w;
		if(!book[u])book[u]=++cnt;
		if(!book[v])book[v]=++cnt;
		c[book[u]][book[v]]=c[book[v]][book[u]]=w;
	}
	floyd(cnt);
	int kk=0;
	for(int i=1;i<=cnt;i++){
		for(int j=i+1;j<=cnt;j++){
			ans[++kk]=c[i][j];
		}
	}
	sort(ans+1,ans+kk+1);
	printf("%lld\n",ans[k]);
	
	
	
	return 0;
}



