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
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
struct Node{
	int x,y;
	int id;
}node[MAXN];
bool cmp(Node a,Node b){
	return a.x+b.y<a.y+b.x;
}
bool cmp1(Node a,Node b){
	return a.id<b.id;
}
ll sumx[MAXN];
ll sumy[MAXN];
ll ans[MAXN];
int main(){
	
	int n,m;
	gi2(n,m);
	for(int i=1;i<=n;i++){
		gi2(node[i].x, node[i].y);
		node[i].id=i;
	}
	sort(node+1,node+n+1,cmp);
	for(int i=1;i<=n;i++){
		sumx[i]=sumx[i-1]+node[i].x;
	}
	for(int i=n;i>=1;i--){
		sumy[i]=sumy[i+1]+node[i].y;
	}
	for(int i=1;i<=n;i++){
		ans[node[i].id]+=sumx[i-1];
		ans[node[i].id]+=sumy[i+1];
		ans[node[i].id]+=1LL*(i-1)*node[i].y;
		ans[node[i].id]+=1LL*(n-i)*node[i].x;
	}
	sort(node+1,node+n+1,cmp1);
	while(m--){
		int u,v;
		gi2(u, v);
		ans[u]-=min(node[u].x+node[v].y,node[u].y+node[v].x);
		ans[v]-=min(node[u].x+node[v].y,node[u].y+node[v].x);
	}
	for(int i=1;i<=n;i++){
		printf("%lld ",ans[i]);
	}

	
	
	return 0;
}



























