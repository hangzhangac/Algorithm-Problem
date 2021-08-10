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
const int MAXN=300005;
const ll mod=1e9+7;
const ll inf=1e18+1;
ll a[MAXN],b[MAXN];
ll sum[MAXN];
ll dp[MAXN][3];
int main(){
	int T;
	gi(T);while(T--){
		int n;
		gi(n);
		for(int i=1;i<=n;i++)
			for(int j=0;j<=2;j++)dp[i][j]=inf;
		for(int i=1;i<=n;i++){
			gll2(a[i],b[i]);
		}
		dp[1][0]=0;
		dp[1][1]=b[1];
		dp[1][2]=b[1]*2;
		for(int i=2;i<=n;i++){
			for(int j=0;j<=2;j++){
				for(int k=0;k<=2;k++){
					if(a[i-1]+j!=a[i]+k){
						dp[i][k]=min(dp[i][k],dp[i-1][j]+b[i]*k);
					}
				}
			}
		}
		printf("%lld\n",min(min(dp[n][0],dp[n][1]),dp[n][2]));
	}
	return 0;
}










