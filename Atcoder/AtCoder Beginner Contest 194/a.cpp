#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
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
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;



int main(){
	
	int a,b;
	cin>>a>>b;
	a=a+b;
	if(a>=15&&b>=8){
		cout<<1<<endl;
	}
	else if(a>=10&&b>=3){
		cout<<2<<endl;
	}
	else if(a>=3){
		cout<<3<<endl;
	}
	else cout<<4<<endl;
	
	return 0;
}



















