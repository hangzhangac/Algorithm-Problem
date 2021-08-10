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
int a[MAXN];
int main(){
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	int ans1=0,ans2=0x3f3f3f3f;
	for(int t=1;t<=101;t++){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=t+1){
				sum+=a[i]-t-1;
			}
			else if(a[i]<=t-1){
				sum+=t-1-a[i];
			}
		}
		if(ans2>sum){
			ans2=sum;
			ans1=t;
		}
	}
	printf("%d %d\n",ans1,ans2);
	
	
	
	return 0;
}

















