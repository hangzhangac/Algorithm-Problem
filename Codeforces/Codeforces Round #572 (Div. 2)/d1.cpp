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
int in[MAXN];
vector<int>G[MAXN];
int main(){
	int n;
	gi(n);
	for(int i=1;i<=n-1;i++){
		int u,v;
		gi2(u,v);G[u].push_back(v);
		G[v].push_back(u);
		in[v]++;
		in[u]++;
	}
	if(n==2){
		printf("YES\n");
		return 0;
	}
	if(n==3){
		printf("NO\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(in[i]==2){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	
	
	return 0;
}

