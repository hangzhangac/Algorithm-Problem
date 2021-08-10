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
const int MAXN=100005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;
vector<int>x;
vector<int>y;

int main(){
	
	int T,cnt1=1;gi(T);
	while(T--){
		printf("Case #%d: ",cnt1++);
		int n;gi(n);
		x.clear();
		y.clear();
		for(int i=1;i<=n;i++){
			int a,b;
			gi2(a,b);
			x.push_back(a);
			y.push_back(b);
		}
		sort(y.begin(),y.end());
		
		int t=y[n/2];
		ll ans=0;
		for(int i=0;i<n;i++){
			ans+=abs(t-y[i]);
		}
		sort(x.begin(),x.end());
		for(int i=0;i<x.size();i++){
			x[i]-=i;
		}
		sort(x.begin(),x.end());
		t=x[n/2];
		for(int i=0;i<n;i++){
			ans+=abs(t-x[i]);
		}
		
		printf("%lld\n",ans);
	}	
	
	
	return 0;
}







