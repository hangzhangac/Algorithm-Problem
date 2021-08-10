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
#ifndef MAXARR
#define MAXARR 100005 //默认数组最多元素
#endif
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int maxNum[MAXARR][22];
int id[MAXARR][22];
int maxNum1[MAXARR][22];
int minNum1[MAXARR][22];
void RMQ(int num){
	for (int j = 1; j < 21; j++) {
		for (int i = 1 ; i <=num; i++) {
			if (i + (1<<j) -1 <=num) {
				maxNum[i][j] = max(maxNum[i][j-1], maxNum[i+(1<<(j-1))][j-1]);
				if(maxNum[i][j-1]>maxNum[i+(1<<(j-1))][j-1]){
					id[i][j]=id[i][j-1];
				}
				else{
					id[i][j]=id[i+(1<<(j-1))][j-1];
				}
			}
		}
	}
}
void RMQ1(int num){
	for (int j = 1; j < 21; j++) {
		for (int i = 1 ; i <=num; i++) {
			if (i + (1<<j) -1 <=num) {
				maxNum1[i][j] = max(maxNum1[i][j-1], maxNum1[i+(1<<(j-1))][j-1]);
				minNum1[i][j] = min(minNum1[i][j-1], minNum1[i+(1<<(j-1))][j-1]);
			}
		}
	}
}
int query1(int l,int r,int flag){
	int k=log2(r-l+1);
	if(flag)
		return max(maxNum1[l][k],maxNum1[r-(int)(1<<k)+1][k]);
	else return min(minNum1[l][k],minNum1[r-(int)(1<<k)+1][k]);
}
struct Node{
	int left,right;
	int l,r;
	int num;
	int val;
}node[MAXN*30];
int a[MAXN];
int n;
void build(int l,int r,int& cnt){
	cnt++;
	node[cnt].l=l;
	node[cnt].r=r;
	int k=log2(r-l+1);
	if(maxNum[l][k]>maxNum[r-(int)(1<<k)+1][k]){
		node[cnt].num=id[l][k];
		node[cnt].val=maxNum[l][k];
	}
	else{
		node[cnt].num=id[r-(int)(1<<k)+1][k];
		node[cnt].val=maxNum[r-(int)(1<<k)+1][k];
	}
	int cur=cnt;
	int num=node[cur].num;	
	if(num-l>0){
		int valmin=query1(node[cur].l, node[cur].num-1, 0);
		if(valmin<0){
			node[cur].left=cnt+1;
			build(l,num-1,cnt);
		}
	}
	if(r-num>0){
		int valmax=query1(node[cur].num, node[cur].r-1, 1);
		if(valmax>0){
			node[cur].right=cnt+1;
			build(num+1,r,cnt);
		}	
	}
	return;
}
int query(int x,int k,int cnt){
	int lnum=node[cnt].num-node[cnt].l;
	int rnum=node[cnt].r-node[cnt].num;
	int y=node[cnt].num;
	if(x<y){
		if(k>lnum){
			return y+k-lnum;
		}
		else{
			
			int valmin=query1(node[cnt].l, node[cnt].num-1, 0);
			if(valmin>0){//递增
				if(k<=x-node[cnt].l){
					return x-k;
				}else{
					return x+k-(x-node[cnt].l);
				}
			}
			return query(x, k, node[cnt].left);
		}
	}
	else if(x>y){
		if(k>rnum){
			return y+rnum+1-k;
		}
		else{
			int valmax=query1(node[cnt].num, node[cnt].r-1, 1);
			if(valmax<0){//递减
				if(k<=node[cnt].r-x+1){
					return x+k;
				}else return x-(k-(node[cnt].r-x+1));
			}
			return query(x, k, node[cnt].right);
		}	
	}
	else{
		if(k>lnum){
			
			return y+k-lnum;
		}
		else{
			return y-k;
		}
	}
}
int main(){
	int cnt1=1;
	int T;gi(T);while (T--) {
		int cnt=0;
		int q;
		gi2(n, q);
		for(int i=1;i<=n-1;i++){
			gi(a[i]);
			maxNum[i][0]=a[i];
			id[i][0]=i;
		}
		for(int i=1;i<=n-2;i++){
			a[i]=a[i+1]-a[i];
			minNum1[i][0]=a[i];
			maxNum1[i][0]=a[i];
		}
		RMQ(n-1);
		RMQ1(n-2);
		build(1,n-1,cnt);
		printf("Case #%d: ",cnt1++);
		while(q--){
			int s,k;
			gi2(s,k);
			k--;
			if(k==0){printf("%d ",s);}
			else{
				int t=query(s, k, 1);
				printf("%d ",t);
			}
		}
		printf("\n");
	}
	return 0;
}
