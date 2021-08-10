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
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8;
typedef long long ll;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int main(){
	int T;gi(T);
	while(T--){
		int n;gi(n);
		int flag=0;
		for(int i=2;i<=100000;i++){
			ll j=i;
			if(j*(j-1)/2>n){
				flag=j-1;
				break;
			}
		}
		if(n==1){
			printf("1337\n");
			continue;
		}
		else if(n==2){
			printf("11337\n");
			continue;
			
		}
		int t=flag;
		printf("133");
		n-=1LL*flag*(1LL*flag-1)/2;
		for(int i=1;i<=n;i++){
			printf("7");
		}
		for(int i=1;i<=t-2;i++){
			printf("3");
		}
		printf("7\n");
	}
	
	
	return 0;
}
