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
int sum1[MAXN];
int sum2[MAXN];
int tmp1[MAXN];
int tmp2[MAXN];
char a[MAXN];
char b[MAXN];
int main(){
	
	int T,cnt=1;
	gi(T);
	int n,m;
	while(T--){
		gi(m);
		scanf("%s",a+1);
		n=2*m-2;
		for(int i=1;i<=n;i++){
			if(a[i]=='S'){b[i]='E';}
			else b[i]='S';
		}
		b[n+1]='\0';
		printf("Case #%d: ",cnt++);
		printf("%s\n",b+1);
	}
	return 0;
}