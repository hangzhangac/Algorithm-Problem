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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
vector<int>G[MAXN];
int book[MAXN];
int n,m;
int ans[MAXN];
ll cnt[105];
int in[MAXN];
int main(){
	gi2(n,m);
	mem(cnt,0);
	for(int i=1;i<=m;i++){
		int x,y;
		gi2(x,y);
		G[x].push_back(y);
		G[y].push_back(x);
		in[x]++;
		in[y]++;
	}
	for(int i=1;i<=n;i++){
		sort(G[i].begin(), G[i].end());
	}
	for(int i=1;i<=n;i++){
		if(in[i]<2){
			printf("-1\n");
			return 0;
		}
	}
	if(n==3){
		if(m==3)
			printf("1 2 3\n");
		else printf("-1\n");
		return 0;
	}
	int s[]={1,2,3,4,0};
	int x1=-1,x2=-1;
	do{
		if(G[s[0]]==G[s[1]]){
			x1=s[0],x2=s[1];
			break;
		}
	}while(next_permutation(s, s+4));
	if(x1==-1){
		printf("-1\n");return 0;
	}
	int e=-1;
	for(int x:G[x1]){
		book[x]++;
	}
	for(int x:G[x2]){
		book[x]++;
		if(book[x]==2){
			e=x;
		}
	}
	if(e==-1){
		printf("-1\n");
		return 0;
	}
	ans[x1]=1;ans[x2]=1;ans[e]=2;
	for(int x:G[e]){
		book[x]++;
		if(book[x]==3){
			ans[x]=3;
		}
	}
	for(int x:G[x1]){
		if(book[x]!=3){
			ans[x]=2;
		}
	}
	for(int x:G[x2]){
		if(book[x]!=3){
			ans[x]=2;
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==0)ans[i]=1;
		cnt[ans[i]]++;
	}
	if(cnt[1]*cnt[2]+cnt[3]*cnt[2]+cnt[3]*cnt[1]!=m||cnt[1]==0||cnt[2]==0||cnt[3]==0){
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int x:G[i]){
			if(ans[i]==ans[x]){
				printf("-1\n");
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}