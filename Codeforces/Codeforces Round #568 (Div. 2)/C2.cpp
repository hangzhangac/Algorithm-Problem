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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int shuzi[MAXN];
priority_queue<int>q;
priority_queue<int, vector<int>, greater<int> >p;
int a[MAXN];
int b[MAXN];
int main() {
	int n,m;
	gi2(n,m);
	for (int i=1;i<=n;i++) {
		int t;
		gi(t);q.push(t);
		a[i]=m-t; 
		b[i]=t;
	}
	
	for (int i=1;i<=n;i++) {
		int cur,qq;
		cur=0;qq = a[i];
		for (int j = 1; j <= 100; j++) {
			int ss=min(qq/j,shuzi[j]);
			qq-=ss*j;
			cur+=ss;
		}
		printf("%d ",i-cur-1);
		shuzi[b[i]]++;
	}
}