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
bool C(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return false;
	}
	return true;
}
ll n[MAXN];
int p[MAXN];
vector<int>a;
ll sum=0;
ll ans=0;
int m;
void dfs(int i,ll mul,ll mm){
	if(i==m+1){
		if(sum-mm==mul)ans=max(ans,mul);
		return;
	}
	dfs(i+1,mul,mm);
	for(int j=1;j<=n[i];j++){
		if(mul>sum/p[i])break;
		mul*=p[i];
		mm+=p[i];
		dfs(i+1, mul, mm);
	}
	return;
}
int main(){
	int T,cnt1=1;gi(T);while(T--){
		a.clear();
		ans=0;
		sum=0;
		gi(m);
		for(int i=1;i<=m;i++){
			gi(p[i]);gll(n[i]);
			sum+=n[i]*p[i];
		}
		dfs(1, 1, 0);
		printf("Case #%d: %lld\n",cnt1++,ans);
	}
	
	
	
	return 0;
}