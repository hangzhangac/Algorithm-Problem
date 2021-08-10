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
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=5005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;

int a[MAXN];
ll solve(int l,int r){
	if(r<l)return 0;
	if(l==r){
		if(a[l]==0)return 0;
		else return 1;
	}
	ll num=1e9+1;
	int x=-1;
	for(int i=l;i<=r;i++){
		if(a[i]<=num){
			num=a[i];
			x=i;
		}
	}
	for(int i=l;i<=r;i++){
		a[i]-=num;
	}
	return min(1ll*r-l+1,num+solve(l,x-1)+solve(x+1, r));
}

int main(){
	
	int n;
	gi(n);
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	cout<<solve(1,n)<<endl;
	
	return 0;
}





