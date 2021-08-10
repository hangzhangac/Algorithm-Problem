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
ull n;
int cal_bits(ull x){
    int ret=0;
    while(x>0)ret++,x/=10;
    return ret;
}
ull str2ull(string s){
    int n=s.length();
    ull ret=0;
    for(int i=0;i<n;i++)ret=ret*10+(s[i]-'0');
    return ret;
}
string ull2str(ull x){
    string ret="";
    while(x>0){
        ret+=(x%10)+'0';
        x/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
ull min_k_bits(int k){
    if(k==1)return 12;
    string ans="";
    if(k&1){
        ull i=1,bits=0;
        while(bits<k){
            string tmp=ull2str(i);
            ans+=tmp;
            bits+=tmp.length();
            i++;
        }
    }
    else{
        ull x=1;
        for(int i=1;i<k/2;i++)x*=10;
        ans=ull2str(x)+ull2str(x+1);
    }
    return str2ull(ans);
}
ull min_k_pre(ull n,int k,int len){
    ull ans=4e18;
    string snum=ull2str(n);
    string prek="";for(int i=0;i<k;i++)prek+=snum[i];
    ull nprek=str2ull(prek);
    for(ull x=nprek;x<=nprek+1;x++){
        ull i=x,bits=0;
        string ret="";
        while(bits<len){
            string tmp=ull2str(i);
            ret+=tmp;
            bits+=tmp.length();
            i++;
        }
        if(bits>len)continue;
        ull y=str2ull(ret);
        if(y>n)ans=min(ans,y);
    }
    string maxk="";for(int i=0;i<k;i++)maxk+='9';
    ull nmaxk=str2ull(maxk);
    for(ull x=nmaxk,j=0;nmaxk>=1&&j<10;j++,x--){
        ull i=x,bits=0;
        string ret="";
        while(bits<len){
            string tmp=ull2str(i);
            ret+=tmp;
            bits+=tmp.length();
            i++;
        }
        if(bits>len)continue;
        ull y=str2ull(ret);
        if(y>n)ans=min(ans,y);
    }
    return ans;
}
int main(){
    int T,cnt1=1;gi(T);while(T--){
        cin>>n;
        ull ans=min_k_bits(cal_bits(n-1)+1);
        int len=cal_bits(n);
        for(int i=1;i<=len/2;i++)ans=min(ans,min_k_pre(n,i,len));
        printf("Case #%d: %llu\n",cnt1++,ans);
    }
    return 0;
}