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
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;

int main(){
	int T;gi(T);while(T--){
		ll n,m,k;
		gll2(n,m);gll(k);
		n=abs(n),m=abs(m);
		if(n>m)swap(n,m);
		k-=n;
		int flag=0;
		ll sum=n;
		if(k<0){
			flag=1;
		}
		ll t=(m-n);
		if(t&1){
			sum+=t-1;
			k-=(t-1);
			if(k<=0){
				flag=1;
			}
			if(k&1){
				sum+=k-1;
			}
			else{
				sum+=k-1;
			}
		}
		else{
			k-=(m-n);
			sum+=(m-n);
			if(k<0){
				flag=1;
			}
			else{
				if(k&1){
					sum--;
					k--;
					sum+=k;
				}
				else{
					sum+=k;
				}
			}
		}
		if(flag){
			printf("-1\n");
		}
		else printf("%lld\n",sum);
		
		
	}
}























