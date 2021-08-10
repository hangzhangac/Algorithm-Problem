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
int a[MAXN];
map<int,int>ms;
int main(){
	int T,cnt1=1;gi(T);while(T--){
		ms.clear();
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			gi(a[i]);
		}
		sort(a+1,a+n+1);
		a[0]=0;
		a[n+1]=k+1;
		int maxn=0;
		vector<int>s;
		for(int i=1;i<=n+1;i++){
			if(ms[a[i]])continue;
			ms[a[i]]=1;
			maxn=max(a[i]-a[i-1]-1,maxn);
			if(i==1||i==n+1){
				s.push_back(a[i]-a[i-1]-1);
			}
			else{
				int qq=a[i]-a[i-1]-1;
				s.push_back((qq+1)/2);
			}
			
		}
		sort(s.begin(),s.end());
		int t=s.size();
		ll ans=1LL*s[t-1]+1LL*s[t-2];
		ans=max(ans,1ll*maxn);
		double aa=ans*1.0/(1LL*k);
		printf("Case #%d: ",cnt1++);
		printf("%.8lf\n",aa);
	}
	
	
	
	return 0;
}




















