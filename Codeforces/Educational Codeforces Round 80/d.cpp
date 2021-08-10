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
const int inf = 0x3f3f3f3f;
const int MAXN = 3e5 + 5;
int rec[1 << 11], recl[1<<11];
int a[MAXN][8];


int main() {
	int n, m;
	gi2(n,m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) gi(a[i][j]);
	}
	for (int i = 0; i < n; i++) {
		for (int k = 1; k < 1 << m; k++) {
			int mn = inf;
			for (int j = 0; j < m; j++) {
				if ( (k >> j) & 1) mn = min(mn, a[i][j]);
			}
			if (mn > rec[k])
				rec[k] = mn, recl[k] = i;
		}
	}
	int ans = 0, t = (1<<m)-1, ans1=0, ans2=0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < 1 << m; k++) {
			int mn = inf;
			for (int j = 0; j < m; j++) {
				if ( (k >> j) & 1) mn = min(mn, a[i][j]);
			}
			if (mn>ans && rec[t-k]>ans) {
				ans = min(mn, rec[t - k]);
				ans1 = i;
				ans2 = recl[t - k];
			}
		}
	}
	printf("%d %d\n",ans1+1,ans2+1);
	return 0;
}