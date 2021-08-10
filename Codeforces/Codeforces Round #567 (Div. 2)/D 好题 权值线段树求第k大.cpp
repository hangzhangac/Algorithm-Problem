#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <time.>
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
const int MAXN=500005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
struct Node{
	int l,r;
	int val;
}node[MAXN<<2];
struct Query{
	int id;
	int ans;
	ll k;
}query[MAXN];
void pushup(int i){
	node[i].val=node[i<<1].val+node[i<<1|1].val;
}
void build(int l,int r,int i){
	node[i].l=l;
	node[i].r=r;
	node[i].val=0;
	if(l==r)return;
	int mid=(l+r)/2;
	build(l,mid,i<<1);
	build(mid+1,r,i<<1|1);
}
void update(int i,int x){
	if(node[i].l==node[i].r){
		node[i].val=1;
		return ;
	}
	int mid=(node[i].l+node[i].r)/2;
	if(x<=mid){
		update(i<<1, x);
	}
	else{
		update(i<<1|1, x);
	}
	pushup(i);
}
int qry(int i,int x){// x 大
	if(node[i].l==node[i].r){
		return node[i].l;
	}
	int t=i<<1;
	if(node[t].val>=x){
		return qry(t, x);
	}
	else return qry(t|1,x-node[t].val);
}
int n,m,q;
struct Num{
	int num;
	int id;
}cnt[MAXN];
bool cmp(Query a,Query b){
	return a.k<b.k;
}
bool cmp1(Query a,Query b){
	return a.id<b.id;
}
bool cmp2(Num a,Num b){
	if(a.num==b.num)return a.id<b.id;
	return a.num<b.num;
}
int main(){
	gi3(n, m, q);
	for(int i=1;i<=m;i++){
		cnt[i].num=0;
		cnt[i].id=i;
	}
	for(int i=1;i<=n;i++){
		int x;gi(x);
		cnt[x].num++;
	}
	for(int i=1;i<=q;i++){
		gll(query[i].k);
		query[i].id=i;
	}
	build(1, m, 1);
	sort(query+1,query+q+1,cmp);
	sort(cnt+1,cnt+m+1,cmp2);
	int ix=1;
	ll sum=0;
	sum+=cnt[ix].num;
	update(1, cnt[ix].id);
	for(int i=1;i<=q;i++){
		ll k=query[i].k;
		k-=n;
		while(ix<=m-1&&k>1ll*cnt[ix+1].num*ix-sum){
			ix++;
			sum+=cnt[ix].num;
			update(1, cnt[ix].id);
		}
		k-=1ll*cnt[ix].num*ix-sum;
		k%=ix;
		if(k==0)k=ix;
		query[i].ans=qry(1, int(k));
	}
	sort(query+1,query+q+1,cmp1);
	for(int i=1;i<=q;i++){
		printf("%d\n",query[i].ans);
	}
}


