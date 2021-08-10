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
const int MAXN=400005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
char s[MAXN];
int flag=0;
int n;
int cal(int q){
	if(flag){
		if(q>n){
			q-=n;
		}
		else{
			q+=n;
		}
		return q;
	}
	else return q;
}
int main() {
	
	cin>>n;
	scanf("%s",s+1);
	int q;cin>>q;
	
	while(q--){
		int t,a,b;
		gi2(t, a);
		gi(b);
		if(t==2){
			flag^=1;
		}
		else{
			a=cal(a);
			b=cal(b);
			swap(s[a], s[b]);
		}
	}
	if(!flag){
		cout<<(s+1)<<endl;
	}
	else{
		cout<<(s+n+1);
		s[n+1]='\0';
		cout<<(s+1)<<endl;
	}
	
	
	
	
	
	
	
	return 0;
}



















