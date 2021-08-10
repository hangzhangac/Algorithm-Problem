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
int dp[1<<20],a[1<<20];
char ss[MAXN];
int num[20][20];
int main(){
	
	int n,m;
	gi2(n,m);
	scanf("%s",ss+1);
	for(int i=2;i<=n;i++){
		int s=ss[i-1]-'a';
		int t=ss[i]-'a';
		if(s==t)continue;
		num[s][t]++;num[t][s]++;
	}
	mem(dp,0x3f);
	dp[0]=0;
	for(int s=0;s<(1<<m);s++){
		int ans=0;
		for(int j=0;j<m;j++){
			if( ( ((1<<j)&s)==0) )continue;
			for(int k=0;k<m;k++){
				if( ( ((1<<k)&s)==0 )  ){
					ans+=num[j][k];
				}
			}
		}
		a[s]=ans;
	}
	for(int s=0;s<(1<<m);s++){
		for(int i=0;i<m;i++){
			if(((1<<i)&s)==0){
				dp[s|(1<<i)]=min(dp[s|(1<<i)],dp[s]+a[s|(1<<i)]);
			}
		}
	}
	cout<<dp[(1<<m)-1]<<endl;
	return 0;
}