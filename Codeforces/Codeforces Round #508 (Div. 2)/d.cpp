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
const int MAXN=500005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll a[MAXN];
ll b[MAXN];
int main(){
	
	int n;
	gi(n);
	int flagf=0;
	int flagz=0;
	int flagze=0;
	ll maxnf=-1000000001;
	ll minnz=1000000001;
	ll sum=0;
	for(int i=1;i<=n;i++){
		gll(a[i]);
		sum+=a[i];
		if(a[i]>0){
			flagz=1;
		}
		else if(a[i]<0){
			flagf=1;
		}
		else{
			flagze=1;
		}
		
		if(a[i]>=0){
			minnz=min(minnz,a[i]);
		}
		if(a[i]<=0){
			maxnf=max(maxnf,a[i]);
		}
	}
	if(n==1){
		printf("%lld\n",a[1]);
		return 0;
	}
	else if(n==2){
		printf("%lld\n",abs(a[1]-a[2]));
		return 0;
	}
	ll ans=0;
	if(flagz==0){
		ans=-sum+2*maxnf;
	}
	else if(flagf==0){
		ans=sum-2*minnz;
	}
	else{
		for(int i=1;i<=n;i++){
			ans+=abs(a[i]);
		}
	}
	printf("%lld\n",ans);
	
}