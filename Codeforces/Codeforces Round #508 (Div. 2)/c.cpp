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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN];
int b[MAXN];
int main(){
	int n;
	cin>>n;
	ll suma=0;
	ll sumb=0;
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	for(int i=1;i<=n;i++){
		gi(b[i]);
	}
	sort(a+1,a+n+1,greater<int>());
	sort(b+1,b+n+1,greater<int>());
	int flag=0;
	int j=1,i=1;
	while(i<=n&&j<=n){
		if(!flag){
			if(b[j]>=a[i]){
				j++;
			}
			else{
				suma+=a[i];
				i++;
			}
			flag^=1;
		}
		else{
			if(a[i]>=b[j]){
				i++;
			}
			else{
				sumb+=b[j];
				j++;
			}
			flag^=1;
		}
	}
	while(i<=n){
		if(!flag){
			suma+=a[i];
			flag^=1;
		}
		else{
			flag^=1;
		}
		i++;
	}
	while(j<=n){
		if(!flag){
			flag^=1;	
		}
		else{
			sumb+=b[j];
			flag^=1;
		}
		j++;
	}
	printf("%lld\n",suma-sumb);
	return 0;
}





