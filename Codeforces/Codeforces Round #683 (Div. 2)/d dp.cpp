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
const int MAXN=5005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;

int dp[MAXN][MAXN];
int main(){
	
	int n,m;
	gi2(n,m);
	string a,b;
	cin>>a>>b;
	int maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+2;
			}
			else dp[i][j]=max(dp[i-1][j]-1,dp[i][j-1]-1);
			dp[i][j]=max(0,dp[i][j]);
			maxn=max(dp[i][j],maxn);
		}
	}
	cout<<maxn<<endl;
	return 0;
}