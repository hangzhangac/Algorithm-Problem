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

int main(){
	
	int T;
	gi(T);
	while(T--){
		int n,d;
		cin>>n>>d;
		if(d<=n){
			printf("YES\n");
			continue;
		}
		int x=sqrt(d);
		x-=2;
		int minn=inf;
		for(int i=max(x,0);i<=min(x+1000,d);i++){
			int cost=i;
			if(d%(i+1)==0){
				cost+=d/(i+1);
			}
			else{
				cost+=d/(i+1)+1;
			}
			minn=min(minn,cost);
		}
		if(minn<=n){
			printf("YES\n");
		}
		else printf("NO\n");
	}
	
	
	
	return 0;
}













