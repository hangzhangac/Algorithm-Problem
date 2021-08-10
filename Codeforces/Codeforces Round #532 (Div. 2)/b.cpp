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
	
	int n,m;
	gi2(n,m);
	int x;
	int cnt=0;
	for(int i=1;i<=m;i++){
		gi(x);
		if(a[x]==0){
			a[x]++;
			cnt++;
		}
		else{
			a[x]++;
		}
		if(cnt==n){
			printf("1");
			cnt=0;
			for(int i=1;i<=n;i++){
				a[i]--;
				if(a[i]>=1)cnt++;
			}
		}
		else printf("0");
	}
	return 0;
}



















