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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
struct Node{
	int num;
	int num1;
	bool operator < (const Node& t)const{    
		return num1 < t.num1;    
	}
}node[MAXN],a[MAXN];
bool cmp(Node a,Node b){
	if(a.num==b.num)return a.num1>b.num1;
	return a.num>b.num;
}
int main(){
	
	int T;
	gi(T);
	while(T--){
		int n;
		gi(n);
		priority_queue<Node>q;
		for(int i=1;i<=n;i++)node[i].num=node[i].num1=0;
		for(int i=1;i<=n;i++){
			int x;gi(x);
			node[x].num++;
			int f;gi(f);
			if(f)node[x].num1++;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(node[i].num){
				a[++cnt]=node[i];
			}
		}
		sort(a+1,a+cnt+1,cmp);
		int maxn=a[1].num;
		int i=1,sum=0,sum1=0;
		for(int j=maxn;j>=1;j--){
			while(i<=cnt&&a[i].num>=j){
				q.push(a[i]);
				i++;
			}
			if(!q.empty()){
				Node e=q.top();
				q.pop();
				sum+=j;
				sum1+=min(j,e.num1);
			}
		}
		printf("%d %d\n",sum,sum1);
		
	}
	return 0;
}




