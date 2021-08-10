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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int x[MAXN],y[MAXN];
int main(){
	
	int n;
	gi(n);
	int curx=0,cury=0;
	for(int i=1;i<=n;i++){
		gi2(x[i],y[i]);
	}
	x[0]=y[0]=0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(x[i]==y[i]){
			ans+=min(x[i]-x[i-1],y[i]-y[i-1]);
			continue;
		}
		if(x[i-1]>=y[i-1]){
			if(y[i]<x[i-1])continue;
			else{
				ans+=min(x[i],y[i])-x[i-1]+1;
			}
		}
		else{
			if(x[i]<y[i-1])continue;
			else{
				ans+=min(x[i],y[i])-y[i-1]+1;
			}
		}
	}
	if(x[n]==y[n])ans++;
	printf("%lld\n",ans);
	
	return 0;
}







