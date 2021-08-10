#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
typedef unsigned long long ull;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
ll n,m,k;
ll pow_mod(ll x,ll n,ll mod){
    ll r=1;
    while(n>0){
        if(n&1){
            r*=x;
            r%=mod;
        }
        n/=2;
        x=x*x%mod;
    }
    return r;
}
ll cal(ll a,ll b){
    ll r=1;
    for(ll i=1;i<=b;i++){
        r*=(a-i+1);r%=mod;
        r*=pow_mod(i,mod-2,mod);r%=mod;
    }
    return r;
}
int main(){
    gll(n);
    gll(m);
    gll(k);
    if(n>m+k)cout<<0<<endl;
    else if(n<k+1)cout<<cal(n+m,n)<<endl;
    else cout<<(cal(n+m,n)-cal(n+m,n-k-1)+mod)%mod<<endl;
    return 0;
}