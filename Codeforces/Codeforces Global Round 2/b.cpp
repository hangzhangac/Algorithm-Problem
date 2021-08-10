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
const int MAXN=1005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN],b[MAXN];
int n,h;
bool C(int k){
	for(int i=1;i<=k;i++){
		b[i]=a[i];
	}
	sort(b+1,b+k+1);
//	for(int i=1;i<=k;i++){
//		cout<<b[i]<<' ';
//	}
//	cout<<endl;
	ll ans=0;
	for(int i=k;i>=2;i-=2){
		ans+=b[i];
	}
	if(k&1){
		ans+=b[1];
	}
//	cout<<ans<<endl;
	return ans<=h;
}
int main(){
	
	
	gi2(n,h);
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	int l=1,r=n;
	int ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(C(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	//cout<<"==="<<endl;
	//C(3);
	cout<<ans<<endl;
	
	
	
	
	return 0;
}



















