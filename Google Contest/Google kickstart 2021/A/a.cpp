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
char x[MAXN];
int n,k;
int main() {
	int cnt=1;
	int T;gi(T);while(T--){
		cin>>n>>k;
		cin>>(x+1);
		int c=0;
		for(int i=1,j=n;i<j;i++,j--){
			if(x[i]!=x[j]){
				c++;
			}
		}
		printf("Case #%d: ",cnt++);
		cout<<(abs(c-k))<<endl;
	}
	
	
	
	return 0;
}
















