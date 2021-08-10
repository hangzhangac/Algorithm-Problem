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
int a[MAXN];
int b[MAXN];
int main(){
	
	
	int n;
	gi(n);
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	sort(a+1,a+n+1);
	b[1]=a[n];
	int i=2;
	int j=n;
	int t=n-1;
	while(t>=1){
		b[i]=a[t];
		i++;
		t--;
		if(t==0)break;
		b[j]=a[t];
		t--;
		j--;
	}
	int flag=0;
	for(int i=1;i<=n;i++){
		int pre=i-1;
		int nx=i+1;
		if(pre==0)pre=n;
		if(nx==n+1)nx=1;
		if(b[i]<b[pre]+b[nx]){
			
		}
		else{
			flag=1;
			break;
		}
	}
	if(flag){
		printf("NO\n");
	}
	else {printf("YES\n");
		for(int i=1;i<=n;i++){
			printf("%d ",b[i]);
		}
	}
	
	
	
	
	return 0;
}








