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
int a[5];
int main(){
	int T;
	int cnt=0;
	scanf("%d",&T);
	while(T--){
		int cnt=0;
		for(int i=1;i<=3;i++){
			gi(a[i]);
			if(a[i]){
				cnt++;
				a[i]--;
			}
		}	
		sort(a+1,a+3+1);
		if(a[3]&&a[2])a[3]--,a[2]--,cnt++;
		if(a[3]&&a[1])a[3]--,a[1]--,cnt++;
		if(a[2]&&a[1])a[2]--,a[1]--,cnt++;
		if(a[2]&&a[1]&&a[3])cnt++;
		printf("%d\n",cnt);
		
	}
	return 0;
}