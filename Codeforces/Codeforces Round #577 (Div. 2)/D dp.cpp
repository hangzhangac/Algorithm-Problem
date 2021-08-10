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
const ll inf=1000000000000000LL;
int b[MAXN];
int n,m,k,q;
int minn[MAXN],maxn[MAXN];
vector<int>r[3];
ll dp[MAXN][2];
ll judge(int id, int minn, int maxn,int flag,int bef){
	if(id<1||id>q)return inf;
	int x=b[id];
	int ans=0;
	if(flag==0)//停留在minn
		ans=abs(maxn-x)+maxn-minn;
	else//停留在maxn
		ans=abs(minn-x)+maxn-minn;
	return ans+abs(b[id]-bef);
}
int main(){
	
	scanf("%d%d%d%d",&n,&m,&k,&q);
	mem(minn,0x3f);
	mem(maxn,0);
	int maxx=0;
	for(int i=1;i<=k;i++){
		int r,c;
		gi2(r,c);
		minn[r]=min(minn[r],c);
		maxn[r]=max(maxn[r],c);
		maxx=max(r,maxx);
	}
	for(int i=1;i<=q;i++){
		gi(b[i]);
	}
	sort(b+1,b+q+1);
	if(maxn[1]==0){
		r[0].push_back(1);
		r[1].push_back(1);
		r[2].push_back(1);
		dp[0][0]=dp[0][1]=0;
	}
	else{
		r[0].push_back(1);
		r[1].push_back(maxn[1]);
		r[2].push_back(maxn[1]);
		dp[0][0]=dp[0][1]=maxn[1]-1;
	}
	for(int i=1;i<=maxx;i++){
		if(maxn[i]!=0&&i!=1){
			r[0].push_back(i);
			r[1].push_back(minn[i]);
			r[2].push_back(maxn[i]);
		}
		dp[i][0]=dp[i][1]=inf;
	}
	ll ans=0;
	for(int i=0;i<r[0].size()-1;i++){
		int mi_down=r[1][i],mx_down=r[2][i];
		int mi_up=r[1][i+1],mx_up=r[2][i+1];
		
		ans+=-r[0][i]+r[0][i+1];
		int sr=lower_bound(b+1, b+q+1, mi_down)-b;
		//由第i行的最左边出发,并通过>=其纵坐标的最小的可以上升的列
		dp[i+1][0]=min(dp[i+1][0],judge(sr, mi_up, mx_up, 0,mi_down)+dp[i][0]);
		dp[i+1][1]=min(dp[i+1][1],judge(sr, mi_up, mx_up, 1,mi_down)+dp[i][0]);
		
		//由第i行的最左边出发,并通过<其纵坐标的最大的可以上升的列
		dp[i+1][0]=min(dp[i+1][0],judge(sr-1, mi_up, mx_up, 0,mi_down)+dp[i][0]);
		dp[i+1][1]=min(dp[i+1][1],judge(sr-1, mi_up, mx_up, 1,mi_down)+dp[i][0]);
		
		//由第i行的最右边出发,并通过>=其纵坐标的最小的可以上升的列
		sr=lower_bound(b+1, b+1+q, mx_down)-b;
		dp[i+1][0]=min(dp[i+1][0],judge(sr, mi_up, mx_up, 0,mx_down)+dp[i][1]);
		dp[i+1][1]=min(dp[i+1][1],judge(sr, mi_up, mx_up, 1,mx_down)+dp[i][1]);
		
		//由第i行的最右边出发,并通过<其纵坐标的最大的可以上升的列
		dp[i+1][0]=min(dp[i+1][0],judge(sr-1, mi_up, mx_up, 0,mx_down)+dp[i][1]);
		dp[i+1][1]=min(dp[i+1][1],judge(sr-1, mi_up, mx_up, 1,mx_down)+dp[i][1]);
	}
	
	printf("%lld\n",ans+min(dp[r[0].size()-1][0],dp[r[0].size()-1][1]));
	
	return 0;
}