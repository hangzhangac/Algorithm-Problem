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
#include <stack>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=300005;
const ll mod=998244353;
const int inf=0x3f3f3f3f;
int dep[MAXN];
vector<int>G[MAXN];
int book[MAXN];
int n,m;
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b/=2;
		a=a*a%mod;
	}
	return res%mod;
}
int x=0,y=0,flag=0;
void dfs(int u,int d){
	dep[u]=d;
	book[u]=1;
	if(flag)return;
	if(!flag){
		if(d&1)x++;
		else{
			y++;
		}
	}
	for(int i=0;i<G[u].size();i++){
		if(flag)return ;
		int v=G[u][i];
		if(book[v]){
			if((dep[u]-dep[v])%2==0){
				flag=1;
				x=-2;y=-2;
				return ;
			}
			continue;
		}
		else{
			dfs(v,d+1);
		}
	}
}
int main(){
	
	int T;
	gi(T);
	while(T--){
		x=0,y=0,flag=0;
		ll ans=1;
		gi2(n,m);
		for(int i=1;i<=n;i++){
			G[i].clear();
			book[i]=0;
			dep[i]=0;
		}
		while(m--){
			gi2(x,y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		x=0,y=0;
		for(int i=1;i<=n;i++){
			if(!book[i]){
				dfs(i,1);
				if(x<0||y<0){
					ans=0;
					break;
				}
				else{
					ll cnt=qpow(2, x)%mod;
					cnt+=qpow(2,y)%mod;
					cnt%=mod;
					ans=ans*cnt%mod;
				}
			}
			x=0;y=0;
			flag=0;
		}
		printf("%lld\n",ans);
	}
	
	
	
	return 0;
}

