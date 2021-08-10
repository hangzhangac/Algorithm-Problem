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
int book[MAXN];
int n,m;
int b[MAXN],a[MAXN];
int lowbit(int k){
	return k&(-k);
}
int c[MAXN];
int getsum(int i){
	int sum=0;
	while(i>0){
		sum+=c[i];
		i-=lowbit(i);
	}
	return sum;
}
void update(int i,int j){
	while(i<=m){
		c[i]+=j;
		i+=lowbit(i);
	}
}
int main(){
	int T;gi(T);
	while(T--){
		gi2(n,m);
		for(int i=1;i<=n;i++){
			book[i]=inf;
			c[i]=0;
			gi(a[i]);
		}
		for(int i=1;i<=m;i++){
			gi(b[i]);
			book[b[i]]=i;
			update(i, 1);
		}
		for(int i=1;i<=n;i++){
			a[i]=book[a[i]];
		}
		int minn=inf+1;
		ll ans=0;
		for(int i=n;i>=1;i--){
			if(a[i]==inf){
				continue;
			}
			update(a[i], -1);
			if(a[i]>minn){
				ans++;
			}
			else{
				int x=getsum(a[i]);
				ans+=(i-1-x)*2+1;	
			}
			minn=min(a[i],minn);
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}


