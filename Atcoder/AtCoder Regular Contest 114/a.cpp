#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;

ll a[MAXN];
ll x[16]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
ll minn=1LL*inf*inf;
int n;
void dfs(int i,ll cur,vector<ll>&v){
	
	ll maxn=1LL*inf*inf;
	if(i==16){
		int cnt=0;
		for(int j=1;j<=n;j++){
			for(int k=0;k<v.size();k++){
				if(a[j]%v[k]==0){
					cnt++;
					break;
				}
			}
		}
		if(cnt==n)
			minn=min(minn,cur);
		return;
	}
	if(maxn/cur<x[i]){
		
	}
	else{
		v.push_back(x[i]);
		dfs(i+1,cur*x[i],v);
		v.pop_back();
	}
	dfs(i+1,cur,v);
}
int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<ll>v;
	dfs(1,1,v);
	cout<<minn<<endl;
	return 0;
}


















