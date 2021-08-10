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
const int MAXN=500005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char a[MAXN];
int main(){
	scanf("%s",a+1);
	int n=strlen(a+1);
	int i=1;
	int flag=0;
	while(i<=n&&a[i]!='['){
		i++;
	}
	if(i>n)flag=1;
	int s=i;
	int j=n;
	while(j>i&&a[j]!=']'){
		j--;
	}
	if(j<=i)flag=1;
	int t=j;
	i++;
	j--;
	while(i<j&&a[i]!=':'){
		i++;
	}
	if(i>=j)flag=1;
	while(j>i&&a[j]!=':'){
		j--;
	}
	if(j<=i)flag=1;
	int cnt=0;
	while(i<=j){
		if(a[i]=='|'){
			cnt++;
		}
		i++;
	}
	
	if(flag)printf("-1\n");
	else printf("%d\n",cnt+=4);
	
	
	
	return 0;
}












