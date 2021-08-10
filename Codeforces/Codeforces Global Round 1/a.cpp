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
const ll mod=2;
const int inf=0x3f3f3f3f;
ll a[MAXN];
int main(){
	
	ll b,k;
	cin>>b>>k;
	ll s=1;
	ll ans=0;
	for(int i=0;i<k;i++){
		gll(a[i]);
	}
	//cout<<1<<endl;
	for(int i=0,j=k-1;i<j;i++,j--){
		swap(a[i],a[j]);
	}
	for(int i=0;i<k;i++){
	//	gll(a[i]);
		ans+=s*a[i]%mod;
		ans%=mod;
		s=s*b;
		s%=mod;
	}
	if(ans){
		printf("odd\n");
	}
	else printf("even\n");
	
	
	
	
	
	
	
	return 0;
}












