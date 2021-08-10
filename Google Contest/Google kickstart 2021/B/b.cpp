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
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
int lef[MAXN],rig[MAXN];
ll a[MAXN];
int main(){
	
	int T,cnt1=1;
	gi(T);while(T--){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		a[n+1]=1LL*inf*inf;
		a[0]=1LL*inf*inf;
		int cur=a[2]-a[1];
		int ans=2;
		lef[1]=1;
		lef[2]=2;
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]==a[i-1]-a[i-2]){
				lef[i]=lef[i-1]+1;
				ans=max(ans,lef[i]);
			}
			else{
				lef[i]=2;
			}
		}
		rig[n]=1;
		rig[n-1]=2;
		
		for(int i=n-2;i>=1;i--){
			if(a[i+1]-a[i]==a[i+2]-a[i+1]){
				rig[i]=rig[i+1]+1;
				ans=max(ans,rig[i]);
			}
			else{
				rig[i]=2;
			}
		}
		if(ans<n)ans++;
		for(int i=2;i<=n-1;i++){
			int l=a[i-1],r=a[i+1],c=a[i];
			
			if((r-l)&1)continue;
			
			c=l+(r-l)/2;
			
			int diff=(r-l)/2;
			int cnt=3;
			if(diff==a[i+2]-a[i+1]){
				cnt+=rig[i+1]-1;

			}
			if(diff==a[i-1]-a[i-2]){
				cnt+=lef[i-1]-1;
			}
			ans=max(ans,cnt);
		}
		printf("Case #%d: ",cnt1++);
		if(n<=3){
			cout<<n<<endl;
		}
		else{
			cout<<ans<<endl;
		}
	}
	
	
	return 0;
}

























