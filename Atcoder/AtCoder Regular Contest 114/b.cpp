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
const ll mo=998244353;
const int inf=0x3f3f3f3f;
using namespace std;
int n;
int f[MAXN];
map<int,int>ms;
int start=0;
int cnt=0;
vector< int>G[MAXN];
int book[MAXN];
int in[MAXN];
ll qMul(ll a,ll b,ll mo){
	ll an = 1;
	while(b) {
		if(b&1) an =(an*a) % mo;
		a = (a*a)%mo;
		b>>=1;
	}return an%mo;
}
void dag(){
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(!in[i]){
			q.push(i);
		}
			
	}
	while(!q.empty()){
		int cur=q.front();
		book[cur]=1;
		q.pop();
		for(int i=0;i<G[cur].size();i++){
			int t=G[cur][i];
			in[t]--;
			if(!in[t]){
				q.push(t);
			}
		}
	}
}
void dfs(int u){
	book[u]=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(book[v])continue;
		dfs(v);
	}
}
int main(){
	
	cin>>n;
	for(int i=1;i<=n;i++){
		gi(f[i]);
		G[i].push_back(f[i]);
		in[f[i]]++;
	}
	dag();
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(book[i]!=1){
			cnt++;
			dfs(i);
		}
	}
	//cout<<cnt<<endl;
	ll ans=qMul(2LL, 1LL*cnt, mo);
	ans-=1;
	ans=((ans%mo)+mo)%mo;
	cout<<ans<<endl;
	
	
	
	return 0;
}

