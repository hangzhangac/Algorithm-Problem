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
map<ll,int>ms;
vector<ll>inz;
vector<int>num;
ll nn[MAXN];
void cal1(long long a){
	while(a>1){
		for(int i=2;i<=a;i++){
			if(a%i==0){
				a = a/i;
				ms[i]++;
				break;
			}
		}
	}
}
void cal(long long n){
	for(ll i=2;i*i<=n;i++){
		while(n%i==0){
			++ms[i];
			n/=i;
		}
	}
	if(n!=1) ms[n]=1;
}
int main(){
	
	long long n,a;
	cin>>n>>a;
	cal(a);
	map<ll,int>::iterator it=ms.begin();
	while(it!=ms.end()){
		inz.push_back(it->first);
		num.push_back(it->second);
		it++;
	}
	for(int i=0;i<inz.size();i++){
		long double now=inz[i];
		while(now<=(long double)n){
			nn[i]+=n/now;
			if(now*inz[i]<=(long double)n+1){
				now*=inz[i];
			}
			else break;
		}
	}
	ll minn=8000000000000000000;
	for(int i=0;i<inz.size();i++){
		minn=min(minn,nn[i]/num[i]);
	}
	printf("%lld\n",minn);
	return 0;
}









