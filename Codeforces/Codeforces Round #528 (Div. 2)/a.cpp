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
#include <stack>
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
char a[MAXN];
char s[MAXN];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	int t=(n+1)/2;
	int cnt=1;
	a[0]=s[t];
	int i,j;
	for(i=t-1,j=t+1;i>=0&&j<=n;i--,j++){
		a[cnt++]=s[j];
		a[cnt++]=s[i];
	}
	while(i>=0){
		a[cnt++]=s[i];
		i--;
	}
	while(j<=n){
		a[cnt++]=s[j];
		j++;
	}
	a[cnt]='\0';
	cout<<a<<endl;
	
	
	
	return 0;
}












