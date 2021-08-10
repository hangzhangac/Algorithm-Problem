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
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int main(){
	
	ll n,m,k,l;
	cin>>n>>m>>k>>l;
	if(l+k>n){
		//cout<<1<<endl;
		printf("-1\n");
		return 0;
	}
	ll t=l+k;
	ll cnt=t/m;
	ll q=t%m;
	ll b=0;
	if(q){
		b=m-q;
		cnt++;
	}
	if(b<=n-t){
		
	}
	else cnt=-1;
	printf("%lld\n",cnt);
	
	
	
	
	return 0;
}































