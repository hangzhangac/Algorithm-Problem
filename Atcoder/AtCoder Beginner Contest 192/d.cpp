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
string a;
ll M;
bool C(ll n){
	ll base=1;
	ll ans=0;
	for(int i=a.size()-1;i>=0;i--){
		int t=a[i]-'0';
		if(M*1.0/t<base)return false;
		ll plus=t*base;
		if(M-ans<plus)return false;
		ans=ans+plus;
		if(i!=0){
			if(M*1.0/n<base)return false;
			base=base*n;
		}
		
	}
	if(ans<=M)return true;
	else return false;
}
int main(){
	

	cin>>a;
	cin>>M;
	char maxn='0';
	for(int i=0;i<a.size();i++){
		maxn=max(maxn,a[i]);
	}
	
	int t=maxn-'0';
	if(a.size()==1){
		if(t<=M){
			cout<<1<<endl;
		}
		else cout<<0<<endl;
		return 0;
	}
	ll l=t+1,r=1e18+10;
	cout<<r<<endl;
	while(l<=r){
		ll mid=(l+r)/2;
		if(C(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	//cout<<r<<endl;
	cout<<r-t<<endl;
	
	return 0;
}













