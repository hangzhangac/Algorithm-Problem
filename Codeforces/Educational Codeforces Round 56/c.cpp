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
#include <stack>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll a[MAXN];
ll b[MAXN];
int main(){
	
	int n;
	gi(n);
	for(int i=1;i<=n/2;i++){
		scanf("%lld",&b[i]);
	}
	a[1]=0;
	a[n]=b[1];
	for(int i=2;i<=n/2;i++){
		ll pre=a[n-i+1+1];
		ll minn=a[i-1];
		if(b[i]-a[i-1]>pre){
			minn+=b[i]-a[i-1]-pre;
		}
		a[i]=minn;
		a[n-i+1]=b[i]-minn;
	}
	for(int i=1;i<=n;i++){
		printf("%lld ",a[i]);
	}
	
	
	
	return 0;
}

