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
const int MAXN=100020;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
vector<int>ans1;
int main(){
	ll a,b;
	cin>>a>>b;
	if(a==b){
		cout<<0<<endl;
		return 0;
	}
	ll t=abs(a-b);
	for(int i=1;i*i<=t;i++){
		if(t%i==0){
			if(t/i==i){
				ans1.push_back(i);
			}
			else{
				ans1.push_back(i);
				ans1.push_back(t/i);
			}
		}
	}
	ll minn=1e18+1;
	ll ans=-1;
	for(int i=0;i<ans1.size();i++){
		ll t=ans1[i];
		if(a%t==b%t){
			if(a%t==0){
				if(minn>=a/t*b){
					minn=a/t*b;
					ans=0;
				}
			}
			else {
				if(minn>(a/t+1)*t*(b/t+1)){
					minn=(a/t+1)*t*(b/t+1);
					ans=(a/t+1)*t-a;
				}
				else if(minn==(a/t+1)*t*(b/t+1)){
					ans=min(ans,(a/t+1)*t-a);
				}
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}