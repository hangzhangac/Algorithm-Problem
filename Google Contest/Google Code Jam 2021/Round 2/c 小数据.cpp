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
const int MAXN=15;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
vector<int>G[MAXN];
int book[MAXN];
int n;
int v[MAXN];
ll ans=0;
void dfs(int i,vector<int>&a){
	if(i==n+1){
		ans++;
		return;
		
	}
	for(int j=1;j<=n;j++){
		if(book[j]==0){
			int cnt=1;
			int maxn=j;
			for(int k=int(a.size())-1;k>=0;k--){
				if(a[k]>maxn){
					maxn=a[k];
					cnt++;
				}
			}
			if(v[i]!=cnt)continue;
			book[j]=1;
			a.push_back(j);
			dfs(i+1,a);
			book[j]=0;
			a.pop_back();
		}
	}
	
}
int main(){
	
	int T,cnt1=1;gi(T);while(T--){
		cin>>n;ans=0;
		for(int i=1;i<=n;i++){
			book[i]=0;
			cin>>v[i];
		}
		vector<int>a;
		dfs(1,a);
		printf("Case #%d: ",cnt1++);
		cout<<ans<<endl;
	}
	
	
	
	return 0;
}






















