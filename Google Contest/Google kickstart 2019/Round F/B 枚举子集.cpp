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
const int MAXN=50005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
vector<int>G[MAXN];
map<vector<int> , int>mt;
int c[MAXN];
ll cnt=0;
void dfs(int cur,int c,vector<int>& ans,vector<int>&G ){
	
	if(cur==c){
		cnt+=mt[ans];
		return ;
	}
	dfs(cur+1,c,ans,G);
	ans.push_back(G[cur]);
	dfs(cur+1,c,ans,G);
	ans.pop_back();
	
}
int main(){
	
	int TT,cnt1=1;gi(TT);while(TT--){
		int n,s;
		gi2(n,s);
		cnt=0;
		for(int i=1;i<=n;i++){
			gi(c[i]);
			for(int j=0;j<c[i];j++){
				int x;gi(x);
				G[i].push_back(x);
			}
			sort(G[i].begin(),G[i].end());
		}
		for(int i=1;i<=n;i++){
			vector<int>ans;
			dfs(0,c[i],ans,G[i]);
			mt[G[i]]++;
		}
		mt.clear();
		for(int i=n;i>=1;i--){
			vector<int>ans;
			dfs(0,c[i],ans,G[i]);
			mt[G[i]]++;
		}
		printf("Case #%d: %lld\n",cnt1++,1ll*n*(n-1)-cnt);
		for(int i=1;i<=n;i++)G[i].clear();mt.clear();
		
	}
	return 0;
}