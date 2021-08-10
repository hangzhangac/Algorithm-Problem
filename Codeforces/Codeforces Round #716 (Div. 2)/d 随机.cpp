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
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
int a[MAXN];
vector<int>G[MAXN];
int main(){
	int n,q;
	gi2(n, q);
	mt19937 rd=mt19937((unsigned)chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int>ran(0,2147483647); //产生[0,2147483647]的随机数
	for(int i=1;i<=n;i++){
		gi(a[i]);
		G[a[i]].push_back(i);
	}
	while(q--){
		int l,r;
		gi2(l, r);
		int ans=1;
		for(int i=0;i<50;i++){
			int id=ran(rd)%(r-l+1)+l;
			int val=a[id];
			int num=upper_bound(G[val].begin(), G[val].end(), r)-lower_bound(G[val].begin(), G[val].end(), l);
			if(num>(r-l+2)/2){
				ans=num-(r-l+1-num);
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


