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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN];
int main(){
	
	int s,n;gi2(n,s);
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	sort(a+1,a+n+1);
	ll ans=0;
	int k=n/2+1;
	if(a[k]==s){
		puts("0");
		return 0;
	}
	else if(a[k]<s)
	for(int i=n/2+1;i<=n;i++){
		if(a[i]<s){
			ans+=s-a[i];
		}
	}
	else{
	for(int i=n/2+1;i>=1;i--){
		if(a[i]>s){
			ans+=a[i]-s;
		}
	}
	}
	printf("%lld\n",ans);
	
	
	return 0;
}






