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
int n;
int book[11];
char a[MAXN];
int main(){
	
	gi(n);scanf("%s",a);
	int len=strlen(a);
	for(int i=0;i<n;i++){
		if(a[i]=='L'){
			for(int i=0;i<10;i++){
				if(book[i]==0){
					book[i]=1;break;
				}
			}
		}
		else if(a[i]=='R'){
			for(int i=9;i>=0;i--){
				if(book[i]==0){
					book[i]=1;
					break;
				}
			}
		}
		else{
			int t=a[i]-'0';
			book[t]=0;
		}
	}
	for(int i=0;i<10;i++){
		cout<<book[i];
	}
	
	
	return 0;
}