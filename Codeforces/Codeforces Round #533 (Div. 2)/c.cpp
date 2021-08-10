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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll dp[MAXN][3];
ll a[4];
int main(){
	
	int n,l,r;
	cin>>n>>l>>r;
	int t=l%3;
	while(l<=r&&l%3!=0){
		a[l%3]++;
		l++;
	}
	while(r>=l&&r%3!=2){
		a[r%3]++;
		r--;
	}
	if(r>=l){
		for(int i=0;i<3;i++){
			a[i]+=(r-l+1)/3;
		}
	}
	for(int i=0;i<3;i++)dp[0][0]=1;
	for(int i=1;i<=n;i++){
		dp[i][0]=dp[i-1][0]*a[0]%mod;
		dp[i][0]+=dp[i-1][1]*a[2]%mod;
		dp[i][0]+=dp[i-1][2]*a[1]%mod;
		
		dp[i][1]=dp[i-1][0]*a[1]%mod;
		dp[i][1]+=dp[i-1][1]*a[0]%mod;
		dp[i][1]+=dp[i-1][2]*a[2]%mod;
		
		dp[i][2]=dp[i-1][0]*a[2]%mod;
		dp[i][2]+=dp[i-1][1]*a[1]%mod;
		dp[i][2]+=dp[i-1][2]*a[0]%mod;
	}
	printf("%lld\n",dp[n][0]%mod);
	
	
	
	return 0;
	
}