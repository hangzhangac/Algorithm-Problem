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
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
const int N=1010000;
int n,m,x,cnt[N];
int dp[10][10],pd[10][10];

int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		scanf("%d",&x);
		cnt[x+2]++;
	}
	m+=2;
	memset(dp,0xaa,sizeof(dp));
	dp[0][0]=0;
	rep(i,1,m+1) {
		rep(p1,0,3) rep(p2,0,3) pd[p1][p2]=dp[p1][p2],dp[p1][p2]=0xaaaaaaaa;
		rep(p1,0,3) rep(p2,0,3) { // p1个i p2个j
			if (p1>cnt[i]) continue;
			if (p1+p2>cnt[i+1]) continue;
			rep(p3,0,3) if (p1+p2+p3<=cnt[i+2])
				dp[p2][p3]=max(dp[p2][p3],pd[p1][p2]+(cnt[i+2]-p1-p2-p3)/3+p1);
		}
	}
	printf("%d\n",dp[0][0]);
}