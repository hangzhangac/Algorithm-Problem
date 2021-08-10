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
int a[MAXN];
int n,k,m;
int main(){
	gi3(n,k,m);
	double sum=0;
	a[0]=0;
	for(int i=1;i<=n;i++){
		gi(a[i]);
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	double maxn=0.0;
	double l=1.0,r=2000000.0;
	double cnt=0;
	for(int i=0;i<=n-1;i++){
		sum-=a[i];
		int sur=m-i;
		if(sur<0)break;
		int ge=n-i;
		double ss=sum+min(1LL*sur,1LL*ge*k);
		maxn=max(maxn,ss/ge);
	}
	printf("%.10lf\n",maxn);
	
	return 0;
}






















