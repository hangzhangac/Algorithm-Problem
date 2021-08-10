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
const int MAXN=1000005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char a[MAXN];
char b[MAXN];
int main(){
	int t;gi(t);
	while(t--){
		scanf("%s",a);int n=strlen(a);
		scanf("%s",b);int m=strlen(b);
		int i=0,j=0;
		int flag=1;
		while(i<n){
			int cnt=1;
			int cntb=0;
			char s=a[i];
			i++;
			while(i<n&&a[i]==s){
				cnt++;
				i++;
			}
			while(j<m&&b[j]==s){
				j++;
				cntb++;
			}
			if(cntb>=cnt){
				continue;
			}
			else{
				flag=0;
				break;
			}
			
		}
		if(i==n&&j!=m){
			flag=0;
		}
		if(flag){
			printf("YES\n");
		}
		else printf("NO\n");
	}
	
	
}