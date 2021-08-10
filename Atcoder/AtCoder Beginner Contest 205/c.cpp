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

int main() {
	
	
	
	int a,b,c;
	cin>>a>>b>>c;
	int flag=0;
	if(c&1){
		if(a<b){
			flag=1;
		}
		else if(a==b){
			flag=2;
		}
		else{
			flag=3;
		}
	}
	else{
		if(abs(a)<abs(b)){
			flag=1;
		}
		else if(abs(a)==abs(b)){
			flag=2;
		}
		else flag=3;
	}
	if(flag==1)cout<<"<"<<endl;
	else if(flag==2)cout<<"="<<endl;
	else{
		cout<<">"<<endl;
	}
	
	
	return 0;
}





















