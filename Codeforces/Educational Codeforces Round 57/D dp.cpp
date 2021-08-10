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
const int MAXN=100005;
const ll mod=1e9+7;
const ll inf=1e18+1;
ll dp[MAXN][2][5];
ll a[MAXN];
char s[MAXN];
int main(){
	
	int n;
	gi(n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		gll(a[i]);
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<=4;k++){
				dp[i][j][k]=1e18+1;
			}
		}
	}
	dp[0][1][0]=dp[0][0][0]=0;
	//0不删   1删
	
	for(int i=1;i<=n;i++){
		for(int k=0;k<=4;k++){
			dp[i][0][k]=dp[i][1][k]=min(dp[i-1][0][k],dp[i-1][1][k]);
		}
		if(s[i]=='h'){
			ll s=dp[i-1][0][0],t=dp[i-1][1][0];
			ll ans=inf;
			ans=min(s,t);
			dp[i][0][1]=ans;
			if(ans!=inf)
			dp[i][0][0]=inf;
			if(dp[i][1][0]!=inf)
			dp[i][1][0]+=a[i];
		}else if(s[i]=='a'){
			ll s=dp[i-1][0][1],t=dp[i-1][1][1];
			ll ans=inf;
			ans=min(s,t);
			dp[i][0][2]=ans;
			if(ans!=inf)
			dp[i][0][1]=inf;
			if(dp[i][1][1]!=inf)
			dp[i][1][1]+=a[i];
		}else if(s[i]=='r'){
			ll s=dp[i-1][0][2],t=dp[i-1][1][2];
			ll ans=inf;
			ans=min(s,t);
			dp[i][0][3]=ans;
			if(ans!=inf)
			dp[i][0][2]=inf;
			if(dp[i][1][2]!=inf)
			dp[i][1][2]+=a[i];		
		}else if(s[i]=='d'){
			ll s=dp[i-1][0][3],t=dp[i-1][1][3];
			ll ans=inf;
			ans=min(s,t);
			dp[i][0][4]=ans;
			if(ans!=inf)
			dp[i][0][3]=inf;
			if(dp[i][1][3]!=inf)
			dp[i][1][3]+=a[i];	
		}else{
			
		}
	}
	ll minn=1e18+1;
	for(int i=0;i<4;i++){
		minn=min(dp[n][0][i],minn);
		minn=min(dp[n][1][i],minn);
	}
	printf("%lld\n",minn);
	
	
	
	return 0;
}






