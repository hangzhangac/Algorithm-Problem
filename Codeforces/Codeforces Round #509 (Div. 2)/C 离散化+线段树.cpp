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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n,m,d;
struct Node{
	int val;
	int id;
}node[MAXN];
struct T{
	int l,r;
	int val;
	int id;
}tr[MAXN<<3];
int b[MAXN*2];
map<int,int>ms;
bool cmp(Node a,Node b){
	return a.val<b.val;
}
void pushup(int i){
	tr[i].val=tr[i<<1].val+tr[i<<1|1].val;
	return ;
}
void build(int l,int r,int i){
	tr[i].l=l;
	tr[i].r=r;
	if(l==r){
		tr[i].val=0;
		tr[i].id=0;
		return ;
	}
	int mid=(l+r)/2;
	build(l,mid,i<<1);
	build(mid+1,r,i<<1|1);
}
void update(int x,int i,int flag,int id){
	if(tr[i].l==tr[i].r){
		tr[i].val=flag;
		tr[i].id=id;
		return ;
	}
	int mid=(tr[i].l+tr[i].r)/2;
	if(x<=mid){
		update(x,i<<1,flag,id);
	}
	else update(x,i<<1|1,flag,id);
	pushup(i);
}
int iid=-1;
int query(int l,int r,int i){
	if(tr[i].l>=l&&tr[i].r<=r){
		if(tr[i].val==0)return -1;
		if(tr[i].l==tr[i].r){
			iid=tr[i].id;
			return tr[i].l;
		}
		if(tr[i<<1].val>0){
			return query(l, r, i<<1);
		}
		else return query(l, r, i<<1|1);
	}
	int mid=(tr[i].l+tr[i].r)/2;
	int res=-1;
	if(l<=mid){
		res=query(l, r, i<<1);
	}
	if(res==-1){
		res=query(l, r, i<<1|1);
	}
	return res;
}
int ans[MAXN];
int main(){
	
	gi3(n, m, d);
	for(int i=1;i<=n;i++){
		gi(node[i].val);
		node[i].id=i;
		b[i-1]=node[i].val;
		b[i-1+n]=node[i].val+d+1;
		if(b[i-1+n]>m){
			b[i-1+n]=1;
		}
	}
	sort(node+1,node+n+1,cmp);
	b[2*n]=m;
	sort(b,b+2*n+1);
	int cnt=unique(b, b+2*n+1)-b;
	for(int i=0;i<cnt;i++){
		ms[b[i]]=i+1;
	}
	build(1,cnt,1);
	for(int i=2;i<=n;i++){
		update(ms[node[i].val], 1, 1, node[i].id);
	}
	int sum=1;
	int i=1;
	int t=node[i].val+d+1;
	int r=ms[m];
	ans[node[1].id]=1;
	while(1){
		int x;
		if(t>m){
			sum++;
			t=1;
			x=query(t,r,1);
			if(x==-1){sum--;break;}
			update(x,1,0,-1);
			ans[iid]=sum;
		}
		else{
			x=query(ms[t],r,1);
			if(x==-1){
				sum++;
				t=1;
				x=query(t,r,1);
				if(x==-1){sum--;break;}
				update(x,1,0,-1);
				ans[iid]=sum;
			}
			else{
				update(x,1,0,-1);
				ans[iid]=sum;
			}
		}
		t=b[x-1]+d+1;
	}
	printf("%d\n",sum);
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}