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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll a[MAXN];
ll sum[MAXN];
ll minn=1e17;
int main(){
	
	ll H;int n;
	gll(H);gi(n);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		gll(a[i]);
		sum[i]=sum[i-1]+a[i];
		minn=min(minn,sum[i]);
	}
	//return 0;
	ll t=H;
	for(int i=1;i<=n;i++){
		t+=a[i];
		if(t<=0){
			printf("%d\n",i);
			return 0;
		}
	}
	
	if(sum[n]>=0){
		printf("-1\n");
		return 0;
	}
	
	ll cur=H+minn;
	//cout<<cur<<endl;
	ll z=abs(sum[n]);
	ll ans=cur/z;
	
	H=H+ans*sum[n];
//	H-=minn;
//	cout<<H<<endl;
	while(H+minn>0){
		H+=sum[n];
		ans++;
	}
	ans*=n;
	if(H<=0){
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=n;i++){
		H+=a[i];
		ans++;
		if(H<=0){
			printf("%lld\n",ans);
			return 0;
		}
		
	}
	
	
	
	
	return 0;
}














