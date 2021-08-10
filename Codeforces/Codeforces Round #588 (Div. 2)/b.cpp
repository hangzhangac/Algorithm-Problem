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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char a[MAXN];
int main(){
	
	int n,k;
	cin>>n>>k;
	getchar();
	for(int i=1;i<=n;i++){
		scanf("%c",a+i);
	}
	if(n==1&&k==1){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(k==0)break;
		if(i==1){
			if(a[i]!='1'){
				a[i]='1';
				k--;
			}
		}
		else{
			if(a[i]!='0'){
				a[i]='0';
				k--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		printf("%c",a[i]);
	}
	
	
	return 0;
}












