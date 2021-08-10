#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=200005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;

char s[MAXN];
char t[MAXN];
int q[MAXN];
int p[MAXN];
int n,m;
int main() {
	cin>>n>>m;
	cin>>(s+1);
	cin>>(t+1);
	int tt=1;
	int i=1;
	while(tt<=m){
		while(t[tt]!=s[i]){
			i++;
		}
		q[tt]=i;
		tt++;
		i++;
	}
	i=n;tt=m;
	while(tt>=1){
		while(t[tt]!=s[i])i--;
		p[tt]=i;
		tt--;
		i--;
	}
	int maxn=0;
	for(int i=1;i<=m-1;i++){
		maxn=max(maxn,p[i+1]-q[i]);
	}
	cout<<maxn<<endl;
	
	
	return 0;
}















