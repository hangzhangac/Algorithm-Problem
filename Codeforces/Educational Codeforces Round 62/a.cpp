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
int a[MAXN];
int main(){
	
	int n;
	int cur=1;
	int cnt=0;
	gi(n);
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	while(1){
		int maxn=a[cur];
		while(cur<=n&&cur<maxn){
			cur++;
			maxn=max(maxn,a[cur]);
		}
		cnt++;
		if(cur>n)break;
		cur++;
		while(cur<=n&&a[cur]<=maxn){
			cur++;
		}
		if(cur>n)break;
	}
	printf("%d\n",cnt);
	
	
	
	
	return 0;
}











