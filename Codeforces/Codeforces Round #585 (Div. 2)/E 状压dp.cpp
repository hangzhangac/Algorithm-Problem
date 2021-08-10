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
const int MAXN=400005;
const ll mod=1e9+7;
const ll inf=(ll)1e18;
ll sum[MAXN];
vector<int>G[25];
int n;
ll cnt[25][25];
ll dp[1<<20];
void init(){
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			if(i==j||!G[i].size()||!G[j].size())continue;
			ll ans=0;
			for(int k=0;k<G[i].size();k++){
				int x=G[i][k];
				int t=lower_bound(G[j].begin(), G[j].end(), x)-G[j].begin();
				ans+=t;
			}
			cnt[i][j]=ans;
		}
	}
	return ;
}
int main(){
	
	gi(n);
	for(int i=1;i<=n;i++){
		int x;gi(x);
		x--;
		G[x].push_back(i);
	}
	init();
	mem(dp,0x3f);
	dp[0]=0;
	for(int s=0;s<(1<<20);s++){
		for(int i=0;i<20;i++){
			if(((1<<i)&s)==0){
				ll ans=0;
				for(int j=0;j<20;j++){
					if(((1<<j)&s)!=0){
						ans+=cnt[j][i];
					}
				}
				dp[s|(1<<i)]=min(dp[s|(1<<i)],dp[s]+ans);
			}
		}
	}
	printf("%lld\n",dp[(1<<20)-1]);
	return 0;
}










