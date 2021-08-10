#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>
#define lson i<<1
#define rson i<<1|1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define gc(x) scanf("%c",&x)
#define gc2(x,y) scanf("%c%c",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const double PI = acos(-1.0); 
const int MAXN=100005;
const ll mod=1e7+9;
const ll llinf = (ll)(1e18) + 500;
const int inf=0x3f3f3f3f;
int a[MAXN];
int n;
vector<int> get(int x){
	std::vector<int> ans;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			ans.push_back(i);
			if(x/i!=i){
				ans.push_back(x/i);
			}
		}
	}
	ans.push_back(x);
	return ans;
}
int main(){
	
	//freopen("a.txt","r",stdin); 
	gi(n);
	int sum=0;
	for(int i=1;i<=n;i++){
		gi(a[i]);
		sum+=a[i];
	}
	if(sum==1){
		printf("-1\n");
		return 0;
	}
	vector<int>ans=get(sum);
	ll minn=1ll*n*n;
	for(int p=0;p<ans.size();p++){
		int base=ans[p];
		std::vector<int> v;
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				v.push_back(i);
				if(v.size()==base){
					//printf("%d\n",base);
						int mid=base/2;
						for(int j=0;j<base;j++)
							ans+=abs(v[j]-v[mid]);
					v.clear();
					//printf("%lld\n",ans);
				}
			}
		}
		//printf("%lld\n",ans);
		minn=min(minn,ans);
	}
	printf("%lld\n",minn);
	return 0;
}