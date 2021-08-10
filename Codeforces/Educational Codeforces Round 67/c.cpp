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
const int MAXN=2005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN];
struct Node{
	int l,r;
	int id;
}node[MAXN],node1[MAXN];
bool cmp(Node a,Node b){
	if(a.l==b.l){
		return a.r>b.r;
	}
	return a.l<b.l;
}
int main(){
	
	int n,m;
	gi2(n,m);
	int cnt=0;
	int cnt1=0;
	for(int i=1;i<=m;i++){
		int t;
		gi(t);
		int l,r;
		gi2(l,r);
		if(t==1){
			++cnt;
			node[cnt].l=l;
			node[cnt].r=r;
			node[cnt].id=1;
		}
		else{
			++cnt1;	
			node1[cnt1].l=l;
			node1[cnt1].r=r;
			node1[cnt1].id=1;
		}
	}
	sort(node+1,node+cnt+1,cmp);
	for(int i=2;i<=cnt;i++){
		for(int j=i-1;j>=1;j--){
			if(node[j].id==1&&node[i].l<=node[j].r){
				node[j].r=max(node[j].r,node[i].r);
				node[i].id=0;
				break;
			}
		}
	}
	int len=0;
	for(int i=1;i<=cnt;i++){
		if(node[i].id)node[++len]=node[i];
	}
	for(int i=1;i<=len;i++){
		for(int j=1;j<=cnt1;j++){
			if(node1[j].l>=node[i].l&&node1[j].r<=node[i].r){
				printf("NO\n");
				return 0;
			}
		}
	}
	int num=1;
	int r=n;
	for(int i=len;i>=1;i--){
		while(r>node[i].r){
			a[r]=num;
			num++;
			r--;
		}
		while(r>=node[i].l){
			a[r]=num;
			r--;
		}
		num++;
	}
	while(r>=1){
		a[r]=num;
		num++;
		r--;
	}
	printf("YES\n");
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	
	
	
	return 0;
}