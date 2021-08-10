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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
int a[MAXN],b[MAXN];
int ans[MAXN];
int main(){
	
	int T;gi(T);
	while(T--){
		ll n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans[i]=inf;
		}
		for(int i=1;i<=m;i++)cin>>b[i];
		int l=-1;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				l=i;
			}
			if(l!=-1)
				ans[i]=i-l;
		}
		int r=-1;
		for(int i=n;i>=1;i--){
			if(a[i]==2)r=i;
			if(r!=-1)ans[i]=min(ans[i],r-i);
		}
		for(int i=1;i<=m;i++){
			int out=0;
			if(b[i]==1)out=0;
			else{
				if(ans[b[i]]==inf)out=-1;
				else out=ans[b[i]];
			}
			if(i==1){
				cout<<out;
			}
			else cout<<" "<<out;
		}
		cout<<endl;
		
	}
	return 0;
}



