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
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[5];
int flag=0;
int sum=0;
void dfs(int u,int ans){
	if(u==4){
		if(ans*2==sum){
			flag=1;
			return;
		}
		return;
	}
	dfs(u+1,a[u]+ans);
	dfs(u+1,ans);
}
int main(){
	
	for(int i=0;i<4;i++){
		cin>>a[i];
		sum+=a[i];
	}
	dfs(0,0);
	if(flag)printf("YES\n");
	else printf("NO\n");
	
	
	return 0;
}












