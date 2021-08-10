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
priority_queue<int,vector<int>, less<int> > q;
int n;
struct Node{
	int a,t;
}node[MAXN];
bool cmp(Node a,Node b){
	return a.a<b.a;
}
bool cmp1(Node a,Node b){
	return a.t<b.t;
}
vector<Node>ans;
int main(){
	
	gi(n);
	for(int i=1;i<=n;i++){
		gi(node[i].a);
	}
	for(int i=1;i<=n;i++){
		gi(node[i].t);
	}
	sort(node+1,node+n+1,cmp);
	ll cnt=0;
	int i=1;
	ll sumt=0;
	while(i<=n){
		int cur=node[i].a;
		sumt+=node[i].t;
		q.push(node[i].t);
		i++;
		while(i<=n&&node[i].a==cur){
			q.push(node[i].t);
			sumt+=node[i].t;
			i++;
		}
		sumt-=q.top();
		q.pop();
		int nex=0;
		if(i<=n)nex=node[i].a;
		else nex=2e9;
		int num=1;
		while(!q.empty()&&cur+num<nex){
			cnt+=1LL*num*q.top();
			sumt-=q.top();
			q.pop();
			num++;
		}
		cnt+=sumt*(nex-cur);
	}
	printf("%lld\n",cnt);
	
	
	
	
	return 0;
}


















