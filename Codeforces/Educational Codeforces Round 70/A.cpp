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
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;

char s[MAXN];
char t[MAXN];
int main(){
	
	int T;gi(T);
	while(T--){
		scanf("%s",s);
		scanf("%s",t);
		
		int n=strlen(t);
		int m=strlen(s);
		for(int i=0,j=n-1;i<j;i++,j--){
			swap(t[i],t[j]);
		}
		for(int i=0,j=m-1;i<j;i++,j--){
			swap(s[i],s[j]);
		}
		int flag=-1;
		for(int i=0;i<n;i++){
			if(t[i]=='1'){
				flag=i;
				break;
			}
		}
		if(flag==-1){
			printf("0\n");
			continue;
		}
		for(int j=min(m,flag);j<m;j++){
			if(s[j]=='1'){
				printf("%d\n",j-flag);
				flag=inf;
				break;
			}
		}
		if(flag!=inf)
			printf("0\n");
	}
	
	
	
	
	return 0;
}