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
const long long  inf=1000000000000000000;
struct edge{
	int to;
	ll cost;
	int id;
	edge(){
		
	}
	edge(int x,ll y,int z){
		to=x;cost=y;id=z;
	}
};
typedef pair<ll,pair<int,int> >P;

vector<edge>G[MAXN];
vector< pair<int,int> >GG[MAXN];
ll d[MAXN];
int n,m,k;
pair<int, int>pp[MAXN];
void dijkstra(int s){
	for(int i=1;i<=n;i++){
		d[i]=inf;
	}
	d[s]=0;
	priority_queue<P,vector<P> ,greater<P> >que;
	//que.push(0,)
	que.push(P(0,make_pair(s, -1)));
	while(!que.empty()){
		P p=que.top();
		que.pop();
		ll dd=p.first;
		int v=p.second.first;
		int id=p.second.second;
		if(d[v]<dd)continue;
		pp[v].first=id;
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],make_pair(e.to, e.id)));
			}
		}
	}
}
struct Node{
	int x,y;
	ll z;
}node[MAXN];
int in[MAXN];
int fa[MAXN];
int ii[MAXN];
int book[MAXN];
void dfs(int u,int f,int x){
	fa[u]=f;
	ii[u]=x;
	for(int i=0;i<GG[u].size();i++){
		pair<int, int>p=GG[u][i];
		int id=p.first;
		int v=p.second;
		if(v==f)continue;
		dfs(v,u,id);
		in[u]++;
	}
}
int main(){
	
	gi3(n, m, k);
	for(int i=1;i<=m;i++){
		int x,y;
		ll w;
		gi2(x,y);
		gll(w);
		G[x].push_back(edge(y,w,i));
		G[y].push_back(edge(x,w,i));
		node[i].x=x;
		node[i].y=y;
		node[i].z=w;
	}
	if(k==0){
		printf("0\n");
		return 0;
	}
	dijkstra(1);
	if(k>=n-1){
		sort(pp+1,pp+n+1);
		printf("%d\n",n-1);
		for(int i=2;i<=n;i++){
			cout<<pp[i].first<<' ';
		}
	}
	else{
		for(int j=2;j<=n;j++){
			int i=pp[j].first;
			int x=node[i].x;
			int y=node[i].y;
			//cout<<i<<endl;
			GG[x].push_back(make_pair(i, y));
			GG[y].push_back(make_pair(i, x));
			
		}
		dfs(1,-1,0);
		int tt=n-1-k;
		//cout<<t<<endl;
		queue<int>q;
		for(int i=1;i<=n;i++){
			if(!in[i]){
				q.push(i);
				//cout<<i<<"fae"<<endl;
			}
		}
		while(!q.empty()&&tt){
			int t=q.front();tt--;q.pop();
			book[ii[t]]=1;
		//	cout<<ii[t]<<"fae"<<endl;
			in[fa[t]]--;
			if(!in[fa[t]]){
				q.push(fa[t]);
			}
		}
		printf("%d\n",k);
		for(int i=2;i<=n;i++){
			int t=pp[i].first;
			if(book[t])continue;
			cout<<t<<' ';
		}
	}
	return 0;
}