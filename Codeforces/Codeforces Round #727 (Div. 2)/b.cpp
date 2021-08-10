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
string s;
int sum[MAXN][26];
int main() {
	int n;
	int q;
	cin>>n>>q;
	cin>>s;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<26;j++){
			sum[i+1][j]=sum[i][j];
		}
		int t=s[i]-'a';
		sum[i+1][t]++;
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		ll ans=0;
		for(int j=0;j<26;j++){
			ll t=1LL*(sum[r][j]-sum[l-1][j])*(j+1);
			ans+=t;
		}
		cout<<ans<<endl;
	}
	
	return 0;
	
}













