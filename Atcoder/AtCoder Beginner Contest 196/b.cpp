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

using namespace std;
char x[MAXN];
int main() {
	cin>>(x+1);
	int n=strlen(x+1);
	int flag=-1;
	for(int i=n;i>=1;i--){
		if(x[i]=='.'){
			x[i]=0;
			flag=i;
			break;
		}
	}
	if(x[1]==0){
		cout<<0<<endl;
	}
	else
		cout<<(x+1)<<endl;
	
}