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
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=1005;
const ll mod=998244353;
const int inf=0x3f3f3f3f;
int n;
int c[MAXN];
int s[MAXN];
int dp[MAXN][10];
int main(){
	cin>>n;
	string st;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		cin>>st;
		int num=0;
		for(int i=0;i<st.size();i++){
			if(st[i]=='A'){
				num+=1;
			}
			else if(st[i]=='B'){
				num+=2;
			}
			else{
				num+=4;
			}
		}
		s[i]=num;
	}
	mem(dp,inf);
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		dp[i][0]=0;
	}
	//cout<<s[3]<<endl;
	for(int i=1;i<=n;i++){
		for(int j=0;j<8;j++){
			//dp[i][j]=dp[i-1][j
			if((s[i]|j)-j){
				dp[i][s[i]|j]=min(dp[i][s[i]|j],dp[i-1][j]+c[i]);
				//if(i==3&&j==0)cout<<dp[3][7]<<endl;
				
			}
		}
		for(int j=0;j<8;j++){
			dp[i][j]=min(dp[i][j],dp[i-1][j]);
		}
	}
	
	//int ans=inf;
	if(dp[n][7]==inf){
		printf("-1\n");
	}
	else printf("%d\n",dp[n][7]);
}