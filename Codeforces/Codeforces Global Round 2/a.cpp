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
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN];
//int t[MAXN];
int main(){
	
	int n;
	gi(n);
	for(int i=1;i<=n;i++){
		int x;gi(x);
		a[i]=x;
	}
	if(a[1]!=a[n]){
		printf("%d\n",n-1);
		return 0;
	}
	int maxn=1;
	for(int i=2;i<=n-1;i++){
		if(a[i]!=a[1]){
			maxn=max(maxn,i-1);
			maxn=max(maxn,n-i);
		}
	}
	
	printf("%d\n",maxn);
	
	
	
	
	
	return 0;
}















