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
		int a,b,r,c;
		cin>>a>>b>>c>>r;
		int z=c-r,y=c+r;
		if(a>b)swap(a,b);
		int ans=0;
		if(z>=b)ans=0;
		else if(y<=a)ans=0;
		else{
			int xx=min(y,b);
			int yy=max(z,a);
			ans=xx-yy;
		}
		printf("%d\n",b-a-ans);
	}
	
	
	return 0;
}

















