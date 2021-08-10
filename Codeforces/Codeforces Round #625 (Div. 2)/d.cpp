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
int n,m;

map<int,int>ms[MAXN];
int a[MAXN];
int d[MAXN];
struct edge{
	int to,cost;
};
typedef pair<int,int>P;
vector<edge>G[MAXN];
void dij(int s){
	priority_queue<P, vector<P>, greater<P> >que;
	fill(d, d+n+1, inf);
	d[s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		P p=que.top();que.pop();
		int v=p.second;
		if (d[v]<p.first)continue;
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			if(d[e.to]>d[v]+1){
				d[e.to]=d[v]+1;
				que.push(P(d[e.to],e.to));
				ms[e.to].clear();
				ms[e.to][v]=1;
			}
			else if(d[e.to]==d[v]+1){
				ms[e.to][v]=1;
			}
		}
	}
}
int main(){
	
	gi2(n, m);
	while(m--){
		int u,v;
		gi2(u,v);
		edge e;
		e.to=u;
		e.cost=1;
		G[v].push_back(e);
	}
	int k;
	gi(k);
	for(int i=1;i<=k;i++){
		gi(a[i]);
	}
	int s=a[1],t=a[k];
	dij(t);
	int minn=0;
	int maxn=0;
	for(int i=1;i<=k-1;i++){
		int cur=a[i],nex=a[i+1];
		if(ms[cur][nex]);
		else minn++;
		if(ms[cur].size()>=2){
			maxn++;
		}
		else if(ms[cur][nex]){
			;
		}
		else maxn++;
	}
	printf("%d %d\n",minn,maxn);
	
	
	return 0;
}









