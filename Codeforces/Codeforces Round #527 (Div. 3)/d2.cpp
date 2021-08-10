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
#include <stack>
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
struct Node{
	int val,id;
	Node(){}
	Node(int a,int b){
		val=a,id=b;
	}
	bool operator < (const Node &b) const{
		if(val==b.val)return id>b.id;
		return val>b.val;
	}
}node[MAXN];
int pre[MAXN];
int nx[MAXN];
int main(){
	int n;
	gi(n);
	priority_queue<Node>q;
	int maxn=0;
	for(int i=1;i<=n;i++){
		pre[i]=i-1;
		nx[i]=i+1;
		gi(node[i].val);
		node[i].id=i;
		maxn=max(node[i].val,maxn);
		q.push(node[i]);
	}
	int flag=0;
	while(!q.empty()){
		Node s=q.top();q.pop();
		if(s.val==maxn)continue;
		if(q.empty()){
			flag=1;break;
		}
		Node t=q.top();q.pop();
		if(s.val!=t.val||nx[s.id]!=t.id||pre[t.id]!=s.id){
			flag=1;break;
		}
		int i=pre[s.id];
		int j=nx[t.id];
		pre[j]=i;
		nx[i]=j;
	}
	if(flag){
		printf("NO\n");
	}
	else printf("YES\n");
	return 0;
}