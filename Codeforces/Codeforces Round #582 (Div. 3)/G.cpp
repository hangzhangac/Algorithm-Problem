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
struct Node{
	int u,v;
	int w;
}node[MAXN];
int f[MAXN];
ll ans[MAXN];
int siz[MAXN],n,m;
void init(){
	for(int i=1;i<=n;i++){
		f[i]=i;
		siz[i]=1;
	}
}
int find1(int x){
	if(x==f[x])return x;
	return f[x]=find1(f[x]);
}
ll num=0;
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int main(){
	
	gi2(n,m);
	init();
	for(int i=1;i<=n-1;i++){
		gi3(node[i].u,node[i].v,node[i].w);
	}
	sort(node+1,node+n,cmp);
	int i=1;
	for(int j=1;j<=200000;j++){
		while(i<=n-1&&node[i].w<=j){
			int x=node[i].u,y=node[i].v;
			int fx=find1(x),fy=find1(y);
			if(fx!=fy){
				f[fx]=fy;
				num-=1LL*siz[fy]*(siz[fy]-1)/2;
				num-=1LL*siz[fx]*(siz[fx]-1)/2;
				siz[fy]+=siz[fx];
				num+=1LL*siz[fy]*(siz[fy]-1)/2;
			}
			i++;
		}
		ans[j]=num;
	}
	while(m--){
		int q;
		gi(q);
		printf("%lld ",ans[q]);
	}
	return 0;
}