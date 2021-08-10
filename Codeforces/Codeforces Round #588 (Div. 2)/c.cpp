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
vector<int>G[10];
int cal(int u){
	int cnt=0;
	for(int i=0;i<G[u].size();i++){
		if(G[u][i]!=-1)cnt++;
	}
	return cnt;
}
map<int,int>ms[8];
int aa[100];
int bb[100];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
		aa[i]=a;bb[i]=b;
	}
	if(n<=6){
		printf("%d\n",m);
	}
	else{
		int ans=0;
		int a[8];
		for(int i=1;i<=6;i++){
			int cnt=0;
			for(int j=1;j<=6;j++){
				cnt++;
				a[cnt]=j;
				if(j==i){
					cnt++;
					a[cnt]=j;
				}
			}
			do{
				int cnt=0;
				for(int i=0;i<m;i++){
					int x=aa[i],y=bb[i];
					if(a[x]>a[y])swap(x, y);
					if(a[x]<=a[y]&&!ms[a[x]][a[y]]){
						cnt++;
						ms[a[x]][a[y]]=1;
					}
				}
				for(int i=1;i<=7;i++)ms[i].clear();
				ans=max(ans,cnt);
				
			}while(next_permutation(a+1, a+cnt+1));
		}
		printf("%d\n",ans);
	}
	
	
	return 0;
}












