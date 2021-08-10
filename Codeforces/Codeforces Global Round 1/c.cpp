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
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int a[8]={
	0,0,3,1,7,7,7,1
};
int b[]={0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int main(){
	
	int q;
	gi(q);
	while(q--){
		int n;
		gi(n);
		if(n<=7){
			printf("%d\n",a[n]);
			continue;
		}
		int flag=0;
		for(int i=4;i<=25;i++){
			int s=(1<<i)-1;
			if(n==s){
				printf("%d\n",b[i]);
				flag=1;
				break;
			}
		}
		if(flag)continue;
		for(int i=3;i<=25;i++){
			int l=1<<i;
			int r=(1<<(i+1))-2;
			if(n>=l&&n<=r){
				printf("%d\n",(1<<(i+1))-1);
				break;
			}
		}
		
	}
	
	
	
	
	return 0;
}












