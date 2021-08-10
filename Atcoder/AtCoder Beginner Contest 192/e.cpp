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
int n,m,x,y;

ll d[MAXN];
struct edge{
	int to;
	ll cost;
	ll k;
	edge(){
		
	}
	edge(int a,int b,int c){
		to=a;
		cost=b;
		k=c;
	}
};
typedef pair<ll,int>P;
vector<edge>G[MAXN];
void dij(int s){
	priority_queue<P, vector<P>, greater<P> >que;
	for(int i=1;i<=n;i++){
		d[i]=1000000000000000000+7;
	}
	d[s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		P p=que.top();que.pop();
		int v=p.second;
		if(v==y)return;
		if (d[v]<p.first)continue;
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			ll k=e.k;
			ll tim=e.cost;
			ll com=d[v];
			if(d[v]%k==0){
				com=d[v]+tim;
			}
			else{
				com=(d[v]/k+1)*k+tim;
			}
			if(d[e.to]>com){
				d[e.to]=com;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}
int main(){
	
	cin>>n>>m>>x>>y;
	int a,b,c,dd;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c>>dd;
		G[a].push_back(edge(b, c, dd));
		G[b].push_back(edge(a, c, dd));
	}
	dij(x);
	if(d[y]==1000000000000000000+7){
		cout<<-1<<endl;
	}
	else cout<<d[y]<<endl;
	return 0;
}









