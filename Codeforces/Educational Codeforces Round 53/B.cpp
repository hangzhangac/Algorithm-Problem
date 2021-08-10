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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN];
int book[MAXN];
int main(){
	int n;
	gi(n);
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	int j=1;
	for(int i=1;i<=n;i++){
		int x;gi(x);
		int cnt=0;
		if(book[x]==1){
			
		}
		else{
			while(a[j]!=x){
				book[a[j]]=1;
				j++;
				cnt++;
			}
			book[a[j]]=1;
			cnt++;
			j++;
		}
		printf("%d ",cnt);
	}
	
	
	return 0;
}










