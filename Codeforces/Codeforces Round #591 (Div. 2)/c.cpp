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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;

int nn;
int aa[MAXN];
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
ll lcm(int a,int b){
	return 1LL*a*b/gcd(a,b);
}
bool cmp(int a,int b){
	return a>b;
}
bool C(int n,int x,int a,int y,int b,ll k){
	ll cnt=0;
	ll s=lcm(a,b);
	int num=n/s;
	int st=1;
	int ans=-1;
	for(int i=st;i<=st+num-1;i++){
		cnt+=aa[i]/100*(x+y);
		if(cnt>=k){
			return true;
		}
	}
	st=num+1;
	if(x<y){
		swap(a,b);
		swap(x,y);
	}
	int num1=n/a-num;
	for(int i=st;i<=st+num1-1;i++){
		cnt+=aa[i]/100*(x);
		if(cnt>=k){
			return true;
		}
	}
	st=num+num1+1;
	swap(a,b);
	swap(x,y);
	num1=n/a-num;
	for(int i=st;i<=st+num1-1;i++){
		cnt+=aa[i]/100*(x);
		if(cnt>=k){
			return true;
		}
	}
	return false;
}
int main(){
	
	int q;gi(q);
	while(q--){
		gi(nn);
		for(int i=1;i<=nn;i++)gi(aa[i]);
		sort(aa+1,aa+nn+1,greater<int>());
		int x,a,y,b;
		gi2(x,a);
		gi2(y,b);
		ll k;gll(k);
		int l=1,r=nn;
		int ans=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(C(mid,x,a,y,b,k)){
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}