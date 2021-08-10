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
const int MAXN = 2e5 + 5;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n, p, k;
int a[MAXN];
int sum[MAXN];
int main() {
	int t; gi(t);while (t--) {
		gi3(n, p, k);
		for (int i = 1; i <= n; i++) gi(a[i]);
		sort(a+1, a + n+1);
		for(int i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
		int ans=0;
		for(int st=0;st<k;st++){
			int tmp=p;
			int cnt=0;
			int id=st+1;
			while(id+k-1<=n){
				if(tmp-a[id+k-1]>=0){
					tmp-=a[id+k-1];
					id+=k;
					cnt+=k;
				}
				else break;
			}
			int l=1,r=st;
			int q=0;
			while(l<=r){
				int mid=(l+r)/2;
				if(sum[mid]<=tmp){
					q=mid;
					l=mid+1;
				}
				else{
					r=mid-1;
				}
			}
			cnt+=q;
			tmp-=sum[q];
			l=id,r=n;
			q=id-1;
			while(l<=r){
				int mid=(l+r)/2;
				if(sum[mid]-sum[id-1]<=tmp){
					q=mid;
					l=mid+1;
				}
				else r=mid-1;
			}
			cnt+=q-id+1;
			
			ans=max(ans,cnt);
		}
		printf("%d\n",ans);
	}
	return 0;
}















