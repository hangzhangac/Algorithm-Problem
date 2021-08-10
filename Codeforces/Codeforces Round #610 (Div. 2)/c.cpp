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
int type[MAXN];
int t[MAXN];
struct Node{
	int type;
	int t;	
}node[MAXN];
bool cmp(Node a,Node b){
	if(a.t==b.t)return a.type<b.type;
	return a.t<b.t;
}
int main(){
	
	int m;
	gi(m);
	while(m--){
		int n,T,a,b;
		gi2(n,T);
		gi2(a,b);
		int cnt[]={0,0};
		for(int i=1;i<=n;i++){
			gi(node[i].type);
			cnt[node[i].type]++;
		}
		for(int i=1;i<=n;i++){
			gi(node[i].t);
		}
		sort(node+1,node+n+1,cmp);
		node[0].t=0;
		node[n+1].t=T+1;
		ll sum=0;
		int maxn=0;
		for(int i=0;i<=n;i++){
			int t1=node[i].t;
			int t2=node[i+1].t;
			int sheng=-1;
			if(sum<t2){
				sheng=t2-1-sum;
				int ans=i;
				int num=min(cnt[0],sheng/a);
				ans+=num;
				sheng-=num*a;
				num=min(cnt[1],sheng/b);
				ans+=num;
				sheng-=num*b;
				maxn=max(maxn,ans);
			}
			int val=a;
			if(node[i+1].type==1){
				val=b;
			}
			cnt[node[i+1].type]--;
			sum+=val;
			if(sum>T){
				break;
			}
		}
		printf("%d\n",maxn);
	}
	return 0;
}

















