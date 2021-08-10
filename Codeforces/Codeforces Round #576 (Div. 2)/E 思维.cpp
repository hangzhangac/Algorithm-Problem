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
int book[MAXN];
vector<int>ans;
int main(){
	int T;gi(T);
	while(T--){
		int n,m;
		gi2(n,m);
		for(int i=1;i<=3*n;i++)book[i]=0;
		ans.clear();
		for(int i=1;i<=m;i++){
			int u,v;gi2(u,v);
			if(!book[u]&&!book[v]){
				book[u]=book[v]=1;
				ans.push_back(i);
			}
		}
		if(ans.size()>=n){
			puts("Matching");
			for(int i=0;i<n;i++){
				printf("%d%c",ans[i],i==n-1?'\n':' ');
			}
		}
		else{
			puts("IndSet");
			int cnt=0;
			for(int i=1;i<=3*n;i++){
				if(book[i]==0){
					cnt++;
					printf("%d",i);
					printf("%c",cnt==n?'\n':' ');
				}
				if(cnt==n)break;
			}
		}
	}
	return 0;
}