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
int n,a[MAXN],b[MAXN];
int mp[MAXN];
vector<int>G[MAXN];
ll s1[MAXN],s2[MAXN];
ll h[MAXN*10];
ll dfs(int u,int f){
	ll cnt=0;
	int num=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f)continue;
		ll flag=dfs(v,u);
		if(flag==46)return flag;
		cnt+=flag;
		num+=(flag||0);
		if(num>=2)return 46;
	}
	int v=mp[u];
	cnt+=h[a[u]];
	cnt-=h[b[u]];
	return cnt;
}
int main() {
	h[0]=1;
	for(int i=1;i<=1000000;i++){
		h[i]=h[i-1]*47;
	}
	int T;gi(T);while(T--){
		int s;cin>>n>>s;
		for(int i=1;i<n;i++){
			int u,v;
			gi2(u, v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			gi(a[i]);
			mp[i]=i;
		}
		for(int i=1;i<=n;i++){
			gi(b[i]);
		}
		ll ans=dfs(1,0);
		if(ans!=0){
			printf("0\n");
		}
		else{
			printf("1\n");
		}
		for(int i=1;i<=n;i++){
			G[i].clear();
			s1[i]=0;
			s2[i]=0;
		}
	}
	return 0;
}