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
ll x[MAXN];
int n;
ll cur=1;
bool C(ll a){
	ll t=sqrt(a)+eps;
	if(t*t==a)return true;
	return false;
}
int main(){
	int n;gi(n);
	mem(x,-1);
	for(int i=2;i<=n;i+=2){
		gll(x[i]);
	}
	ll sum=0;
	int flag=0;
	for(int i=2;i<=n;i+=2){
		while(1){
			ll t=cur*cur;
			if(t-sum>10000000000000){
				x[n-1]=-1;
				flag=1;
				break;
			}
			if(t>sum&&C(t+x[i])){
				x[i-1]=t-sum;
				sum=t+x[i];
				cur++;
				break;
			}
			cur++;
		}
		if(flag)break;
	}
	if(x[n-1]==-1||flag){
		printf("No\n");
	}
	else{
		printf("Yes\n");
		for(int i=1;i<=n;i++){
			printf("%lld ",x[i]);
		}
	}
	return 0;
}
































