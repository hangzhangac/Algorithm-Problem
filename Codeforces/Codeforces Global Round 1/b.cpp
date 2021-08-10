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
int n,m,k;
int a[MAXN];
ll sum=0;
int main(){
	gi3(n,m,k);
	for(int i=0;i<n;i++){
		gi(a[i]);
	}
	if(n==1){
		printf("%d\n",1);
		return 0;
	}
	for(int i=1;i<n;i++){
		a[i-1]=a[i]-a[i-1]-1;
	}
	sort(a,a+n-1);
	ll ans=n;
	for(int i=0;i<n-k;i++){
		ans+=a[i];
	}
	printf("%lld\n",ans);
	
	
	
	
	
	
	return 0;
}












