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
const int MAXN=17;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n,T;
int a[MAXN],b[MAXN];
ll dp[1<<15][226][4];
ll dfs(int sta,int T,int g){
	if(T==0) return 1;
	if(T<0) return 0;
	if(dp[sta][T][g]!=-1)return dp[sta][T][g];
	ll ans=0;
	for(int i=0;i<n;i++){
		if(!(sta&(1<<i))&&b[i]!=g){
			ans=(ans+dfs(sta|(1<<i), T-a[i], b[i]))%mod;
		}
	}
	return dp[sta][T][g]=ans;
	
}
int main(){
	
	gi2(n,T);
	mem(dp,-1);
	for(int i=0;i<n;i++){
		gi2(a[i],b[i]);
	}
	printf("%lld\n",dfs(0,T,0));
	
	
	return 0;
}