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
#include <stack>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=500005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
vector<int>G[MAXN];
vector<int>T[MAXN];
vector<int>ans;
int sum[MAXN];
int a[MAXN];
int book[MAXN];

int n,c;
int main(){
	ll anst=0;
	gi2(n,c);
	for(int i=0;i<MAXN;i++){
		G[i].push_back(0);
	}
	for(int i=1;i<=n;i++){
		gi(a[i]);
		if(a[i]==c)anst++;
		sum[i]=sum[i-1];
		if(a[i]==c)sum[i]++;
		G[a[i]].push_back(i);
		if(!book[a[i]]){
			book[a[i]]=1;
			ans.push_back(a[i]);
		}
	}
	for(int q=0;q<ans.size();q++){
		int zans=0;
		int cg=ans[q];
		if(cg==c)continue;
		for(int t=0;t<G[cg].size();t++){
			T[cg].push_back(0);
		}
		int maxn=0;
		for(int t=G[cg].size()-1;t>=1;t--){
			if(t==G[cg].size()-1){
				maxn=t-sum[G[cg][t]];
			}
			else{
				maxn=max(t-sum[G[cg][t]],maxn);
			}
			T[cg][t]=maxn;
		}
		for(int i=1;i<G[cg].size();i++){
			zans=max(zans,sum[G[cg][i]-1]+1-i+sum[n]+T[cg][i]);
		}
		//cout<<cg<<' '<<zans<<endl;
		anst=max(anst,1ll*zans);
	}
	printf("%lld\n",anst);
}