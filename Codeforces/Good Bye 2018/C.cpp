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
const int MAXN=100000;
typedef  long long  ll;
vector<int>ans;
vector<ll>a;
int main(){
	int n;
	cin>>n;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			if(i==n/i){
				ans.push_back(i);
			}
			else{
				ans.push_back(i);
				ans.push_back(n/i);
			}
		}
	}
	for(int i=0;i<ans.size();i++){
		ll d=ans[i];
		ll j=(n-1)/d+1;
		ll las=1+1LL*(j-1)*d;
		ll qq=(1+las)*j/2;
		a.push_back(qq);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++){
		printf("%lld ",a[i]);
	}
	
	
	return 0;
	
}