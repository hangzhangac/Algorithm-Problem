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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
struct Node{
	int l,r;
	int id;
	int sta;
}node[MAXN];
bool cmp(Node a,Node b){
	if(a.l==b.l)return a.r>b.r;
	return a.l<b.l;
}
bool cmp1(Node a,Node b){
	return a.id<b.id;
}
int main(){
	int T;gi(T);
	while(T--){
		int n;
		gi(n);
		for(int i=1;i<=n;i++){
			gi2(node[i].l,node[i].r);
			node[i].id=i;
			node[i].sta=1;
		}
		sort(node+1,node+n+1,cmp);
		int flag=0;
		int r=node[1].r;
		node[1].sta=2;
		for(int i=2;i<=n;i++){
			if(node[i].l>r){
				flag=1;
				break;
			}
			else{
				node[i].sta=2;
				r=max(node[i].r,r);
			}
		}
		if(!flag)printf("-1\n");
		else{
			sort(node+1,node+n+1,cmp1);
			for(int i=1;i<=n;i++){
				printf("%d%c",node[i].sta,i==n?'\n':' ');
			}
		}
	}
	
}
























