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
int book[MAXN];
char s[MAXN];
int main(){
	
	int T,cnt1=1;
	gi(T);while(T--){
		
		int n;
		cin>>n;
		cin>>(s+1);
		for(int i=1;i<=n;i++){
			book[i]=0;
		}
		book[1]=1;
		for(int i=2;i<=n;i++){
			if(s[i]>s[i-1]){
				book[i]=book[i-1]+1;
			}
			else book[i]=1;
			
		}
		printf("Case #%d:",cnt1++);
		for(int i=1;i<=n;i++){
			cout<<" "<<book[i];
		}
		
		
		cout<<endl;
	}
	
	
	return 0;
}

























