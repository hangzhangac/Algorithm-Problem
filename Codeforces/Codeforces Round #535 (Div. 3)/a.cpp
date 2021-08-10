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
	
	int T;
	gi(T);
	while(T--){
		int l1,l2,r1,r2;
		cin>>l1>>r1>>l2>>r2;
		int flag=0;
		if(l1>l2){
			swap(l2,l1);
			swap(r2,r1);
			flag=1;
		}
		int ans1,ans2;
		ans1=l1;ans2=r2!=l1?r2:r2-1;
		if(flag)swap(ans1,ans2);
		printf("%d %d\n",ans1,ans2);
	
	}
	
	
	
	return 0;
}