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

int main() {
	
	int T;gi(T); while (T--) {
		int n; 
		ll x = 0, y = 0,s = 1ll<<58;;
		gi(n);
		for (int i = 0; i < n; i++) {
			int a;gi(a);
			x += a; y ^= a;
		}
		if (x == 2 * y) {
			printf("0\n");
			printf("\n");
		}
		else{
			cout << 3 << endl;
			if (y & 1) {
				x += s+1; y ^= (s+1);
				ll t = (2*y-x) / 2;
				cout << s+1 << " " << t << " " << t << endl;
			}
			else {
				x += s; y ^= s;
				ll t = (2*y-x) / 2;
				cout <<s<<" " <<t << " " << t << endl;
			}
		}
	}
	return 0;
}
