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
const int MAXN=200020;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n,m,k;
int g[MAXN];
int f[MAXN];
int a[MAXN];
int sum[MAXN];
int main(){
	gi3(n,m,k);
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	for(int i=1;i<=m;i++){
		int x,y;
		gi2(x,y);
		if(x<=k)g[x]=max(g[x],y);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=k;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=k;i++){
		f[i]=0;
		for(int j=0;j<i;j++){
			f[i]=max(f[i],f[j]+sum[j+g[i-j]]-sum[j]);
		}
	}
	cout<<sum[k]-f[k]<<endl;
	return 0;
}