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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN];
int sum[2][MAXN];
int main(){
	
	int n;
	gi(n);
	//int sum[2];
	//sum[0]=sum[1]=0;
	for(int i=1;i<=n;i++){
		gi(a[i]);
		if(i&1){
			sum[1][i]=sum[1][i-1]+a[i];
			sum[0][i]=sum[0][i-1];
		}
		else {
			sum[1][i]=sum[1][i-1];
			sum[0][i]=sum[0][i-1]+a[i];
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		ll num1=0,num2=0;
		if(i&1){
			num1+=sum[1][i-1];
			num2+=sum[0][i-1];	
			num1+=sum[0][n]-sum[0][i];
			num2+=sum[1][n]-sum[1][i];
		}
		else{
			num1+=sum[0][i-1];
			num2+=sum[1][i-1];	
			num1+=sum[1][n]-sum[1][i];
			num2+=sum[0][n]-sum[0][i];
		}
//		if(i==2){
//			cout<<num1<<' '<<num2<<endl;
//		}
		if(num1==num2){
			cnt++;
		//	cout<<i<<endl;
		}
		
	}
	printf("%d\n",cnt);
	
	
	
	return 0;
}








