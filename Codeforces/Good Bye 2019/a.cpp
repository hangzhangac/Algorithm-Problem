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
int book[105];
int main(){
	int T;
	gi(T);
	while(T--){
		mem(book,0);
		int n,k1,k2;
		cin>>n>>k1>>k2;
		for(int i=1;i<=k1;i++){
			int x;gi(x);
			book[x]=1;
		}
		for(int i=1;i<=k2;i++){
			int x;
			gi(x);
		}
		if(book[n]==1){
			printf("YES\n");
		}
		else printf("NO\n");
		
	}
	
	
	
	return 0;
}


