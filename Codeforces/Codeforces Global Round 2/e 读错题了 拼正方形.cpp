//第i(0<=i<=n-1)根棍子的长度为2^i,数量为a[i], 每根棍子只能出现在一个正方形中
//每个正方形可以由多个棍子组成(比如边长为2的正方形 可以由1 1 2 2 2 组成) 问最多拼成多少个正方形
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
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll a[MAXN];
int main(){
	int n;gi(n);
	ll ans=0;
	for(int i=0;i<n;i++){
		gll(a[i]);
		ans+=a[i]/4;
		a[i]%=4;
	}
	ll cnt=0;
	for(int i=0;i<n;i++){
		ll q=cnt+a[i];
		ans+=q/4;
		cnt=q%4;
		cnt/=2;
	}
	printf("%lld\n",ans);
	return 0;
}