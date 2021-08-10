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
const int MAXN=505;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int row[MAXN],col[MAXN];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			gi(a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			gi(b[i][j]);
			if(a[i][j]!=b[i][j]){
				row[i]++;
				col[j]++;
			}
		}
	}
	int flag=1;
	for(int i=1;i<=n;i++){
		if(row[i]%2==1){
			flag=0;
		}
	}
	for(int i=1;i<=m;i++){
		if(col[i]%2==1){
			flag=0;
		}
	}
	
	if(flag){
		printf("YES\n");
	}
	else printf("NO\n");
	return 0;
}









