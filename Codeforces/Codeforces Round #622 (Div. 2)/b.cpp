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
	
	int T;
	gi(T);
	while(T--){
		ll n,x,y;
		cin>>n>>x>>y;
		ll t=x+y;
		ll ans0=0;
		ll ans1=0;
		if(x>y)swap(x,y);
		ll cnt=min(n-x,y-1);
		cnt+=min(n-y,x-1);
		if(x+y>n){
			cnt+=x+y-n-1;
			ans1=cnt;
		}
		else{
			ans1=cnt;
		}
		cnt=0;
		
		cnt+=min(max(0LL,y-1),max(0LL,n-(x+1)));
		cnt+=min(max(0LL,x-1),max(0LL,n-(y+1)));
		//printf("%lld\n",cnt);
		if(x+y>=n){
			//cnt+=x+y-n;
			ans0=cnt;
		}
		else{
			cnt+=n-(x+y);
			ans0=cnt;
		}
		if(x+1<=n&&y+1<=n){
			ans0++;
		}
		
		printf("%lld %lld\n",n-ans0,ans1+1);
		
	}
	return 0;
}
