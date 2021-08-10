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
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=998244353;
const int inf=0x3f3f3f3f;
int a[MAXN];
int main(){
	
	int n,m;
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	int ans2=maxn+m;
	while(m--){
		int pos=-1,minn=inf;
		for(int i=1;i<=n;i++){
			if(minn>a[i]){
				minn=a[i];
				pos=i;
			}
		
		}
		a[pos]++;
	}
	maxn=0;
	for(int i=1;i<=n;i++){
			cin>>a[i];
			maxn=max(maxn,a[i]);
		}
	printf("%d %d\n",maxn,ans2);
	
	return 0;
}
































