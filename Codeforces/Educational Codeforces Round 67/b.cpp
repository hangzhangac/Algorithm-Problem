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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char a[MAXN];
char b[MAXN];
int sum[27][MAXN];
int book[27];
int main(){
	
	int n;
	gi(n);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++){
		int t=a[i]-'a';
		for(int j=0;j<26;j++){
			sum[j][i]=sum[j][i-1];
		}
		sum[t][i]++;
	}
	int m;
	gi(m);
	for(int i=1;i<=m;i++){
		scanf("%s",b+1);
		int len=strlen(b+1);
		mem(book,0);
		for(int j=1;j<=len;j++){
			book[b[j]-'a']++;
		}
		int l=1,r=n;
		int ans=-1;
		while(l<=r){
			int mid=(l+r)/2;
			int flag=true;
			for(int j=0;j<26;j++){
				if(sum[j][mid]>=book[j])continue;
				else{
					flag=false;break;
				}
			}
			if(flag){
				r=mid-1;
				ans=mid;
			}
			else{
				l=mid+1;
			}
		}
		printf("%d\n",ans);
	}
	
	
	return 0;
}
