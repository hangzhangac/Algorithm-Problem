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
int a[MAXN],n;
int book[100];
int q[MAXN];
int main(){
	gi(n);
	book[4]=1;book[8]=2;book[15]=3;book[16]=4;book[23]=5;
	book[42]=6;
	for(int i=1;i<=n;i++){
		gi(a[i]);
		if(a[i]==4){
			q[1]++;
		}
		else{
			int t=book[a[i]];
			if(q[t-1]>=1){
				q[t-1]--;
				q[t]++;
			}
		}
	}
	printf("%d\n",n-6*q[6]);
	
	return 0;
}