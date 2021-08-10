#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>
#define lson i<<1
#define rson i<<1|1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define gc(x) scanf("%c",&x)
#define gc2(x,y) scanf("%c%c",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const double PI = acos(-1.0); 
const int MAXN=100005;
const ll mod=1e7+9;
const ll llinf = (ll)(1e18) + 500;
const int inf=0x3f3f3f3f;
int a[53][33];
int sum[53][33];
int dp[53][1550];
int main(){
	
	int T;
	gi(T);
	int cnt1=1;
	while(T--){
		int n,k,p;
		gi2(n,k);gi(p);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				gi(a[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				sum[i][j]=sum[i][j-1]+a[i][j];
				
			}
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=p;j++){
				dp[i][j]=-1;
			}
		}
		dp[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=p;j++){
				for(int q=max(0,j-k);q<=j;q++){
					if(dp[i-1][q]!=-1&&j-q<=k)
						dp[i][j]=max(dp[i][j],dp[i-1][q]+sum[i][j-q]);
				}
			}
		}
		printf("Case #%d: %d\n",cnt1++,dp[n][p]);
		
		
	}
	
	
	return 0;	
}