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
const int MAXN=5005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
vector< pair<int,int> > G[MAXN];
int book[MAXN];
int color[MAXN],in[MAXN];
int u[MAXN],v[MAXN];
int n,m;
bool judge(){
	queue<int>q;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!in[i]){q.push(i);cnt++;}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto p:G[u]){
			int v=p.first;
			in[v]--;
			if(!in[v]){cnt++;q.push(v);}
		}
	}
	return cnt==n;
}
int main(){
 
	gi2(n,m);
	for(int i=1;i<=m;i++){
		gi2(u[i],v[i]);
		G[u[i]].push_back(make_pair(v[i],i));
		in[v[i]]++;
	}
	if(judge()){
		printf("1\n");
		for(int i=1;i<=m;i++){
			printf("1 ");
		}
	}
	else{
		
		printf("%d\n",2);
		for(int i=1;i<=m;i++){
			if(u[i]<v[i])printf("%d ",2);
			else printf("%d ",1);
		}
	}
	
	return 0;
}