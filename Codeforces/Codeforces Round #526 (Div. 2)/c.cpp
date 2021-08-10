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

int main(){
	
	scanf("%s",a);
	int len=strlen(a);
	int cnt=0;
	for(int i=0;i<len;i++){
		if(a[i]=='a'||a[i]=='b'){
			a[cnt++]=a[i];
		}
	}
	a[cnt]='\0';
	int i=0;
	ll ans=1;
	while(1){
		int c=0;
		while(i<cnt&&a[i]=='a'){
			i++;
			c++;
		}
		ans=(c+1)*ans%mod;
		if(i==cnt)break;
		while(i<cnt&&a[i]=='b'){
			i++;
		}
		if(i==cnt)break;
	}
	ans=(ans+mod-1)%mod;
	printf("%lld\n",ans);
	
	return 0;
}




