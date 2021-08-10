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
int book[4*1000000+10];
int a[2005];
int b[2005];
int n,m;
int sum[2005];
int sum1[2005];
int main(){
	
	gi2(n, m);
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	for(int i=1;i<=m;i++){
		gi(b[i]);
	}
	
	int x;
	gi(x);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int t=sum[j]-sum[i-1];
			book[t]=max(book[t],j-i+1);
		}
	}
	int maxn=0;
	for(int t=1;t<=4000000;t++){
		book[t]=max(maxn,book[t]);
		maxn=max(maxn,book[t]);
	}
	for(int i=1;i<=m;i++){
		sum1[i]=sum1[i-1]+b[i];
	}
	int maxx=0;
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			int len=(j-i+1);
			int t=sum1[j]-sum1[i-1];
			int q=x/t;
			if(q>=4000000){
				q=4000000;
			}
			int s=book[q];
			maxx=max(maxx,s*len);
		}
	}
	printf("%d\n",maxx);
	
	
	
	
	return 0;
	
	
	
	
	
}












