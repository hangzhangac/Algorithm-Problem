#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
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
map<ll,int>ms;
int main(){
	
	ll n;cin>>n;
	int i=2;
	int t=ceil(log(n)/log(2)+1);
	//cout<<t<<endl;
	int cnt=0;
	while(i<=t){
		//int a=ceil(log(n)/log(i));
		ll x=ceil(pow(n,1.0/i))+1;
		for(ll j=2;j<=x;j++){
			int k=i;
			ll ans=1;
			while(k--){
				ans=ans*j;
			}
			if(ans>n||ans<=2)continue;
			if(ms[ans]==0){
				ms[ans]=1;
				cnt++;
			}
		}
		i++;
	}
	cout<<n-cnt<<endl;
	
	return 0;
}


