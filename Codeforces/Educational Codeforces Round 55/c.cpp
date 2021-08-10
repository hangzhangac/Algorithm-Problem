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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
vector<int>G[MAXN];
vector<int>sum[MAXN];
bool cmp(int a,int b){
	return a>b;
}
bool cmp1(int a,int b){
	return G[a].size()>G[b].size();
}
int n,m;
int id[MAXN];
int main(){
	gi2(n,m);
	for(int i=1;i<=n;i++){
		int x,y;
		gi2(x, y);
		G[x].push_back(y);
	}
	int ans=0;
	int maxn=0;
	for(int i=1;i<=m;i++){
		id[i]=i;
		maxn=max(maxn,(int)G[i].size());
		sort(G[i].begin(),G[i].end(),cmp);
		for(int j=0;j<G[i].size();j++){
			if(j==0){
				sum[i].push_back(G[i][j]);
			}
			else sum[i].push_back(sum[i][j-1]+G[i][j]);
		}
	}
	sort(id+1,id+m+1,cmp1);
	for(int i=1;i<=maxn;i++){
		int s=0;
		for(int j=1;j<=m;j++){
			int q=G[id[j]].size();
			if(q<i)break;
			if(sum[id[j]][i-1]>0)
			s+=sum[id[j]][i-1];
		}
		ans=max(ans,s);
	}
	printf("%d\n",ans);
}

