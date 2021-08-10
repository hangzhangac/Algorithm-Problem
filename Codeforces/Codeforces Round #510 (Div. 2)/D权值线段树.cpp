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
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=400005;
const ll mod=998244353;
const int inf=0x3f3f3f3f;
ll a[MAXN];
ll sum[MAXN];
ll t,n;
struct Node{
	int l,r;
	int val;
	Node(){
		val=0;
	}
}node[MAXN<<2];
void pushup(int i){
	node[i].val=node[i<<1].val+node[i<<1|1].val;
}
void build(int l,int r,int i){
	node[i].l=l;
	node[i].r=r;
	if(l==r)return ;
	int mid=(l+r)/2;
	build(l,mid,i<<1);
	build(mid+1,r,i<<1|1);
}
int query(int l,int r,int i){
	if(node[i].l>=l&&node[i].r<=r){
		return node[i].val;
	}
	int res=0;
	int mid=(node[i].l+node[i].r)/2;
	if(l<=mid){
		res+=query(l, r, i<<1);
	}
	if(r>=mid+1)res+=query(l, r, i<<1|1);
	return res;
}
void update(int x,int i){
	if(node[i].l==node[i].r){
		node[i].val++;
		return ;
	}
	int mid=(node[i].l+node[i].r)/2;
	if(x<=mid)update(x, i<<1);
	else update(x, i<<1|1);
	pushup(i);
}
ll v[MAXN];
int cnt=0;
map<ll,int>ms;
int main(){
	
	gll2(n, t);
	for(int i=1;i<=n;i++){
		gll(a[i]);
		sum[i]=sum[i-1]+a[i];
		v[++cnt]=sum[i];
	}
	
	for(int i=0;i<=n;i++){
		v[++cnt]=sum[i]+t;
	}
	sort(v+1,v+cnt+1);
	cnt=unique(v+1, v+cnt+1)-v-1;
	
	for(int i=1;i<=cnt;i++){
		ms[v[i]]=i;
	}
	build(1,cnt,1);
	update(ms[t+sum[0]], 1);
	ll ans=0;
	for(int i=1;i<=n;i++){
		int l=ms[sum[i]]+1;
		if(l<=cnt){
			int x=query(l, cnt, 1);
			ans+=x;
		}
		update(ms[t+sum[i]], 1);
	}
	printf("%lld\n",ans);
	
	
	
	return 0;
}