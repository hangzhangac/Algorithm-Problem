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


int a[MAXN];
map<int,int>ms;
int main(){
	int T;gi(T);while (T--) {
		int n,k;
		ms.clear();
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a[i];
			ms[a[i]]++;
		}
		if(k==0){
			cout<<n<<endl;
			continue;
		}
		sort(a,a+n);
		int x=n;
		for(int i=0;i<n;i++){
			if(a[i]!=i){
				x=i;break;
			}
		}
		int pp=0;
		int maxn=a[n-1];
		if(maxn>=x+2){
			int sum=maxn+x;
			int ans=0;
			ans=sum/2;
			if(sum&1){
				ans++;
			}
			if(ms[ans]==0){
				pp=n+1;
			}
			else pp=n;
		}
		else if(maxn==x+1){
			pp=n;
		}
		else{
			pp=n+k;
		}
		cout<<pp<<endl;
		
	}
	
	return 0;
}















