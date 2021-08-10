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
const int MAXN=400005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN];
int p[MAXN];
int book[MAXN];
int main(){
	int n;
	gi(n);
	for(int i=2;i<=n;i++){
		gi(p[i]);
	}
	
	a[1]=1;
	int minn=1;
	for(int i=2;i<=n;i++){
		a[i]=a[i-1]+p[i];
		minn=min(minn,a[i]);
	}
	
	for(int i=1;i<=n;i++){
		a[i]=a[i]-minn+1;
		if(a[i]<1||a[i]>n){
			printf("-1\n");
			return 0;
		}
		book[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(book[i]!=1){
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	
	
	
	
	return 0;
}




