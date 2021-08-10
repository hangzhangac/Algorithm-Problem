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
int n;
int a[MAXN];
map<int,int>ms;
int main(){
	
	gi(n);
	ll res=0;
	for(int i=1;i<=n;i++){
		gi(a[i]);
		res+=(a[i]&1);
	}
	sort(a+1,a+n+1);
	int f=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			f++;
		}
	}
	if(f>=2||(f==1&&n==1)){
		printf("cslnb\n");
		return 0;
	}
	int flag=0;
	int cnt2=0;
	int id=-1;
	for(int i=1;i<=n;i++){
		int t=++ms[a[i]];
		if(t>=3){
			printf("cslnb\n");
			return 0;
		}
		if(t==2){
			cnt2++;
			id=a[i];
		}
	}
	if(cnt2>=2){
		printf("cslnb\n");
		return 0;
	}
	else if(cnt2==1){
		if(ms[id-1]==1){
			printf("cslnb\n");
			return 0;
		}
		else{
			flag=0;
			for(int i=1;i<=n;i++){
				if(a[i]==id){
					a[i]--;
					break;
				}
			}
		}
	}
	else if(cnt2==0){
		flag=0;
	}
	res=(res+1ll*n*(n-1)/2&1) & 1;
	if (!res) printf("cslnb\n");
	else printf("sjfnb\n");
	
	
	return 0;
}