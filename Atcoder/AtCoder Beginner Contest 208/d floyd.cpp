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
const int MAXN=405;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
int a[MAXN][MAXN];
int main(){
	
	int n,m;
	gi2(n, m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=inf;
		}
		a[i][i]=0;
	}
	while(m--){
		int b,c,d;
		cin>>b>>c>>d;
		a[b][c]=d;
	}
	ll ans=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
			}
		}
		ll sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]!=inf)ans+=a[i][j];
			}
		}
	}
	cout<<ans<<endl;
	
	
	return 0;
}










