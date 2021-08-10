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
const int MAXN=500005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
vector<int>G[MAXN];
vector<int>T[MAXN];
ll dp[MAXN][2];
struct Node{
	ll a,b;
	ll diff;
	Node(int u,int v){
		a=u,b=v;
		diff=a-b;
	}
};
bool cmp(Node a,Node b){
	return a.diff<b.diff;
}
int n,k;
void dfs(int u,int f,int val){
	dp[u][0]=0;
	dp[u][1]=val;
	vector<Node>q;
	ll cnt0=0,cnt1=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i],w=T[u][i];
		if(v==f)continue;
		dfs(v,u,w);
		cnt1+=dp[v][1],cnt0+=dp[v][0];
		q.push_back(Node(dp[v][0],dp[v][1]));
	}
	ll sum=cnt0+cnt1,s=cnt1;
	sort(q.begin(),q.end(),cmp);
	cnt0=0;
	for(int i=0;i<min((int)q.size(),k);i++){
		Node e=q[i];
		if(e.a>e.b){
			break;
		}
		cnt0+=e.a;
		cnt1-=e.b;
	}
	dp[u][0]=sum-(cnt1+cnt0);
	cnt0=0;cnt1=s;
	for(int i=0;i<min((int)q.size(),k-1);i++){
		Node e=q[i];
		if(e.a>e.b){
			break;
		}
		cnt0+=e.a;
		cnt1-=e.b;
	}
	dp[u][1]+=sum-(cnt1+cnt0);
	return;
}
int main(){
	int q;gi(q);while(q--){
		gi2(n,k);
		for(int i=1;i<=n;i++){
			G[i].clear();
			T[i].clear();
		}
		for(int i=1;i<=n-1;i++){
			int u,v,w;
			gi3(u,v,w);
			G[u].push_back(v);
			T[u].push_back(w);
			G[v].push_back(u);
			T[v].push_back(w);
		}
		dfs(1,-1,0);
		printf("%lld\n",dp[1][0]);
	}
	return 0;
	
}