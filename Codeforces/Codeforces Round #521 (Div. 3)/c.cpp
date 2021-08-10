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
vector<int>ans;
int a[MAXN];
int main(){
	
	int n;
	gi(n);
	ll sum=0;
	for(int i=1;i<=n;i++){
		gi(a[i]);
		sum+=a[i];
	}
	int pos=1;
	int maxn=a[1];
	for(int i=2;i<=n;i++){
		if(maxn<a[i]){
			maxn=a[i];
			pos=i;
		}
	}
	int pos2=-1;
	int maxn2=0;
	for(int i=1;i<=n;i++){
		if(i==pos)continue;
		if(maxn2<a[i]){
			maxn2=a[i];
			pos2=i;
		}
	}
	for(int i=1;i<=n;i++){
		ll num=sum-a[i];
		if(i!=pos){
			num-=maxn;
			if(num==maxn){
				ans.push_back(i);
			}
		}
		else{
			num-=maxn2;
			if(num==maxn2){
				ans.push_back(i);
			}
		}
	}
	printf("%ld\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	
	return 0;
}






























