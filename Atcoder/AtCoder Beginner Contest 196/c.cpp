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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
ll string_to_int(string s){//string类型转int
	ll cur=0;
	for(int i=0;i<s.size();i++){
		cur*=10;
		cur+=s[i]-'0';
	}
	return cur;
}
int main(){
	string s;
	cin>>s;
	
	ll n=string_to_int(s);
	for(int i=0;i<s.size();i++){
		s[i]-='0';
	}
	ll cnt=0;
	for(int i=2;i<s.size();i+=2){
		int tmp=i;
		tmp/=2;tmp--;
		ll ans=9;
		while(tmp--){
			ans=ans*10;
		}
		cnt+=ans;
	}
	if(s.size()&1){
		
	}
	else{
		int t=s.size()/2-1;
		for(int i=0;i<=t;i++){
			ll ans=0;
			if(i==0){
				ans=s[i]-1;
				//cout<<ans<<"fea"<<endl;
				for(int j=i+1;j<=t;j++){
					ans*=10;
				}
			}
			else{
				ans=s[i];
				for(int j=i+1;j<=t;j++){
					ans*=10;
				}
			}
			cnt+=ans;
		}
		int flag=0;
		int i=0,j=t+1;
		while(i<=t&&s[i]==s[j]){
			i++;
			j++;
		}
		if(i==t+1){
			flag=1;
		}
		else{
			if(s[i]<s[j]){
				flag=1;
			}
			else{
				flag=0;
			}
		}
		if(flag){
			cnt++;
		}
		
	}
	cout<<cnt<<endl;
	return 0;
}