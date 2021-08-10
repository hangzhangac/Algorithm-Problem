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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN];
int main(){
	int T;
	cin>>T;
	while(T--){
		ll n,x,y,d;
		cin>>n>>x>>y>>d;
		ll minn=10000000000000000;
		ll t=abs(y-x);
		if(t%d==0){
			minn=min(t/d,minn);
		}
		ll q=(x-1)/d+1;
		t=y-1;
		if(t%d==0){
			minn=min(t/d+q,minn);
		}
		q=(n-x)/d+1;
		t=n-y;
		if(t%d==0){
			minn=min(t/d+q,minn);
		}
		if(minn==10000000000000000)minn=-1;
		printf("%lld\n",minn);
	}
	return 0;
}































