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

bool check(ll u){
	for(int i=2;i*i<=u;i++){
		if(u%i==0)return false;
	}
	return true;
}
vector<ll>ans;
int main(){
	
	int T,cnt1=1;
	gi(T);while(T--){
		ans.clear();
		ll z;
		cin>>z;
		ll t=ceil(sqrt(z));
		if(t%2==0)t--;
		ll tmp=t;
		t+=2;
		while(1){
			if(check(t)){
				ans.push_back(t);
				break;
			}
			t+=2;
		}
		t=tmp;
		while(1){
			if(t<=1)break;
			if(check(t)){
				ans.push_back(t);
				int q=ans.size()-1;
				if(ans[q]<=z/ans[q-1]){
					tmp=ans[q]*ans[q-1];
					break;
				}
			}
			if(t==3)t--;
			else t-=2;
		}
		printf("Case #%d: ",cnt1++);
		cout<<tmp<<endl;
	}
	
	
	return 0;
}

























