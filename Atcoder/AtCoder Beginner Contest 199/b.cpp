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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
int a[MAXN],b[MAXN];
int main() {
	
	
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	int r=b[1];
	int l=a[1];
	for(int i=2;i<=n;i++){
		r=min(r,b[i]);
		l=max(l,a[i]);
	}
	cout<<max(0,r-l+1)<<endl;
	
	
	return 0;
}



















