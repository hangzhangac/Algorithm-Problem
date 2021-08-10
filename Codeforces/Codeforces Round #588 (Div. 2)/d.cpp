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
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
map<ll,int>ms;
map<ll,int>val;
ll a[7005];
ll b[7005];
int book[7005];
vector<ll>ans;
int main(){
	int n;
	gi(n);
	
	for(int i=1;i<=n;i++){
		gll(a[i]);
	}
	for(int i=1;i<=n;i++){
		gll(b[i]);
	}
	for(int i=1;i<=n;i++){
		ms[a[i]]++;
		val[a[i]]+=b[i];
	}
	map<ll,int>::iterator it = ms.begin();
	while(it!=ms.end()){
		if(it->second>=2){
			ans.push_back(it->first);
		}
		it++;
	}
	ll cnt=0;
	for(int i=1;i<=n;i++){
		if(ms[a[i]]>=2){
			book[i]=1;
			cnt+=b[i];
		}
	}
	for(int i=0;i<ans.size();i++){
		ll t=ans[i];
		for(int i=1;i<=n;i++){
			if(book[i]==0&&(t&a[i])==a[i]){
				book[i]=1;
				cnt+=b[i];
			}
		}
	}
	printf("%lld\n",cnt);
	
	
	
	
	return 0;
}











