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
int n,m;

vector<int>G[MAXN*10][10];
vector<int>T[MAXN*10];
int s[10];
int ans[MAXN*10];
int cnt;

void solve(int x,int y,int t){
	int len=0;
	while(t){
		s[len++]=t%10;
		t/=10;
	}
	reverse(s, s+len);
	int pre=x;
	for(int i=0;i<len-1;i++){
		G[pre][s[i]].push_back(cnt);
		pre=cnt++;
	}
	G[pre][s[len-1]].push_back(y);
}

int main(){
	gi2(n,m);
	cnt=n+1;
	for(int i=1;i<=m;i++){
		int x,y;
		gi2(x,y);
		solve(x, y, i);
		solve(y, x, i);
	}
	mem(ans,-1);
	ans[1]=0;
	int t;
	T[t=1].push_back(1);
	for(int i=1;i<=t;i++){
		for(int j=0;j<=9;j++){
			bool flag=0;
			for(int cur:T[i]){
				for(int v:G[cur][j]){
					if(ans[v]!=-1)continue;
					ans[v]=(10LL*ans[cur]+j)%mod;
					T[t+1].push_back(v);
					flag=1;
				}
				
			}
			if(flag)t++;
		}
	}
	for(int i=2;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}