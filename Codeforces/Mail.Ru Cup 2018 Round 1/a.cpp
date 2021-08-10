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
	
	int x,y,z;
	int t1,t2,t3;
	cin>>x>>y>>z>>t1>>t2>>t3;
	int ans0=abs(z-x)*t2+t3*3+abs(y-x)*t2;
	int ans1=abs(x-y)*t1;
	if(ans0<=ans1){
		printf("YES\n");
	}
	else printf("NO\n");
	
	
	
	return 0;
}






































