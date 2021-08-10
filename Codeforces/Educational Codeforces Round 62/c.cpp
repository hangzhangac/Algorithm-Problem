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
int n,k;
struct Node{
	ll t;
	ll b;
}node[MAXN];
bool cmp(Node a,Node b){
	return a.b<b.b;
}
ll sum[MAXN];
ll mm[MAXN];
priority_queue<int,vector<int>, greater<int> > q; 
int main(){
	
	gi2(n,k);
	for(int i=1;i<=n;i++){
		gll2(node[i].t,node[i].b);
	}
	sort(node+1,node+n+1,cmp);
	ll cnt=0;
	ll maxn=0;
	for(int i=n;i>=n-k+1+1;i--){
		q.push(node[i].t);
		cnt+=node[i].t;
		maxn=max(maxn,cnt*node[i].b);
	}
	
	for(int i=n-k+1;i>=1;i--){
		maxn=max(maxn,(node[i].t+cnt)*node[i].b);
		if(q.empty())continue;
		ll x=q.top();
		if(x<node[i].t){
			cnt-=x;
			q.pop();
			q.push(node[i].t);
			cnt+=node[i].t;
		}
	}
	printf("%lld\n",maxn);
	
	
	
	
	
	return 0;
}











