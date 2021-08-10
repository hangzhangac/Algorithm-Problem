#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <stack>
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
int in[MAXN];
int main(){
	int n,s;
	gi2(n,s);
	for(int i=1;i<=n-1;i++){
		int u,v;
		gi2(u,v);
		in[u]++;
		in[v]++;
	}
	if(n==2){
		printf("%.6lf\n",1.0*s);
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(in[i]==1){
			cnt++;
		}
	}
	double t=1.0*s/(1.0*cnt);
	printf("%.10lf\n",t*2.0);
	
	
	return 0;
}






























