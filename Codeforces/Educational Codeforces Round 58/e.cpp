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
const int MAXN=500005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int main(){
	int n;
	char s[5];
	gi(n);
	int maxl=0,maxr=0;
	int x,y;
	while(n--){
		scanf("%s",s);
		scanf("%d%d",&x,&y);
		if(x>y)swap(x, y);
		if(s[0]=='+'){
			maxl=max(maxl,x);
			maxr=max(maxr,y);
		}
		else{
			if(x>=maxl&&y>=maxr){
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}
	return 0;
}















