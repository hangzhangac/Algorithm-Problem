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
const int MAXN=65005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char a[MAXN];
int main(){
	
	int n;
	gi(n);
	scanf("%s",a);
	ll ans=0;
	for(int i=0;i<n;i++){
		a[i]-='0';
		if((a[i]&1)==0){
			ans+=i+1;
		}
	}
	printf("%lld\n",ans);
	
	
	
	
	
	
	return 0;
}












