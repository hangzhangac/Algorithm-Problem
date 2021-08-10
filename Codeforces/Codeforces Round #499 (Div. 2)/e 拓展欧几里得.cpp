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
int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}
map<ll,bool>ms;
int a[MAXN];
int main(){
	int n,k;
	cin>>n>>k;
	int g=0;
	for(int i=1;i<=n;i++){
		gi(a[i]);
		g=gcd(g,a[i]);
	}
	
	int cnt=0;
	for(ll i=g,j=0;j<=k;j++,i+=g){
		if(!ms[i%k]){
			cnt++;
			ms[i%k]=true;
		}
	}
	cout<<cnt<<endl;
	map<ll,bool>::iterator it=ms.begin();
	while(it!=ms.end()){
		printf("%lld ",it->first);
		it++;
	}
	return 0;
}















