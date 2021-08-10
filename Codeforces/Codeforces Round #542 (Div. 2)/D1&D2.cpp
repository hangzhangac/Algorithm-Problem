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
int a[MAXN],b[MAXN];
struct Node{
	int x,y;
	Node(){
		
	}
	Node(int z,int t){
		x=z,y=t;
	}
};
vector<Node>G[5005];
int book[MAXN];
bool cmp(Node a,Node b){
	return a.y<b.y;
}
int main(){
	int n,m;
	gi2(n,m);
	for(int i=1;i<=m;i++){
		gi2(a[i],b[i]);
		int plus=0;
		if(b[i]>=a[i])plus=b[i]-a[i];
		else plus=b[i]+n-a[i];
		G[a[i]].push_back(Node(b[i],plus));
	}
	for(int i=1;i<=n;i++){
		if(G[i].size()){
			sort(G[i].begin(),G[i].end(),cmp);
		}
	}
	for(int i=1;i<=n;i++)book[i]=i;
	for(int j=1;j<=n;j++){
		ll maxn=0;
		for(int i=1;i<=n;i++){
			
			if(G[book[i]].size()==0)continue;
			ll t=G[book[i]][0].x-j+1;
			if(t<1)t=n+t;
			int plus=0;
			if(t>i)plus=t-i;
			else plus=t+n-i;
			ll ans=(1LL*G[book[i]].size()-1)*n+plus+i-1;
			maxn=max(ans,maxn);
			//i=s;
		}
		for(int i=1;i<=n;i++){
			book[i]++;
			if(book[i]>n)book[i]-=n;
		}
		printf("%lld ",maxn);
		
	}
	
	
	
	
	
	
	
	return 0;
}











