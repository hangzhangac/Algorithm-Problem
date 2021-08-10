#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <time.h>
#include <map>
#include <set>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
vector<int>v[MAXN];
int main(){
	v[0].push_back(1);
	v[0].push_back(1);
	int n;
	gi(n);
	for(int i=1;i<=2*n;i++){
		int x;gi(x);
		v[x].push_back(i);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		int t=abs(v[i][0]-v[i-1][0])+abs(v[i][1]-v[i-1][1]);
		int s=abs(v[i][1]-v[i-1][0])+abs(v[i][0]-v[i-1][1]);
		ans+=min(s,t);
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	
	
	return 0;
}















