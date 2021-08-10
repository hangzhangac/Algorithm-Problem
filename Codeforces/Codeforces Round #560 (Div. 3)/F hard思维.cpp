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
int n,m;
vector<int>G[MAXN*2];
struct Node{
	int dy,ty;
}node[MAXN];;
int k[MAXN];
int kk[MAXN];
bool cmp(Node a,Node b){
	return a.dy<b.dy;	
}
int t[MAXN];
bool C(int mid){
	for(int i=1;i<=n;i++){t[i]=-1;kk[i]=k[i];}
	for(int i=1;i<MAXN;i++)G[i].clear();
	for(int i=1;i<=m;i++){
		if(node[i].dy>mid)break;
		t[node[i].ty]=node[i].dy;
	}
	for(int i=1;i<=n;i++){
		if(t[i]!=-1){
			G[t[i]].push_back(i);
		}
	}
	int ans=0;
	for(int i=1;i<=mid;i++){
		ans++;
		for(int j=0;j<G[i].size();j++){
			int ty=G[i][j];
			if(kk[ty]){
				int tt=min(ans,kk[ty]);
				ans-=tt;
				kk[ty]-=tt;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(kk[i]>0)ans-=2*kk[i];
	}
	return ans>=0;
	
}
int main(){
	
	gi2(n,m);
	for(int i=1;i<=n;i++){
		gi(k[i]);
	}
	for(int i=1;i<=m;i++){
		gi2(node[i].dy,node[i].ty);
	}
	sort(node+1,node+m+1,cmp);
	int l=1,r=400000;
	int ans=r;
	while(l<=r){
		int mid=(l+r)/2;
		if(C(mid)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%d\n",ans);
	
	
	
	
	
	return 0;
}