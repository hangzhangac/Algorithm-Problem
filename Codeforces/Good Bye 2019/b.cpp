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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN];

int main(){
	int T;
		gi(T);
		while(T--){
			int n;
			gi(n);
			int flag=0;

			for(int i=1;i<=n;i++)
				gi(a[i]);
			for(int i=1;i<=n;i++){
				if(i>=2){
					int diff=abs(a[i]-a[i-1]);
					if(diff>=2){
						printf("YES\n");
						printf("%d %d\n",i-1,i);
						flag=1;
						break;
					}
				}
			}
			if(flag==0)
				printf("NO\n");
			
		}
	return 0;
}


