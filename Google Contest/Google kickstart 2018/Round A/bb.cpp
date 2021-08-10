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
const int MAXN=5100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n;
char a[MAXN];
int sum[MAXN];

int main(){
	freopen("B-large.in","r",stdin); //输入重定向，输入数据将从D盘根目录下的in.txt文件中读取 
	freopen("ans.out","w",stdout);
	int cnt=1;
	int T;cin>>T;while(T--){
		int n;
		gi(n);
		scanf("%s",a+1);
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i]-'0';
		}
		int maxn=0;
		//ll sum=0;
		int len=(n+1)/2;
		for(int i=1;i<=n;i++){
			int t=i+len-1;
			t=min(n,t);
			maxn=max(maxn,sum[t]-sum[i-1]);
		}
		printf("Case #%d: ",cnt++);
		printf("%d\n",maxn);
	}
	
	
	return 0;
}




























