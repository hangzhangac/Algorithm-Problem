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
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=400005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
struct Node{
	int w;
	int id;
}node[MAXN];
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int book[MAXN];
int ans[MAXN*2];
priority_queue<int,vector<int>,greater<int> >qmin;
priority_queue<int,vector<int>,less<int> >qmax;
char s[MAXN*2];
int main(){
	
	int n;gi(n);
	for(int i=1;i<=n;i++){
		gi(node[i].w);
		node[i].id=i;
	}
	sort(node+1,node+n+1,cmp);
	for(int i=1;i<=n;i++){
		book[i]=node[i].id;
		qmin.push(i);
	}
	int len=2*n;
	scanf("%s",s);
	for(int i=0;i<len;i++){
		if(s[i]=='0'){
			int t=qmin.top();
			qmin.pop();
			ans[i]=book[t];
			qmax.push(t);
		}
		else{
			int t=qmax.top();
			qmax.pop();
			ans[i]=book[t];
		}
	}
	for(int i=0;i<2*n;i++){
		printf("%d ",ans[i]);
	}
	
	
	
	return 0;
}







