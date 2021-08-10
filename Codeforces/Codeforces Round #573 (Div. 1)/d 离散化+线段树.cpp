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
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n;
struct Node{
	int x,y;
}node[MAXN];
struct Tree{
	int val;
	int l,r;
}tree[MAXN<<2];
bool cmp(Node a,Node b){
	if(a.y==b.y)return a.x<b.x;
	return a.y>b.y;
}
map<int,int>ms;

vector<int>x,y,ans,up;
int maxx,maxy;
void build(int l,int r,int i){
	tree[i].l=l;
	tree[i].r=r;
	tree[i].val=0;
	if(l==r){
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,i<<1);
	build(mid+1,r,i<<1|1);
}
int query(int l,int r,int i){
	if(tree[i].l>=l&&tree[i].r<=r){
		return tree[i].val;
	}
	int mid=(tree[i].l+tree[i].r)/2;
	int ans=0;
	if(l<=mid)ans=query(l, r, i<<1);
	if(r>=mid+1)ans+=query(l, r, i<<1|1);
	return ans;
}
void update(int x,int i){
	if(tree[i].l==tree[i].r){
		tree[i].val=1;
		return;
	}
	int mid=(tree[i].l+tree[i].r)/2;
	if(x<=mid){
		update(x, i<<1);
	}
	else update(x,i<<1|1);
	tree[i].val=tree[i<<1].val+tree[i<<1|1].val;
	return ;
}
int book[MAXN];

int main(){
	
	gi(n);
	for(int i=1;i<=n;i++){
		gi2(node[i].x,node[i].y);
		x.push_back(node[i].x);
		y.push_back(node[i].y);
	}
	sort(x.begin(),x.end());
	x.erase(unique(x.begin(),x.end()), x.end());
	for(int i=0;i<x.size();i++){
		ms[x[i]]=i+1;
	}
	for(int i=1;i<=n;i++){
		node[i].x=ms[node[i].x];
	}
	sort(y.begin(),y.end());ms.clear();
	y.erase(unique(y.begin(),y.end()), y.end());
	for(int i=0;i<y.size();i++){
		ms[y[i]]=i+1;
	}
	for(int i=1;i<=n;i++){
		node[i].y=ms[node[i].y];
	}
	maxx=x.size();maxy=y.size();
	build(1,maxx,1);
	sort(node+1,node+n+1,cmp);
	int i=1;
	ll cnt=0;
	ll res=0;
	while(i<=n){
		ans.push_back(1);
		int t=node[i].y;
		while(i<=n&&node[i].y==t){
			int x=book[node[i].x]++;
			if(x==0){
				cnt++;
				up.push_back(node[i].x);
			}
			ans.push_back(node[i].x-1);
			ans.push_back(node[i].x+1);
			i++;
		}
		ans.push_back(maxx);
		ll sum=cnt*(cnt+1)/2;
		for(int i=0;i<ans.size();i+=2){
			int l=ans[i],r=ans[i+1];
			if(l<=r){
				int y=query(l, r, 1);
				sum-=1ll*y*(y+1)/2;
			}
		}
		res+=sum;
		for(int i=0;i<up.size();i++){
			int t=up[i];
			update(t, 1);
		}
		ans.clear();
		up.clear();
	}
	printf("%lld\n",res);

	
	return 0;
}













