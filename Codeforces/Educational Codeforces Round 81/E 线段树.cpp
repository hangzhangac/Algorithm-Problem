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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN];
int n,p[MAXN];
int id[MAXN];
ll sum[MAXN];
ll lazy[MAXN << 2];			//lazy用来记录该节点的每个数值应该加多少 
struct Tree
{
	int l, r;
	ll minn;
	int mid()
	{
		return (l + r) >> 1;
	}
}tree[MAXN<<2];		

void PushUp(int rt)
{
	tree[rt].minn= min(tree[rt << 1].minn, tree[rt << 1 | 1].minn);
}

void PushDown(int rt)
{
	if (lazy[rt])
	{
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		tree[rt << 1].minn += lazy[rt];
		tree[rt << 1 | 1].minn += lazy[rt];
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
		tree[rt].minn = sum[l];
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
		tree[rt].minn += c;
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

ll Query(int l, int r, int rt)
{
	if (l == tree[rt].l&&r == tree[rt].r)
	{
		return tree[rt].minn;
	}
	int m = tree[rt].mid();
	PushDown(rt);
	ll res = 0;
	if (r <= m)res = Query(l, r, rt << 1);
	else if (l > m)res = Query(l, r, rt << 1 | 1);
	else
	{
		res =Query(l, m, rt << 1);
		res =min(Query(m + 1, r, rt << 1 | 1),res);
	}
	return res;
}
int main(){
	
	gi(n);
	for(int i=1;i<=n;i++){
		gi(p[i]);
		id[p[i]]=i;
	}
	for(int i=1;i<=n;i++){
		gi(a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	build(1,n-1,1);
	ll minn=Query(1, n-1, 1);
	for(int i=1;i<=n;i++){
		int x=id[i];
		if(x!=n){
			update(-a[x], x, n-1, 1);
		}
		if(x!=1){
			update(a[x], 1, x-1, 1);
		}
		ll ans=Query(1, n-1, 1);
		minn=min(minn,ans);
	}
	printf("%lld\n",minn);
	
	return 0;
}