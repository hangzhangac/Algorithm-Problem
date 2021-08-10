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
ll n;
ll m,k;
ll p[MAXN];
int main(){
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		gll(p[i]);
		p[i]--;
	}
	int cnt=0;
	int i=1;
	int op=0;
	while(i<=m){
		int num=1;
		ll t=(p[i]-cnt)/k;
		i++;
		while(i<=m&&(p[i]-cnt)/k==t){
			num++;
			i++;
		}
		cnt+=num;
		op++;
	}
	printf("%d\n",op);
	return 0;
}















