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
vector<int>G[MAXN];
int n,m;
int f[MAXN];
void getf(int m,vector<int>T[]){
	f[0]=-1;
	int i,j;
	for(i=1;i<m;i++){
		j=f[i-1];
		while(T[j+1]!=T[i]&&j>=0) j=f[j];
		if(T[j+1]==T[i]) f[i]=j+1;
		else f[i]=-1;
	}
	return;
}
int main(){
	gi2(n,m);
	for(int i=1;i<=m;i++){
		int x,y;
		gi2(x,y);
		int t=0;
		if(y>x) t=y-x;
		else t=n-x+y;
		G[x-1].push_back(t);
		swap(x, y);
		if(y>x) t=y-x;
		else t=n-x+y;
		G[x-1].push_back(t);
	}
	for(int i=0;i<n;i++){
		if(G[i].size()>=2)
			sort(G[i].begin(),G[i].end());
	}
	getf(n,G);
	int t=f[n-1]+1;
	if(t!=0&&n%(n-t)==0){
		printf("Yes\n");
	}
	else 
		printf("No\n");

	
	
	
	return 0;
}















