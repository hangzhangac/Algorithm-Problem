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
const int MAXN=2005;
const ll mod=100000;
const int inf=0x3f3f3f3f;
ll a[MAXN];
int main(){
	
	int n;
	gi(n);
	for(int i=1;i<=n;i++){
		gll(a[i]);
	}
	ll pl=0;
	printf("%d\n",n+1);
	for(int i=n;i>=1;i--){
		a[i]+=pl;
		int t=a[i]%mod;
		int ans=0;
		if(t<=i){
			ans=i-t;
		}
		else{
			ans=mod+i-t;
		}
		printf("1 %d %d\n",i,ans);
		pl+=ans;
	}
	printf("2 %d %lld\n",n,mod);
	return 0;
}











