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
	
	int n;
	cin>>n;
	if(n==1||n==2){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	
	int t;
	if(n%2==0){
		t=n/2;
	}
	else{
		t=(n+1)/2;
	}
	printf("1 %d\n",t);
	printf("%d",n-1);
	//printf("%d",t);
	for(int i=1;i<=n;i++){
		if(i==t){
			continue;
		}
		printf(" %d",i);
	}
	
	return 0;
}