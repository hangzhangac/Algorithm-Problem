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
int a[105];
int n;
bool C(int mid){
	ll ans1=0;
	ll ans2=0;
	for(int i=1;i<=n;i++){
		ans1+=mid-a[i];
		ans2+=a[i];
	}
	return ans1>ans2;
}
int main(){
	
	
	cin>>n;
	
	int k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k=max(k,a[i]);
	}
	int l=k,r=1000000000;
	int ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(C(mid)){
			r=mid-1;
			ans=mid;
		}
		else{
			l=mid+1;
		}
	}
	printf("%d\n",ans);
	
	
	
	return 0;
}































