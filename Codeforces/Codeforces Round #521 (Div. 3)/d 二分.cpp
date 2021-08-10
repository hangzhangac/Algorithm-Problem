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
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
struct Node{
	int num;
	int id;
}node[MAXN];
bool cmp(Node a,Node b){
	return a.num>b.num;
}
int n,k;
vector<int>ans;
bool C(int mid){
	ll ans=0;
	for(int i=1;i<=200000;i++){
		if(node[i].num==0)return false;
		ans+=node[i].num/mid;
		if(ans>=k)return true;
	}
	return false;
	
}
int main(){
	
	gi(n);gi(k);
	for(int i=1;i<=2*100000;i++){
		node[i].id=i;
		node[i].num=0;
	}
	for(int i=1;i<=n;i++){
		int x;gi(x);
		node[x].num++;
	}
	sort(node+1,node+200000+1,cmp);
	int l=1,r=200000;
	while(l<=r){
		int mid=(l+r)/2;
		if(C(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	int cnt=0;
	for(int i=1;i<=200000;i++){
		int t=node[i].num/r;
		for(int j=1;j<=t&&cnt<k;j++,cnt++){
			ans.push_back(node[i].id);
		}
	}
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	
	
	
	return 0;
}
































