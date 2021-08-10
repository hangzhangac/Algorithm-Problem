#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 200007;
int arr[maxn];
struct Node{
	int l,r;
	int maxn;
	ll sum;
	ll lazy;
	int minn;
}node[maxn<<2];
int n, q;

void push_down(int i) {
	if (node[i].lazy) {
		node[i<<1].lazy=node[i].lazy;
		node[i<<1|1].lazy=node[i].lazy;
		node[i<<1].maxn=node[i].lazy;
		node[i<<1|1].maxn=node[i].lazy;
		node[i<<1].minn=node[i].lazy;
		node[i<<1|1].minn=node[i].lazy;
		int l=node[i].l,r=node[i].r;
		int mid=(l+r)/2;
		node[i<<1].sum=node[i].lazy*(mid-l+1);
		node[i<<1|1].sum=node[i].lazy*(r-mid);
		node[i].lazy=0;
	}
}
void push_up(int i) {
	node[i].maxn=max(node[i<<1].maxn,node[i<<1|1].maxn);
	node[i].sum=node[i<<1].sum+node[i<<1|1].sum;
	node[i].minn=min(node[i<<1].minn,node[i<<1|1].minn);
}

void build(int i,int l,int r){
	node[i].l=l;
	node[i].r=r;
	node[i].lazy=0;
	if(l==r){
		node[i].maxn=arr[l];
		node[i].minn=arr[l];
		node[i].sum=arr[l];
		return;
	}
	int mid=(l+r)/2;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	push_up(i);
}
int query_first(int i,int l,int r,int y){
	if(node[i].l>=l&&node[i].r<=r){
		if(node[i].minn>y)return -1;
		if(node[i].maxn<=y)return node[i].l;
		push_down(i);
		if(node[i<<1].minn<=y) return query_first(i<<1,l,r,y);
		else return query_first(i<<1|1,l, r, y);
	}
	push_down(i);
	int mid=(node[i].r+node[i].l)/2;
	int pos1=-1;
	int pos2=-1;
	if(l<=mid){
		pos1=query_first(i<<1,l, r, y);
	}
	if(pos1!=-1)return pos1;
	if(r>mid){
		pos2=query_first(i<<1|1,l, r, y);
	}
	return pos2;
}
pair<int,int> query_sum(int i,int l,int r,int y){
	if(y==-1)return make_pair(0,-1);
	if(node[i].l>=l&&node[i].r<=r){
		if(node[i].maxn>y)return make_pair(0,-1);
		if(node[i].sum<=y)return make_pair(node[i].r-node[i].l+1,y-node[i].sum);
		push_down(i);
		if(node[i<<1].sum>y)return query_sum(i<<1, l, r, y);
		else{
			y-=node[i<<1].sum;
			int num=node[i<<1].r-node[i<<1].l+1;
			pair<int,int> p=query_sum(i<<1|1, l, r, y);
			return make_pair(num+p.first,p.second);
		}
	}
	push_down(i);
	int mid=(node[i].l+node[i].r)/2;
	pair<int,int>p,e;
	p.first=0;
	p.second=y;
	if(l<=mid){
		p=query_sum(i<<1, l, r, y);
	}
	if(r>mid){
		e=query_sum(i<<1|1, l, r, p.second);
		p.first+=e.first;
		p.second=e.second;
	}
	return p;
}
ll querysum2(int index,int l,int r){  
	if(l <= node[index].l && r >= node[index].r){  
		return node[index].sum;  
	}  
	push_down(index);  
	int mid = (node[index].l+node[index].r)>>1;  
	ll ans = 0;   
	if(l <= mid){  
		ans += querysum2(index<<1,l,r);  
	}  
	if(r > mid){  
		ans += querysum2(index<<1|1,l,r);  
	}
	return ans; 
}
void update(int i,int l,int r,ll y){
	if(node[i].l>=l&&node[i].r<=r){
		if(node[i].maxn<y){
			node[i].lazy=y;
			node[i].maxn=y;
			node[i].minn=y;
			node[i].sum=y*(node[i].r-node[i].l+1);
			return ;
		}
		if(node[i].minn>=y)return;
	}
	push_down(i);
	int mid=(node[i].l+node[i].r)/2;
	if(l<=mid){
		update(i<<1,l,r,y);
	}
	if(r>mid){
		update(i<<1|1,l,r,y);
	}
	push_up(i);
	
}
int main()
{
	scanf("%d %d", &n, &q);
	for (int i=1;i<=n;i++) {
		scanf("%d", &arr[i]);
	}
	build(1, 1, n);
	int op;
	int x,y;
	while (q--) {
		scanf("%d", &op);
		if (op==1) {
			scanf("%d%d", &x,&y);
			update(1, 1, x, y*1LL);
		} else if (op==2) {
			scanf("%d%d",&x,&y);
			int l=x,r=n;
			int cnt=0;
			int flag=0;
			while(l<=n){
				int t=query_first(1, l, n, y);
				if(t==-1)break;
				flag++;
				pair<int,int>p=query_sum(1, t, n, y);
				int num=p.first;
				ll tmp=querysum2(1, t, t+num-1);
				y-=tmp;
				cnt+=num;
				l=t+num;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}
