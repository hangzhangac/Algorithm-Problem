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
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
//0 min
//1 max

struct Node{
	int val;
	int num;
	Node(int x,int y){
		val=x;num=y;
	}
	Node(){}
};
int a[MAXN];
vector<int>G[MAXN];
vector<Node>T[MAXN];
int n;
bool cmp1(Node a,Node b){//max
	return a.val-a.num>b.val-b.num;
}
bool cmp2(Node a,Node b){//min
	return a.val>b.val;
}
void dfs(int u,int f){
	int sum=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f)continue;
		dfs(v,u);
	}
	if(G[u].size()==0){
		T[f].push_back(Node(1,1));
		return;
	}
	for(int i=0;i<T[u].size();i++){
		Node e=T[u][i];
		sum+=e.num;
	}
	int mm;
	if(a[u]==0){//min
		int ans=0x3f3f3f;
		int sum1=0;
		sort(T[u].begin(),T[u].end(),cmp2);
		for(int i=0;i<T[u].size();i++){
			ans=min(ans,T[u][i].val+sum1);
			sum1+=T[u][i].num;
		}
		mm=ans;
	}
	else{//max
		int ans=0;
		sort(T[u].begin(),T[u].end(),cmp1);
		for(int i=0;i<T[u].size();i++){
			ans=max(ans,T[u][i].val+sum-T[u][i].num);
		}
		mm=ans;
	}
	T[u].clear();
	T[f].push_back(Node(mm,sum));
	
}
int main(){
	
	gi(n);
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	for(int i=2;i<=n;i++){
		int x;gi(x);
		G[x].push_back(i);
	}
	dfs(1,0);
	printf("%d\n",T[0][0].val);
	return 0;
}