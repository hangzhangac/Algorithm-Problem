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
const int MAXN=500005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int f[MAXN][20];
int main(){
	
	int n,m;
	gi2(n,m);
	int maxn=0;
	for(int i=1;i<=n;i++){
		int x,y;
		gi2(x,y);
		x++,y++;
		f[x][0]=max(f[x][0],y);
		maxn=max(y,maxn);
	}
	for(int i=1;i<=maxn;i++){
		f[i][0]=max(f[i-1][0],f[i][0]);
	}
	for(int j=1;j<=19;j++){
		for(int i=0;i<=maxn;i++){
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	while(m--){
		int x,y;
		gi2(x,y);
		x++,y++;
		int ans=0;
		if(f[x][19]<y){
			printf("-1\n");
			continue;
		}
		for(int i=19;i>=0;i--){
			if(f[x][i]<y){
				ans+=1<<i;
				x=f[x][i];
			}
		}
		ans++;
		printf("%d\n",ans);
	}
	return 0;
}





