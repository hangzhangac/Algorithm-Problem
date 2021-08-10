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
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
vector<int>a[MAXN];
vector<int>b[MAXN];
int n;
struct Node{
	int l,r;
	int val;
}node[MAXN<<2];
int bb[MAXN];
int aa[MAXN];
int book[MAXN];
void pushup(int i){
	node[i].val=min(node[i<<1].val,node[i<<1|1].val);
}
void build(int l,int r,int i){
	node[i].l=l;
	node[i].r=r;
	if(l==r){
		node[i].val=aa[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,i<<1);
	build(mid+1,r,i<<1|1);
	pushup(i);
}
int query(int l,int r,int i){
	if(node[i].l>=l&&node[i].r<=r){
		return node[i].val;
	}
	int mid=(node[i].r+node[i].l)/2;
	int ans=inf;
	if(l<=mid){
		ans=query(l,r, i<<1);
	}
	if(r>=mid+1){
		ans=min(ans,query(l, r, i<<1|1));
	}
	return ans;
}
void update(int i,int x){
	if(node[i].l==node[i].r){
		node[i].val=inf;
		return;
	}
	int mid=(node[i].r+node[i].l)/2;
	if(x<=mid)update(i<<1, x);
	else update(i<<1|1, x);
	pushup(i);
}
int main(){
	
	int T;
	gi(T);
	while(T--){
		int n;
		gi(n);
		for(int i=1;i<=n;i++){
			a[i].clear();
			b[i].clear();
		}
		for(int i=1;i<=n;i++){
			gi(aa[i]);
			a[aa[i]].push_back(i);
		}
		
		for(int i=1;i<=n;i++){
			book[i]=0;
			gi(bb[i]);
			b[bb[i]].push_back(i);
		}
		
		int flag=0;
		for(int i=1;i<=n;i++){
			if(a[i].size()!=b[i].size()){
				flag=1;break;
			}
			for(int j=0;j<a[i].size();j++){
				book[b[i][j]]=a[i][j];
			}
		}
		
		if(flag){printf("NO\n");continue;}
		build(1,n,1);
		
		for(int i=1;i<=n;i++){
			int t=book[i];
			int minn=query(1, t, 1);
			if(minn==bb[i]){
				update(1, t);
			}
			else{
				flag=1;
				break;
			}
		}
		if(flag){
			printf("NO\n");
		}
		else printf("YES\n");
	}
	
	
	
	return 0;
}