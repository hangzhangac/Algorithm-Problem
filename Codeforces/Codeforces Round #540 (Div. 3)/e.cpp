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
int main(){
	ll n,k;
	gll2(n,k);
	ll sum=k*(k-1);
	if(sum<n){
		printf("NO\n");return 0;
	}
	printf("YES\n");
	int c=1,p=c+1;
	int flag=0;
	if(n&1){n--;flag=1;}
	while(n){
		n-=2;
		printf("%d %d\n",c,p);
		printf("%d %d\n",p,c);
		p++;
		if(p>k){
			c++;p=c+1;
		}
	}
	if(flag){
		printf("%d %d\n",c,p);
	}
	
	
	
	return 0;
}








