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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll cal(int a,int b){
	int cnt=0;
	int b1=b;
	while(b1){
		cnt+=1;
		b1/=10;
		a*=10;
	}
	a+=b;
	return a;
}
int main(){
	
	int T;
	gi(T);
	while(T--){
		ll A,B;
		cin>>A>>B;
//		for(int i=1;i<=A;i++){
//			for(int j=1;j<=B;j++){
//				if(i*j+i+j==cal(i,j)){
//					printf("%d %d\n",i,j);
//				}
//			}
//		}
//		
		ll cnt=0;
		ll t=0;
		while(t*10+9<=B){
			cnt+=1;
			t*=10;
			t+=9;
		}
		printf("%lld\n",A*cnt);
	}
	
	
}














