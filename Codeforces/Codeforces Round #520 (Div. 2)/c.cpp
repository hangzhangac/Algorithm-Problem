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
char a[MAXN];
int sum1[MAXN];
int sum0[MAXN];
ll qc(ll x,int n){
	ll res=1;
	while(n){
		if(n&1)res=res*x%mod;
		n>>=1;
		x=x*x%mod;
	}
	return res%mod;
}
int main(){
	int n,q;
	cin>>n>>q;
	scanf("%s",a+1);
	int len=strlen(a+1);
	for(int i=1;i<=n;i++){
		sum1[i]=sum1[i-1];
		sum0[i]=sum0[i-1];
		if(a[i]=='1'){
			sum1[i]++;
		}
		else sum0[i]++;
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		int x=sum1[r]-sum1[l-1];
		int y=sum0[r]-sum0[l-1];
		ll ans1=qc(2LL,y);
		ll ans2=qc(2LL,x);
		ans2=(ans2-1+mod)%mod;
		printf("%lld\n",ans1*ans2%mod);
	}
	
}

