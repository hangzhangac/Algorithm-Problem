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
const int MAXN=1505;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
struct Node{
	int l,r;
	ll val;
}node[2250005],tmp[2250005];;
ll sum[MAXN];
ll a[MAXN];
vector<int>ans1;
vector<int>ans2;
bool cmp(Node a,Node b){
	if(a.val==b.val){
		if(a.r==b.r)
			return a.l>b.l;
		return a.r<b.r;
	}
	return a.val<b.val;
}
int main(){
	sum[0]=0;
	int n;
	gi(n);
	for(int i=1;i<=n;i++){
		gll(a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	int len=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			++len;
			node[len].l=i;
			node[len].r=j;
			node[len].val=sum[j]-sum[i-1];
		}
	}
	sort(node+1,node+len+1,cmp);
	int i=1;
	ll val=node[1].val;
	int num=0;
	int maxn=0;
	int pos=-1;
	while(i<=len){
		int st=i;
		while(i<=len&&node[i].val==val){
			++num;
			tmp[num]=node[i];
			i++;
		}
		int r=tmp[1].r;
		int sum=1;
		for(int j=2;j<=num;j++){
			if(tmp[j].l>r){
				r=tmp[j].r;
				sum++;
			}
		}
		if(maxn<sum){
			maxn=sum;
			pos=st;
		}
		if(i>len)break;
		val=node[i].val;
		num=0;
	}
	printf("%d\n",maxn);
	i=pos;
	val=node[i].val;
	num=0;
	while(i<=len&&node[i].val==val){
		++num;
		tmp[num]=node[i];
		i++;
	}
	int r=tmp[1].r;
	printf("%d %d\n",tmp[1].l,tmp[1].r);
	for(int j=2;j<=num;j++){
		if(tmp[j].l>r){
			r=tmp[j].r;
			printf("%d %d\n",tmp[j].l,tmp[j].r);
		}
	}
	return 0;
}