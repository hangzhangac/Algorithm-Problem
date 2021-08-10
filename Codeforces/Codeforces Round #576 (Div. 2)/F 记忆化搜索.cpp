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
const int MAXN=52;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char a[MAXN][MAXN];
int f[MAXN][MAXN][MAXN][MAXN];
int sum[MAXN][MAXN];
int cal(int x,int y,int xx,int yy){
	return sum[xx][yy]+sum[x-1][y-1]-sum[xx][y-1]-sum[x-1][yy];
}
int dfs(int x,int y,int xx,int yy){
	if(f[x][y][xx][yy]!=inf)return f[x][y][xx][yy];
	if(cal(x,y,xx,yy)==0)return f[x][y][xx][yy]=0;
	int minn=max(xx-x+1,yy-y+1);
	for(int i=x;i<=xx-1;i++){
		minn=min(minn,dfs(x,y,i,yy)+dfs(i+1,y,xx,yy));
	}
	for(int i=y;i<=yy-1;i++){
		minn=min(minn,dfs(x,y,xx,i)+dfs(x,i+1,xx,yy));
	}
	return f[x][y][xx][yy]=minn;
}
int main(){
	
	int n;gi(n);
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(a[i][j]=='#'?1:0);
		}
	}
	mem(f,0x3f);
	printf("%d\n",dfs(1,1,n,n));
	
	
	
	return 0;
}