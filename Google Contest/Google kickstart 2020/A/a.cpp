#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>
#define lson i<<1
#define rson i<<1|1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define gc(x) scanf("%c",&x)
#define gc2(x,y) scanf("%c%c",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const double PI = acos(-1.0); 
const int MAXN=100005;
const ll mod=1e7+9;
const ll llinf = (ll)(1e18) + 500;
const int inf=0x3f3f3f3f;
int a[MAXN];
int main(){
	int T;gi(T);
	int cnt1=1;
	while(T--){
		int n;
		gi(n);
		int b;gi(b);
		for(int i=1;i<=n;i++){
			gi(a[i]);
		}
		sort(a+1,a+n+1);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(b>=a[i]){
				b-=a[i];
				cnt++;
			}
			else break;
		}
		printf("Case #%d: %d\n",cnt1++,cnt);
	}
	return 0;
}











