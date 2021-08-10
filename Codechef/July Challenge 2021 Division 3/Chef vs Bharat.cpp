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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
vector<ll>a;
long long quick_pow(long long a, long long b, long long mod) {
	a %= mod;
	long long res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
ll sum[MAXN];
string int_to_string(int a){//int类型转string
	if(a==0)return "0";
	stack<char>s;
	string cur="";
	while(a){
		char t=a%10+'0';
		s.push(t);
		a/=10;
	}
	while(!s.empty()){
		cur+=s.top();
		s.pop();
	}
	return cur;
}
ll string_to_int(string s){//string类型转int
	ll cur=0;
	for(int i=0;i<s.size();i++){
		cur*=10;
		cur+=s[i]-'0';
	}
	return cur;
}
ll change(int a){
	string s=int_to_string(a/10);
	string t=int_to_string(a%10);
	string x=s;
	reverse(x.begin(),x.end());
	return string_to_int(s+t+x);
	
}
int main() {
	
	for(int i=1;i<=9;i++)a.push_back(i);
	
	for(int i=10;i<=99999;i++){
		a.push_back(change(i));
	}
	a.push_back(10000000001);
	sum[0]=a[0];
	for(int i=1;i<a.size();i++){
		sum[i]=(sum[i-1]+a[i])%(mod-1);
	}
	int q;gi(q);
	while(q--){
		int l,r;
		gi2(l, r);
		l--;r--;
		ll t=a[l]%mod;
		ll b=((sum[r]-sum[l])%(mod-1)+mod-1)%(mod-1);
		//cout<<b<<endl;
		cout<<quick_pow(t, b, mod)<<endl;
	}
	
	
	
	return 0;
}











