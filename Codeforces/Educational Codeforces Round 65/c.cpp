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
const int MAXN=500005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int f[MAXN];
int a[MAXN];
int cnt[MAXN];
int find1(int x){
	if(x==f[x]){
		return x;
	}
	return f[x]=find1(f[x]);
}
int main(){
	int n,m;
	gi2(n,m);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int x;
		gi(x);
		for(int i=1;i<=x;i++){
			gi(a[i]);
			if(i==1)continue;
			int fx=find1(a[i-1]),fy=find1(a[i]);
			if(fx==fy)continue;
			f[fx]=fy;
		}
	}
	for(int i=1;i<=n;i++){
		int fx=find1(i);
		cnt[fx]++;
	}
	for(int i=1;i<=n;i++){
		printf("%d ",cnt[find1(i)]);
	}
	
	
	
	
	return 0;
}