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
vector<int>G[MAXN];
vector<int>T1[MAXN],T2[MAXN];
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
		G[x+n-1].push_back(t);
		T1[x-1].push_back(t);
		swap(x, y);
		if(y>x) t=y-x;
		else t=n-x+y;
		G[x-1].push_back(t);
		G[x+n-1].push_back(t);
		T1[x-1].push_back(t);
	}
	for(int i=0;i<2*n;i++){
		if(G[i].size()>=2)
			sort(G[i].begin(),G[i].end());
		if(T1[i].size()>=2)
			sort(T1[i].begin(),T1[i].end());
	}
	getf(n,T1);
	int i=0,j=0;
	while(i<2*n){
		if(G[i]==T1[j]){
			i++;
			j++;
			if(j==n){
				if(i-n!=0&&i-n!=n){
					printf("Yes\n");
					return 0;
				}
				j=f[j-1]+1;
			}
		}
		else{
			if(j==0)i++;
			else j=f[j-1]+1;
		}
	}
	printf("No\n");
	return 0;
}















