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
const int MAXN=1005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int bit[MAXN][55];
int num[55][2];
ll a[MAXN],b[MAXN];
ll pp[MAXN];
int kk[55];
int main(){
	
	int T;gi(T);
	int n;ll m;
	int cnt1=1;
	ll q=1;
	for(int i=0;i<=50;i++){
		pp[i]=q;
		q*=2;
	}
	while(T--){
		mem(num,0);
		mem(kk,0);
		gi(n);gll(m);
		printf("Case #%d: ",cnt1++);
		for(int i=1;i<=n;i++){
			gll(a[i]);
			b[i]=a[i];
			int cnt=0;
			while(cnt<=50){//0-50包含
				bit[i][cnt]=a[i]&1;
				num[cnt++][a[i]&1]++;
				a[i]>>=1;
			}
		}
		for(int i=0;i<=50;i++){
			if(num[i][1]>=num[i][0]){
				kk[i]=1;
			}else{
				kk[i]=0;
			}
		}
		ll k=0;
		for(int i=50;i>=0;i--){
			k*=2;
			k+=kk[i];
		}
		
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans+=k^b[i];
		}
		
		if(ans>m){
			printf("-1\n");
			continue;
		}
		
		for(int i=50;i>=0;i--){
			if(kk[i]==0){
				ll ans1=ans;
				ans1+=(num[i][0]-num[i][1])*pp[i];
				if(ans1<=m){
					kk[i]=1;
					ans=ans1;
					//cout<<ans1<<' '<<i<<endl;
				}
			}
		}
		k=0;
		for(int i=50;i>=0;i--){
			k*=2;
			k+=kk[i];
		}
		printf("%lld\n",k);
	}
	
	
	return 0;
}