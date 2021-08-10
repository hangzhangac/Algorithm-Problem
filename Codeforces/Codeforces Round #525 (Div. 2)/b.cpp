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
#include <stack>
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
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN];
int main(){
	
	
	int n,k;
	gi2(n,k);
	for(int i=0;i<n;i++){
		gi(a[i]);
	}
	sort(a,a+n);
	n=unique(a, a+n)-a;
	int cnt=0;
	ll cur=0;
	for(int i=0;i<n;i++){
		printf("%lld\n",a[i]-cur);
		cur+=a[i]-cur;
		cnt++;
		if(cnt==k)break;
	}
	while(cnt<k){
		cnt++;
		printf("%d\n",0);
	}
	
	
	
	return 0;
}































