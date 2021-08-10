//求区间不同数的个数 下标从1开始
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
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=300010;
const int MAXN_VALUE=3e5+10;//数组中a[i]的最大值 用于离散化
int book[MAXN_VALUE];
struct Node{
	int L,R;
	int sum;
}node[MAXN*40];
int n,m,cnt=0;
int a[MAXN],b[MAXN];//a为原数组 b为离散化数组
int root[MAXN],vis[MAXN];
int last[MAXN];
int c[MAXN];
int lowbit(int k){
	return k&(-k);
}
int getsum(int i){
	int sum=0;
	while(i>0){
		sum+=c[i];
		i-=lowbit(i);
	}
	return sum;
}
void update1(int i,int j){
	while(i<=300001){
		c[i]+=j;
		i+=lowbit(i);
	}
}

void init(){
	cnt=0;mem(vis,0);
	node[0].L=node[0].R=node[0].sum=0;
	root[0]=0;
}
void update(int num,int& rt,int v,int l,int r){
	node[++cnt]=node[rt];
	node[rt=cnt].sum+=v;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(num<=mid)update(num, node[rt].L, v, l, mid);
	else update(num,node[rt].R,v,mid+1,r);	
}
int query(int rt,int L,int R,int l,int r){
	if(!rt)return 0;
	if(l>=L&&r<=R) return node[rt].sum;
	int mid=(l+r)>>1,res=0;
	if(L<=mid)res=query(node[rt].L, L, R, l, mid);
	if(R>mid)res+=query(node[rt].R, L, R, mid+1, r);
	return res;
}
int minn[MAXN],maxn[MAXN];
set<int>s;
int main(){
	init();gi(m);gi(n);
	for(int i=1;i<=n;i++){ gi(a[i]);b[i]=a[i];}
	for(int i=1;i<=n;i++){
		root[i]=root[i-1];
		if(!vis[a[i]]){
			vis[a[i]]=i;
			update(i, root[i], 1, 1, n);
		}
		else{
			update(vis[a[i]], root[i], -1, 1, n);
			vis[a[i]]=i;
			update(i, root[i], 1, 1, n);
		}
	}
	for(int i=1;i<=m;i++){
		minn[i]=i;
		maxn[i]=i;
	}
	for(int i=n;i>=1;i--){
		int t=a[i];
		int x,y,ans=0;
		if(last[t]==0){
			x=i+1;
			y=n;
			if(x>y){
				ans=0;
			}
			else ans=query(root[y], x, y, 1, n);
		}
		else{
			x=i+1;
			y=last[t]-1;
			if(x>y){
				ans=0;
			}
			else ans=query(root[y], x, y, 1, n);
		}
		last[t]=i;
		minn[t]=min(minn[t],ans+1);
		maxn[t]=max(maxn[t],ans+1);
	}
	mem(last,0);
	int cnt=0;
	for(int i=1;i<=n;i++){
		int t=a[i];
		if(last[t]==0){
			int sum1=getsum(t);
			int sum2=getsum(300000);
			int ans=sum2-sum1+t;
			last[t]=1;
			update1(t, 1);
			minn[t]=min(minn[t],ans);
			maxn[t]=max(maxn[t],ans);
		}
		minn[t]=1;
	}
	for(int i=1;i<=m;i++){
		if(last[i]==0){
			int sum1=getsum(i);
			int sum2=getsum(300000);
			int ans=sum2-sum1+i;
			minn[i]=min(minn[i],ans);
			maxn[i]=max(maxn[i],ans);
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d %d\n",minn[i],maxn[i]);
	}
	return 0;
}