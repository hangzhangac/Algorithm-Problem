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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;int n,m;
int f[MAXN];
int maxn[MAXN];
int find1(int x){
	if(x==f[x])return x;
	return f[x]=find1(f[x]);
}
int main(){
	
	gi2(n,m);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v;
		gi2(u,v);
		int fx=find1(u),fy=find1(v);
		if(fx==fy)continue;
		if(fx<fy)swap(fx, fy);
		f[fy]=fx;
	}
	int i=1;
	int ans=0;
	while(i<=n){
		int id=i;
		int t=find1(id);
		while(i<=t&&i<=n){
			int x=id,y=i;
			int fx=find1(x),fy=find1(y);
			if(fx!=fy){
				if(fx<fy)swap(fx,fy);
				f[fy]=fx;
				ans++;
				t=max(t,fx);
			}
			i++;
		}
	}
	printf("%d\n",ans);
	
	
	
	
}