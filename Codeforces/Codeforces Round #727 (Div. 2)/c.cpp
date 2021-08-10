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
const int inf=0x3f3f3f3f;
using namespace std;
ll a[MAXN];
int n;
ll k,x;
vector<ll>v;
int main() {
	
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++){
		gll(a[i]);
	}
	sort(a+1,a+n+1);
	int group=0;
	for(int i=1;i<=n-1;i++){
		if(a[i+1]-a[i]>x){
			v.push_back(a[i+1]-a[i]);
			group++;
		}
	}
	group++;
	sort(v.begin(),v.end());
	for(auto y: v){
		ll need=(y-1)/x;
		if(k>=need){
			k-=need;
			group--;
		}
		else break;
	}
	cout<<group<<endl;
	
	
	
	return 0;
	
}













