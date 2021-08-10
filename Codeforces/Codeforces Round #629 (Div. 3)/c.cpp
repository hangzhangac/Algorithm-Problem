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
char a[MAXN];
char b[MAXN];
int main(){
	
	int T;
	gi(T);
	while(T--){
		int n;
		gi(n);
		cin>>(s+1);
		for(int i=1;i<=n;i++){
			s[i]=s[i]-'0';
		}
		int flag=0;
		for(int i=2;i<=n;i++){
			if(s[i]==0){
				a[i]=b[i]=0;
			}
			else if(s[i]==1){
				if(!flag){
					a[i]=1;b[i]=0;
					flag=1;
				}
				else{
					a[i]=0;
					b[i]=1;
				}
			}
			else{
				if(flag){
					a[i]=0;
					b[i]=2;
				}
				else{
					a[i]=b[i]=1;
				}
			}
		}
		a[1]=b[1]=1;
		a[n+1]='\0';
		b[n+1]='\0';
		for(int i=1;i<=n;i++){
			a[i]=a[i]+'0';
			b[i]=b[i]+'0';
		}
		
		cout<<a+1<<endl;
		cout<<b+1<<endl;
		
		
	}
	
	return 0;
}

