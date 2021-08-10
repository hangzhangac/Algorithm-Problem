#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>
#define lson i<<1
#define rson i<<1|1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define gc(x) scanf("%c",&x)
#define gc2(x,y) scanf("%c%c",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const double PI = acos(-1.0); 
const int MAXN=100002;
const ll mod=1e7+9;
const ll llinf = (ll)(1e18) + 500;
const int inf=0x3f3f3f3f;
int n,p,k1;
struct Node{
	int a;
	int s[7];
}node[MAXN];
ll dp[MAXN][1<<7];
bool cmp(Node a,Node b){
	return a.a>b.a;
}
int main(){
	gi2(n,p);gi(k1);
	memset(dp,-0x3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		gi(node[i].a);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<p;j++){
			gi(node[i].s[j]);
		}
	}
	sort(node+1,node+n+1,cmp);
	dp[1][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<p);j++){
			int cnt=0;
			for(int k=0;k<p;k++){
				if(!((1<<k)&j))dp[i+1][j|(1<<k)]=max(dp[i+1][j|(1<<k)],dp[i][j]+node[i].s[k]);
				else cnt++;
			}
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]+(i<=cnt+k1?node[i].a:0));
		}
	}
	cout<<dp[n+1][(1<<p)-1]<<endl;
	return 0;
}