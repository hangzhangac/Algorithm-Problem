#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;

int n;
int p[MAXN];
int maxn[MAXN];
int id[MAXN];
int ans[MAXN];
int main() {
	
	int T;cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i];
			if(p[i]>maxn[i-1]){
				maxn[i]=p[i];
				id[i]=i;
			}
			else{
				maxn[i]=maxn[i-1];
				id[i]=id[i-1];
			}
		}
		int cnt=n-1;
		for(int i=n;i>=1;){
			int t=id[i];//idx
		//	cout<<t<<endl;
			for(int j=t;j<=i;j++){
				ans[cnt]=p[j];
				cnt--;
			}
			i=t-1;
		}
		for(int i=n-1;i>=0;i--){
			cout<<ans[i]<<' ';
		}
		cout<<endl;
	}
	
	
	return 0;
}















