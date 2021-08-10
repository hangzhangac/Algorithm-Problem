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
vector<int>G[MAXN];
int n;
int dfs(int u,int f,int k){
	vector<int>q;
	int minn=n;
	int maxn=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f)continue;
		int e=dfs(v,u,k);
		if(e==-1)return -1;
		if(u!=1&&e>=k){return -1;}
		if(u==1)
			q.push_back(e);
		minn=min(e,minn);
		maxn=max(maxn,e);
	}
	if(u==1){
		if(G[u].size()==1){
			if(maxn>k)return -1;
		}
		else{
			sort(q.begin(),q.end());
			int s=q.size();
			if(q[s-1]>k)return -1;
			if(q[s-1]==k&&q[s-2]==k){return -1;}
		}
	}
	if(minn==n)return 1;
	else return minn+1;
}
bool C(int k){
	
	int t=dfs(1,-1,k);
	if(t==-1)return false;
	return true;
}
int main(){
	int T;gi(T);
	while(T--){
		gi(n);
		for(int i=1;i<=n-1;i++){
			int a,b;
			gi2(a,b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		int l=1,r=n-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(C(mid)){
				r=mid-1;
			}
			else l=mid+1;
		}
		cout<<l<<endl;
		for(int i=1;i<=n;i++)G[i].clear();
	}
	return 0;
}