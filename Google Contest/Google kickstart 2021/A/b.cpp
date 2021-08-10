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
const int MAXN=1005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
int n,m;
int a[MAXN][MAXN];
int book[4][MAXN][MAXN];
ll cal(ll a,ll b){
	if(a==1||b==1)return 0;
	ll ans=0;
	ans+=min(a/2,b)-1;
	ans+=min(b/2,a)-1;
	return ans;
}
int main() {
	int cnt=1;
	int T;gi(T);while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				gi(a[i][j]);
			}
		}
		int cur=0;
		
		for(int i=1;i<=n;i++){
			cur=0;
			for(int j=1;j<=m;j++){
				if(a[i][j]==0){
					cur=j;
				}
				else{
					book[0][i][j]=cur;
				}
			}
		}
		
		for(int i=1;i<=n;i++){
			cur=m+1;
			for(int j=m;j>=1;j--){
				if(a[i][j]==0){
					cur=j;
				}
				else{
					book[1][i][j]=cur;
				}
			}
		}
		
		for(int j=1;j<=m;j++){
			cur=0;
			for(int i=1;i<=n;i++){
				if(a[i][j]==0){
					cur=i;
				}
				else{
					book[2][i][j]=cur;
				}
			}
		}
		for(int j=1;j<=m;j++){
			cur=n+1;
			for(int i=n;i>=1;i--){
				if(a[i][j]==0){
					cur=i;
				}
				else{
					book[3][i][j]=cur;
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==0)continue;
				ll left=abs(book[0][i][j]-j);
				ll right=abs(book[1][i][j]-j);
				ll up=abs(book[2][i][j]-i);
				ll down=abs(book[3][i][j]-i);
				ans+=cal(left, up);
				ans+=cal(left,down);
				ans+=cal(right,up);
				ans+=cal(right,down);
//				if(i==3&&j==3){
//					cout<<left<<' '<<right<<' '<<up<<'a'<<down<<endl;
//				}
//				cout<<book[0][i][j]<<' '<<book[1][i][j]<<' ';
//				cout<<book[2][i][j]<<' '<<book[3][i][j]<<endl;
//				cout<<i<<' '<<j<<' '<<ans<<endl;
			}
		}
		printf("Case #%d: ",cnt++);
		cout<<ans<<endl;
	}
	
	return 0;
}
















