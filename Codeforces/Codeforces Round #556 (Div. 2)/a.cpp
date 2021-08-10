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
const int MAXN=105;
int n,m,r;
int b[MAXN];
int s[MAXN];
int dp[1005];
int main(){
	
	cin>>n>>m>>r;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	int maxn=r;
	sort(s+1,s+n+1);
	sort(b+1,b+m+1);
	int t=r/s[1];
	t*=b[m];
	t+=r%s[1];
	printf("%d",max(maxn,t));
	
	
	
	return 0;
}