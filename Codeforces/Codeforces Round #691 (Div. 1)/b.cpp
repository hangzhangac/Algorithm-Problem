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
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=105;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;
int a[MAXN],b[MAXN];

int dp[MAXN][10001];
int main(){
	
	int n,sum=0;
	gi(n);
	mem(dp,-1);
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=b[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=0;
		for(int k=i;k>=1;k--){
			for(int j=10000;j>=a[i];j--){
				if(dp[k-1][j-a[i]]!=-1)
					dp[k][j]=max(dp[k][j],dp[k-1][j-a[i]]+b[i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=1;j<=10000;j++){
			if(dp[i][j]!=-1)
				ans=max(ans,2*dp[i][j]+min(2*j-2*dp[i][j],sum-dp[i][j]));
		}
		cout<<1.0*ans/2<<endl;
	}
	return 0;
}





















