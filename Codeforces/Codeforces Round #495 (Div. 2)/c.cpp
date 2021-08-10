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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int book[MAXN];
int vis[MAXN];
int a[MAXN];
int main(){
	
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		gi(a[i]);
		if(book[a[i]]==0){
			cnt++;
		}
		book[a[i]]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		book[a[i]]--;
		if(book[a[i]]==0)cnt--;
		if(vis[a[i]])continue;
		vis[a[i]]=1;
		//book[a[i]]--;
		ans+=cnt;
	}
	printf("%lld\n",ans);
	
	
	return 0;
}




