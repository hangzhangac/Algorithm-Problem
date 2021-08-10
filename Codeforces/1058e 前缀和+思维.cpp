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
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int cal(ll x){
	int cnt=0;
	while(x){
		cnt+=x&1;
		x>>=1;
	}
	return cnt;
}
int n;
ll a[MAXN];
int sum[MAXN];
int sum1[MAXN];
int sum2[MAXN];
int main(){
	gi(n);
	sum2[0]=1;
	for(int i=1;i<=n;i++){
		gll(a[i]);
		sum[i]=sum[i-1]+(a[i]=cal(a[i]));
	}
	for(int i=1;i<=n;i++){
		sum1[i]=sum1[i-1]+(sum[i]&1);//奇数
		sum2[i]=sum2[i-1]+((sum[i]&1)^1);//偶数
	}
	ll ans=0;
	for(int r=1;r<=n;r++){
		ll maxn=a[r];
		int low=max(1,r-64);
		for(int j=r;j>=low;j--){
			maxn=max(maxn,a[j]);
			if((maxn<<1)<=sum[r]-sum[j-1]&&(sum[r]&1)==(sum[j-1]&1))ans++;
		}
		if(low>=2)
		ans+=sum[r]&1?sum1[low-2]:sum2[low-2];
	}
	printf("%lld\n",ans);
	
	
	
	return 0;
}






























