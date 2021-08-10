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
int n,m;
int a[MAXN];
int main(){
	
	cin>>n>>m;
//	int maxn=0;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		gi(a[i]);
		cnt+=a[i];
	//	maxn=max(a[i],maxn);
	}
	if(n==1){
		printf("%d\n",0);
		return 0;
	}
	sort(a+1,a+n+1);
	int t=a[n];
	int cur=1;
	for(int i=n-1;i>=1;i--){
		cur+=max(t-a[i],1);
		if(t-a[i]>1){
			t=a[i];
		}
		else{
			t--;
		}	
	}
	if(t>1){
		cur+=t-1;
	}
	printf("%lld\n",cnt-cur);
	
	
	return 0;
}