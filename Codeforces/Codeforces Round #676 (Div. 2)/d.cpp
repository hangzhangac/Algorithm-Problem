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
int a[8];
int c[8];
int main(){
	int T;gi(T);
	while(T--){
		ll x,y;
		cin>>x>>y;
		for(int i=1;i<=6;i++){
			cin>>a[i];
		}
		a[0]=a[6];
		a[7]=a[1];
		for(int i=1;i<=6;i++){
			c[i]=min(a[i],a[i-1]+a[i+1]);
		}
		ll ans=0;
		if(x>=0&&y>=0){
			int t=min(x,y);
			ans+=1LL*t*c[1];
			if(x>y){
				ans+=(x-t)*c[6];
			}
			else{
				ans+=(y-t)*c[2];
			}
		}
		else if(x>=0&&y<0){
			ans+=x*c[6];
			ans+=-y*c[5];
		}
		else if(x<0&&y<0){
			x=-x;y=-y;
			int t=min(x,y);
			ans+=1LL*t*c[4];
			if(x>y){
				ans+=(x-t)*c[3];
			}
			else{
				ans+=(y-t)*c[5];
			}
		}
		else if(x<0&&y>=0){
			ans-=x*c[3];
			ans+=y*c[2];
		}
		cout<<ans<<endl;
	}
	return 0;
}










