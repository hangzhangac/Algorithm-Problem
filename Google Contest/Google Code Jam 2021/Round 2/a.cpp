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
const int MAXN=1000005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
int a[105];
int main(){
	
	int T,cnt1=1;cin>>T;
	int n;
	cin>>n;
	while(T--){
		int l=1,r=n;
		while(l<n){
			cout<<'M'<<' '<<l<<' '<<r<<endl;
			int t;
			cin>>t;
			if(l!=t){
				cout<<"S "<<l<<' '<<t<<endl;
				int x;cin>>x;
			}
			l++;
		}
		cout<<'D'<<endl;
		int x;
		cin>>x;
	}
	
	
	
	return 0;
}






















