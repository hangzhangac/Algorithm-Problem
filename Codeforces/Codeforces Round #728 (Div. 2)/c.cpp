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
int a[MAXN];
int main(int argc, char *argv[]) {
	int T;gi(T);
	while(T--){
		int n;
		gi(n);
		ll ans=0;
		for(int i=1;i<=n;i++){
			gi(a[i]);
		}
		for(int i=1;i<=n;i++){
			int t=a[i];
			int x=1;
			while(t*x<=2*i-1){
				int cur=t*x;
				int q=cur-i;
				if(a[q]==x&&q>=1){
					ans++;
				}
				x++;
			}
		}
		cout<<ans<<endl;
	}
	
}