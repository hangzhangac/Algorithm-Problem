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
const int MAXN=1005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN][MAXN];
int r[MAXN],c[MAXN];
int main(){
	
	int h,w;
	gi2(h,w);
	for(int i=1;i<=h;i++)gi(r[i]);
	for(int i=1;i<=w;i++)gi(c[i]);
	for(int i=1;i<=h;i++){
		for(int j=1;j<=r[i];j++){
			a[i][j]=1;
		}
		if(r[i]+1<=w)
			a[i][r[i]+1]=2;
	}
	for(int i=1;i<=w;i++){
		for(int j=1;j<=c[i];j++){
			if(a[j][i]==2){
				printf("0\n");
				return 0;
			}
			a[j][i]=1;
		}
		if(c[i]+1<=h){
			if(a[c[i]+1][i]==1){
				printf("0\n");
				return 0;
			}
			a[c[i]+1][i]=2;
		}
			
	}
	int cnt=0;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(a[i][j]==0){
				cnt++;
			}
		}
	}
	ll ans=1;
	while(cnt--){
		ans*=2;
		ans%=mod;
	}
	printf("%lld\n",ans);
	
	
	
	
	return 0;
}














