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
int a[MAXN];
int b[MAXN];
int book[3];
map<int,int>ms;
int main(){
	int T;
	gi(T);
	while(T--){
		gi(n);
		mem(book,0);
		ms.clear();
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1,j=n;i<j;i++,j--){
			swap(a[i],a[j]);
		}
		for(int i=-n;i<=n;i++)ms[i]=n+1;
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		int diff;
		for(int i=n;i>=1;i--){
			diff=book[1]-book[2];
			ms[diff]=i;
			book[b[i]]++;
		}
		diff=book[1]-book[2];
		ms[diff]=0;
		
		mem(book,0);
		for(int i=1;i<=n;i++)book[a[i]]++;
		int ans=2*n;
		for(int i=1;i<=n;i++){
			diff=book[2]-book[1];
			if(ms[diff]!=n+1){
				ans=min(ans,i-1+ms[diff]);
			}
			book[a[i]]--;;
		}
		diff=book[2]-book[1];
		if(ms[diff]!=n+1){
			ans=min(ans,n+ms[diff]);
		}
		printf("%d\n",ans);
		
		
		
	}
	return 0;
}














