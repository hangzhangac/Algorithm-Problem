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
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll a[MAXN];
ll b[MAXN];
int n,m;
int main(){
	
	gi(n);
	for(int i=1;i<=n;i++){
		gll(a[i]);
	}
	gi(m);
	for(int i=1;i<=m;i++){
		gll(b[i]);
	}
	int i=1,j=1;
	ll suma=a[1];
	ll sumb=b[1];
	int cnt=0;
	int flag=0;
	while(1){
		while(suma!=sumb){
			if(suma<sumb){
				i++;
				suma+=a[i];
			}
			else{
				j++;
				sumb+=b[j];
			}
			if(i>n||j>m)break;
		}
		if(suma==sumb){
			cnt++;
		}
		else{
			flag=1;
			break;
		}
		i++;j++;
		suma=a[i];sumb=b[j];
		if(i>n&&j>m){
			break;
		}
		else if(i>n||j>m){
			flag=1;
			break;
		}
	}
	if(flag){
		printf("-1\n");
	}
	else printf("%d\n",cnt);
	
	return 0;
}




