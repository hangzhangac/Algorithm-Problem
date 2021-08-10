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
int sum[MAXN];
int a[MAXN];
int main(){
	int n;
	gi(n);
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int q;
	gi(q);
	while(q--){
		int l,r;
		gi2(l,r);
		int t=sum[r]-sum[l-1];
		printf("%d\n",t/10);
	}
	
	
	
	
	return 0;
}