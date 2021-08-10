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
int cnt[32];
int main() {
	
	int T;gi(T);
	while(T--){
		int n,k;
		int ans=0;
		mem(cnt,0);
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int x;gi(x);
			//cout<<x<<endl;
			for(int j=1;j<=31;j++){
				if(x&1)cnt[j]++;
				x>>=1;
			}
		}
		for(int j=1;j<=31;j++){
			if(cnt[j])
				ans+=(cnt[j]-1)/k+1;
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}




