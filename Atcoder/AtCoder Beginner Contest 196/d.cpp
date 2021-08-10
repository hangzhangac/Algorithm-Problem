#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=200005;
const ll mod=1e9+7;
const ll inf=1000000000000000001;
using namespace std;
int n;
ll a[MAXN],t[MAXN];
ll cal(int i){
	ll sum=a[i];
	while(i<=n){
		if(t[i]==1){
			sum+=a[i];
		}
		else if(t[i]==2){
			sum=max(sum,a[i]);
		}
		else sum=min(sum,a[i]);
		i++;
	}
	return sum;
	
}
int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		gll2(a[i], t[i]);
	}
	ll sum=0;
	int i=1;
	ll left=-1000000000;
	ll right=1000000000;
	int idl=0,idr=0;
	while(i<=n){
		while(i<=n&&t[i]==1){
			sum+=a[i];
			i++;
		}
		if(i>n)break;
		if(t[i]==2){
			if(left<a[i]-sum){
				left=a[i]-sum;
				idl=i;
			}
		}
		else{
			if(right>a[i]-sum){
				right=a[i]-sum;
				idr=i;
			}
		}
		i++;
	}
	int q;
	cin>>q;
	ll val1=-1,val2=-1;
	if(idl)val1=cal(idl);
	if(idr)val2=cal(idr);
	for(int i=1;i<=q;i++){
		ll x;gll(x);
		if(x>=left&&x<=right){
			cout<<x+sum<<endl;
		}
		else if(x<left){
			cout<<val1<<endl;
		}
		else if(x>right){
			cout<<val2<<endl;
		}
	}
	return 0;
}