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
int n;
int p[MAXN],c[MAXN];
int book[MAXN];
vector<int>G[MAXN];
int main(){
	
	
	gi(n);
	for(int i=1;i<=n;i++){
		gi2(p[i],c[i]);
		if(p[i]!=-1){
			G[p[i]].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			book[i]=1;
			if(p[i]!=-1){
				book[p[i]]=1;
			}
		}
	}
	int flag=1;
	for(int i=1;i<=n;i++){
		if(!book[i]){
			printf("%d ",i);
			flag=0;
		}
	}
	if(flag){
		printf("-1\n");
	}
	
	
	
	
	
	
	return 0;
}








