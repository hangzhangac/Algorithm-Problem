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
ll a[64];
vector<int>ans;
int main() {
	
	int T;gi(T);
	a[1]=2;
	for(int i=2;i<=60;i++){
		a[i]=a[i-1]*2+2;
	}
	while(T--){
		ans.clear();
		ll k;
		gll(k);
		if(k&1)cout<<"-1"<<endl;
		else{
			vector<int>x;
			while(k){
				x.push_back(k&1);
				k/=2;
			}
			for(int i=0;i<x.size();i++){
				if(x[i]==1){
					for(int j=1;j<=i-1;j++){
						if(j==1)ans.push_back(1);
						else ans.push_back(0);
					}
					ans.push_back(1);
				}
			}
			cout<<ans.size()<<endl;
			for(int i=0;i<ans.size();i++){
				cout<<ans[i]<<' ';
			}
			cout<<endl;
		}
		
	}
	
	
	
	
	
	
	return 0;
}





















