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
	
	int n,v;
	cin>>n>>v;
	int cur=0;
	int num=0;
	for(int i=1;i<=n;i++){
		if(i==n)break;
		int res=n-i;
		if(cur<res){
			num+=min(res-cur,v-cur)*i;
			cur+=min(res-cur,v-cur);
		}
		if(cur>=res){
			break;
		}
		cur--;
	}
	printf("%d\n",num);
	
	
	
	return 0;
}


















