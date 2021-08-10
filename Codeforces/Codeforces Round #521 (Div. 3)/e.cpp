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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
map<int,int>ms;
int book[MAXN];
int main(){
	int n;
	cin>>n;
	int cnt=1;
	for(int i=1;i<=n;i++){
		int x;
		gi(x);
		if(ms[x]==0){
			ms[x]=cnt++;
		}
		book[ms[x]]++;
	}
	cnt--;
	sort(book+1,book+cnt+1);
	ll maxn=0;
	for(int st=1;st<=n;st++){
		ll sum=0;
		int q=st;
		int l=1;
		while(1){
			int t=lower_bound(book+l, book+cnt+1, q)-book;
			if(t==cnt+1)break;
			sum+=q;
			q*=2;
			l=t+1;
			if(l==cnt+1)break;
		}
		maxn=max(maxn,sum);
	}
	printf("%lld\n",maxn);
	return 0;
}





























