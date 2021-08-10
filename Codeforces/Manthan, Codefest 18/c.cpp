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
const int MAXN=1000005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char a[MAXN];
char b[MAXN];
int main(){
	int n;gi(n);
	scanf("%s",a);
	scanf("%s",b);
	int ans=0;
	int i;
	for(i=0;i<n;i++){
		int j=i+1;
		if(j!=n){
			if(a[i]!=b[i]){
				if(a[j]!=b[j]&&a[i]!=a[i+1]){
					ans++;
					i++;
				}
				else{
					ans++;
				}
			}
		}
		else{
			if(a[i]!=b[i]){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}