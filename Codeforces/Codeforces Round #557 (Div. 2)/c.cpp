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
int n,k;
int x[MAXN];
int book[MAXN];
int fir[MAXN];
bool vis[MAXN];
int main(){
	gi2(n,k);
	for(int i=1;i<=k;i++){
		gi(x[i]);
	}
	int cnt=0;
	ll ans=0;
	for(int i=1;i<=k;i++){
		if(!fir[x[i]]){
			fir[x[i]]=i;
			vis[i]=1;
		}
	}
	for(int i=k;i>=1;i--){
		if(!book[x[i]]){
			book[x[i]]=1;
			cnt++;
		}
		if(vis[i]){
			if(x[i]+1<=n&&!book[x[i]+1]){
				ans++;
			}
			if(x[i]-1>=1&&!book[x[i]-1]){
				ans++;
			}	
		}
	}
	for(int i=1;i<=n;i++){
		if(!book[i]){
			if(i==1||i==n)ans++;
			else ans+=2;
			ans++;
		}
	}
	printf("%lld\n",ans);
	
	
	

	
	
	
	
	return 0;
}






