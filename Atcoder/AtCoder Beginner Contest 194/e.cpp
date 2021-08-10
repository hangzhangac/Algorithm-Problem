#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
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
const int MAXN=15*100001;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;
int book[MAXN];
int a[MAXN];
int n,m;
int main(){
	
	cin>>n>>m;
	set<int>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]++;
	}
	for(int i=1;i<=n+1;i++){
		s.insert(i);
	}
	int ans=n+1;
	for(int i=1;i<=m;i++){
		book[a[i]]=i;
		s.erase(a[i]);
	}
	ans=min(ans,*s.begin());
	for(int i=m+1;i<=n;i++){
		book[a[i]]=i;
		s.erase(a[i]);
		if(book[a[i-m]]==i-m){
			s.insert(a[i-m]);
		}
		ans=min(ans,*s.begin());
	}
	cout<<ans-1<<endl;
	
	
	return 0;
}



















