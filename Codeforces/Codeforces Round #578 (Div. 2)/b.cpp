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
int n,m,k;
int h[105];
int main(){
	int t;gi(t);
	while(t--){
	gi3(n,m,k);
	for(int i=1;i<=n;i++){
		gi(h[i]);
	}
	int flag=0;
	for(int i=1;i<=n-1;i++){
		if(h[i]<=h[i+1]){
			if(h[i+1]-h[i]<=k){
				m+=min(h[i],h[i]-(h[i+1]-k));
			}
			else{
				m-=(h[i+1]-k)-h[i];
				
			}
		}
		else{
			m+=min(h[i],h[i]-(h[i+1]-k));
		}
		if(m<0){
			printf("NO\n");flag=1;break;
		}
	}
	
	if(flag==0)
	printf("YES\n");
	}
	
	
}