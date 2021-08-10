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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
vector<int>G[MAXN];
int n;
int c[MAXN];
int a[MAXN];
int book[MAXN];
int in[MAXN];
void dag(){
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(!in[i]){
			q.push(i);
			book[i]=1;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(book[v])continue;
			in[v]--;
			if(!in[v]){
				q.push(v);
				book[v]=1;
			}
		}
	}
}
int bfs(int s){
	queue<int>q;
	q.push(s);
	int minn=c[s];
	while(!q.empty()){
		int u=q.front();
		q.pop();
		book[u]=1;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(book[v])continue;
			if(v==s)return minn;
			minn=min(c[v],minn);
			q.push(v);
			book[v]=1;
		}
	}
	return minn;
}
int main(){
	gi(n);
	for(int i=1;i<=n;i++){
		gi(c[i]);
	}
	for(int i=1;i<=n;i++){
		gi(a[i]);
		G[i].push_back(a[i]);
		in[a[i]]++;
	}
	dag();
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(book[i])continue;
		int minn=bfs(i);
		ans+=minn;
	}
	printf("%lld\n",ans);
	
	
	
}































