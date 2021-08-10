#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <time.h>
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
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int main(){
	
	
	ll n,m;
	cin>>n>>m;
	if(m%n!=0){
		printf("-1\n");
		return 0;
	}
	m/=n;
	int cnt=0;
	while(m%2==0){
		m/=2;
		cnt++;
	}
	while(m%3==0){
		m/=3;
		cnt++;
	}
	if(m==1){
		printf("%d\n",cnt);
	}
	else printf("-1\n");
	
	
	return 0;
}














