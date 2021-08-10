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
ll dp[11][1005][1005];
ll sum[1005][1005];
int n,m;
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum[i][j]=0;
		}
	}
}
int main(){
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[1][i][j]=1;
		}	
	}
	for(int j=1;j<=n;j++){
		for(int k=n;k>=j;k--){
			sum[j][k]=sum[j-1][k]+sum[j][k+1]-sum[j-1][k+1]+dp[1][j][k];
			sum[j][k]%=mod;
		}
	}
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				dp[i][j][k]+=sum[j][k]%mod;
				dp[i][j][k]%=mod;
			}
		}
		//init();
		for(int j=1;j<=n;j++){
			for(int k=n;k>=j;k--){
				sum[j][k]=sum[j-1][k]+sum[j][k+1]-sum[j-1][k+1]+dp[i][j][k];
				sum[j][k]%=mod;
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans+=dp[m][i][j];
			ans%=mod;
		}
	}
	cout<<(ans%mod)<<endl;
	
	
	return 0;
}













