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
	
	int x,y,z;
	int a,b,c;
	cin>>x>>y>>z;
	cin>>a>>b>>c;
	int flag=1;
	if(a<x){
		flag=0;
	}
	a-=x;
	b+=a;
	if(b<y){
		flag=0;
	}
	b-=y;
	c+=b;
	if(c<z){
		flag=0;
	}
	if(flag)printf("YES\n");
	else printf("NO\n");
	
	
	return 0;
}









