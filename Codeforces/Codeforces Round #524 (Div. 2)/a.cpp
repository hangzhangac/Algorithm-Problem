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
int main(){
	
	int n,k;
	cin>>n>>k;
	ll red=n*2;
	ll gr=n*5;
	ll bl=n*8;
	ll cnt=ceil(1.0*red/k);
	cnt+=ceil(1.0*gr/k);
	cnt+=ceil(1.0*bl/k);
	printf("%lld\n",cnt);
	
	
	return 0;
}































