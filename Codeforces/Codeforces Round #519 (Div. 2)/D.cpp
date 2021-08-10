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
int n,m;
int a[15][MAXN];
int pre[15][MAXN];
int cnt[MAXN];
int main(){
	
	gi2(n, m);
	//ll sum=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			gi(a[i][j]);
			pre[i][a[i][j]]=a[i][j-1];
		}
	}
	ll sum=n;
	for(int i=2;i<=n;i++){
		int flag=1;
		for(int j=1;j<=m-1;j++){
			if(pre[j][a[m][i]]==a[m][i-1]){
				
			}
			else{
				flag=0;
				break;
			}
		}
		if(flag){
			cnt[i]=cnt[i-1]+1;
			sum+=cnt[i];
		}
	}
	printf("%lld\n",sum);
	return 0;
}














