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
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;

int a[MAXN],b[MAXN];
int book[MAXN];
vector<int>G[MAXN];
int ss[MAXN];
int cnt;
int C(){
	int maxn=1;
	int num=1;
	for(int i=2;i<=cnt;i++){
		if(G[i-1][G[i-1].size()-1]<G[i][0]){
			num++;
		}
		else num=1;
		maxn=max(maxn,num);
	}
	return cnt-maxn;
}
int main(){
	int q;gi(q);
	while(q--){
		int n;
		gi(n);
		for(int i=1;i<=n;i++){
			gi(a[i]);
			b[i-1]=a[i];
			book[i]=0;
			G[i].clear();
		}
		sort(b,b+n);
		int t=unique(b, b+n)-b;
		for(int i=0;i<t;i++){
			ss[b[i]]=i+1;
		}
		cnt=t;
		for(int i=1;i<=n;i++){
			a[i]=ss[a[i]];
			G[a[i]].push_back(i);
		}
		for(int i=1;i<=cnt;i++){
			sort(G[i].begin(),G[i].end());
		}
		printf("%d\n",C());
	}
	
	
	return 0;
}






