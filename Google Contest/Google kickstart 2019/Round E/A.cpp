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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int f[MAXN];
int find1(int x){
	if(x==f[x])return x;
	return f[x]=find1(f[x]);
}
int main(){
	
	int T;
	gi(T);
	int cnt1=1;
	while(T--){
		int n,m;
		gi2(n,m);
		for(int i=1;i<=n;i++)f[i]=i;
		int cnt=0;
		for(int i=1;i<=m;i++){
			int x,y;
			gi2(x,y);
			int fx=find1(x),fy=find1(y);
			if(fx!=fy){
				f[fx]=fy;
				cnt++;
			}
		}
		int t=n-1-cnt;
		cnt+=2*t;
		printf("Case #%d: ",cnt1++);
		printf("%d\n",cnt);
	}
	return 0;
}