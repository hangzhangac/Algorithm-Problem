#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <time.h>
#include <map>
#include <set>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=1000005;
const ll mod=1e9+7;
const ll inf=2e18;
ll sa[MAXN];
ll sb[MAXN];
ll lazy[MAXN << 2];
struct Node{
	int x,y,z;
}node[int(2e5)+5];
struct Tree
{
	int l, r;
	ll maxn;
	int mid()
	{
		return (l + r) >> 1;
	}
}tree[MAXN<<2];		

void PushUp(int rt)
{
	tree[rt].maxn= max(tree[rt << 1].maxn, tree[rt << 1 | 1].maxn);
}

void PushDown(int rt)
{
	if (lazy[rt])
	{
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		tree[rt << 1].maxn += lazy[rt];
		tree[rt << 1 | 1].maxn += lazy[rt];
		lazy[rt] = 0;
	}
}

void build(int l, int r, int rt)
{
	tree[rt].l = l;
	tree[rt].r = r;
	lazy[rt] = 0;
	if (l == r)
	{
		tree[rt].maxn = -sb[l];
		return;
	}
	int m = tree[rt].mid();
	build(l, m, (rt << 1));
	build(m + 1, r, (rt << 1 | 1));
	PushUp(rt);
}
void update(ll c, int l, int r, int rt)
{
	if (tree[rt].l == l&&tree[rt].r==r)
	{ 
		lazy[rt] += c;
		tree[rt].maxn += c;
		return;
	}
	if (tree[rt].l == tree[rt].r)return;
	int m = tree[rt].mid();
	PushDown(rt);
	if (r <= m)update(c, l, r, rt << 1);
	else if (l > m)update(c, l, r, rt << 1 | 1);
	else 
	{
		update(c, l, m, rt << 1);
		update(c, m + 1, r, rt << 1 | 1);
	}
	PushUp(rt);
}
bool cmp(Node a,Node b){
	return a.x<b.x;
}
int n,m,p;
int main(){
	
	gi3(n, m, p);
	for(int i=1;i<MAXN;i++){
		sa[i]=inf;
		sb[i]=inf;
	}
	for(int i=1;i<=n;i++){
		int a,b;
		gi2(a,b);
		sa[a]=min(sa[a],1LL*b);
	}
	for(int i=1;i<=m;i++){
		int a,b;
		gi2(a,b);
		sb[a]=min(sb[a],1LL*b);
	}
	for(int i=1;i<=p;i++){
		gi3(node[i].x, node[i].y, node[i].z);
	}
	sort(node+1,node+p+1,cmp);
	build(1, 1000000, 1);
	int cur=1;
	ll ans=-1e18;
	for(int i=1;i<=1000000;i++){
		while(cur<=p&&node[cur].x<i){
			if(node[cur].y!=1000000)
				update(node[cur].z, node[cur].y+1, 1000000, 1);
			cur++;
		}
		if(sa[i]==inf)continue;
		ans=max(ans,-sa[i]+tree[1].maxn);
	}
	printf("%lld\n",ans);
	
	
	return 0;
}
