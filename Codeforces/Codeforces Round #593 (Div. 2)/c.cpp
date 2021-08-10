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
const int MAXN=305;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN][MAXN];
int main(){
	
	int n;
	gi(n);
	int j=-1;
	for(int i=0;i<n*n;i++){
		if(i%n==0){
			j++;
		}
		a[i%n][j]=i+1;
	}
	for(int j=1;j<n;j+=2){
		for(int i=0,k=n-1;i<k;i++,k--){
			swap(a[i][j],a[k][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		
		
		putchar('\n');
	}
	
	
	
	return 0;
}











