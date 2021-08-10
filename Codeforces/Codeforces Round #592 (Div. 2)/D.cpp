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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[3][MAXN];
vector<int>G[MAXN];
int in[MAXN],col[MAXN];
ll dfs(int u,int cur_col,int nex_col,int f){
	col[u]=cur_col;
	ll ans=a[cur_col][u];
	int ne;
	for(int i=0;i<3;i++){
		if(i!=cur_col&&i!=nex_col){
			ne=i;break;
		}
	}
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f)continue;
		ans+=dfs(v,nex_col,ne,u);
	}
	return ans;
	
}
int main(){
	
	int n;gi(n);
	for(int i=0;i<3;i++){
		for(int j=1;j<=n;j++){
			gi(a[i][j]);
		}
	}
	for(int i=1;i<=n-1;i++){
		int x,y;
		gi2(x,y);
		G[x].push_back(y);
		G[y].push_back(x);
		in[x]++,in[y]++;
	}
	int flag=0,cnt2=0,cnt1=0,root=-1;
	for(int i=1;i<=n;i++){
		if(in[i]==1){root=i;cnt1++;}
		else if(in[i]==2) cnt2++;
		else{
			flag=1;break;
		}
	}
	if(cnt1!=2){
		flag=1;
	}
	if(flag){
		printf("-1\n");return 0;
	}
	int pos1=0,pos2=0;
	ll minn=1e18+1;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i!=j){
				ll ans=dfs(root,i,j,-1);
				if(minn>ans){
					minn=ans;
					pos1=i,pos2=j;
				}
			}
		}
	}
	cout<<dfs(root,pos1,pos2,-1)<<endl;
	for(int i=1;i<=n;i++){
		printf("%d ",col[i]+1);
	}
	return 0;
}





