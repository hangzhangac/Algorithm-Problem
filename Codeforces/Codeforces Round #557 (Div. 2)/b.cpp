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
int s[55][55];
int s1[55][55];
int ans[55][55];
int ans1[55][55];
int a[5005];
int book[MAXN];
int re[MAXN];
map<int,int>ms;
int main(){
	
	int n,m;
	gi2(n,m);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			gi(s[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			gi(s1[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int maxn=max(ans[i][j-1],ans[i-1][j])+1;
			int minn=min(s[i][j],s1[i][j]);
			int maxx=max(s[i][j],s1[i][j]);
			if(minn>=maxn){
				ans[i][j]=minn;
				ans1[i][j]=maxx;
			}
			else{
				ans[i][j]=maxx;
				ans1[i][j]=minn;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]<=ans[i-1][j]||ans[i][j]<=ans[i][j-1]||ans1[i][j]<=ans1[i-1][j]||ans1[i][j]<=ans1[i][j-1]){
				printf("Impossible\n");
				return 0;
			}
		}
	}
	printf("Possible\n");

	
	
	
	
	
	return 0;
}