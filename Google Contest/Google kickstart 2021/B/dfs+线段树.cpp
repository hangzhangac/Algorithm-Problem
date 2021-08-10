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
int maxn=1;
struct Node{
	int l,r;
	ll val;
}node[MAXN<<2];
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
void pushup(int i){
	node[i].val=gcd(node[i<<1].val,node[i<<1|1].val);
}
void build(int l,int r,int i){
	node[i].l=l;
	node[i].r=r;
	int mid=(l+r)/2;
	if(l==r){
		node[i].val=0;
		return;
	}
	if(l<=mid)build(l,mid,i<<1);
	if(r>mid)build(mid+1,r,i<<1|1);
	pushup(i);
}
void update(int x,ll val,int i){
	if(node[i].l==node[i].r){
		node[i].val=val;
		return;
	}
	int mid=(node[i].l+node[i].r)/2;
	if(x<=mid)update(x, val, i<<1);
	else update(x, val, i<<1|1);
	pushup(i);
}
ll query(int l,int r,int i){
	if(node[i].l>=l&&node[i].r<=r){
		return node[i].val;
	}
	int mid=(node[i].l+node[i].r)/2;
	ll ans=0;
	if(l<=mid)ans=query(l, r, i<<1);
	if(r>mid)ans=gcd(ans,query(l, r, i<<1|1));
	return ans;
}
struct point{
	int to,l;
	ll a;
	point(){}
	point(int to,int l,ll a):to(to),l(l),a(a){
		
	}
};
vector<point>G[50005];
vector< pair<int,int> >q[50005];
vector< pair<int,ll> >ans;
void dfs(int u,int f){
	for(auto x:q[u]){
		int idx=x.first;
		int w=x.second;
		ll cur=query(1, min(maxn,w), 1);
		ans.push_back( make_pair(idx, cur));
	}
	for(auto x:G[u]){
		int v=x.to;
		int l=x.l;
		ll a=x.a;
		if(v==f)continue;
		update(l, a, 1);
		dfs(v,u);
		update(l, 0, 1);
	}
	return;
}
int main(){
	int T,cnt1=1;
	gi(T);while(T--){
		int n,qq;
		cin>>n>>qq;
		maxn=1;
		for(int i=1;i<=n-1;i++){
			int x,y,l1;ll a;
			cin>>x>>y>>l1>>a;
			G[x].push_back(point(y,l1,a));
			G[y].push_back(point(x,l1,a));
			maxn=max(maxn,l1);
		}
		build(1, maxn, 1);
		for(int j=1;j<=qq;j++){
			int c,w;
			cin>>c>>w;
			q[c].push_back(make_pair(j,w));
		}
		dfs(1,-1);
		sort(ans.begin(),ans.end());
		printf("Case #%d:",cnt1++);
		for(auto x:ans){
			cout<<" "<<x.second;
		}
		cout<<endl;
		for(int i=1;i<=n;i++){
			q[i].clear();
			G[i].clear();
		}
		ans.clear();
		
	}
	return 0;
	
}