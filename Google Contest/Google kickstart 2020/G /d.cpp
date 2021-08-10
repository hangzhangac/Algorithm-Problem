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
const int inf=0x3f3f3f3f;
#define INF 0x3f3f3f3f
#define mod 1000000007
#define MAX_N 5000
using namespace std;
typedef pair<ll,int> P;
int t,n,a[MAX_N+5];
double dp[MAX_N+5][MAX_N+5];
int main(){
	dp[0][0]=0,dp[0][1]=dp[1][0]=1;
	for(int i=0;i<=MAX_N;i++){
		if(i>1)dp[i][0]=dp[i-1][0]+1.0/i;
		for(int j=1;j<=MAX_N-i;j++){
			if(i==0){if(j>1)dp[0][j]=dp[0][j-1]+1.0/j;}
			else{
				dp[i][j]=(i*dp[i-1][j]+j*dp[i][j-1]+2)/(i+j);
			}
		}
	}
	cin>>t;for(int cas=1;cas<=t;cas++){
		double ans=0;
		printf("Case #%d: ",cas);
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		for(int i=0;i<n;i++)ans+=dp[i][n-i-1]*a[i];
		printf("%.6f\n",ans);
	}
	return 0;
}










