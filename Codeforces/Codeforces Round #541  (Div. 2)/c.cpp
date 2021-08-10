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
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=105;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int book[MAXN];
int a[MAXN];
int n;
vector<int>ans1;
bool C(int mid){
	for(int i=1;i<=n;i++)book[i]=0;
	ans1.clear();
	book[1]=1;
	int cur=a[1];
	ans1.push_back(a[1]);
	while(1){
		int q=-1;
		for(int i=n;i>=1;i--){
			if(!book[i]){
				if(a[i]-cur<=mid){
					ans1.push_back(a[i]);
					q=i;
					cur=a[i];
					book[i]=1;
					break;
				}
			}
		}
		if(q==-1)return false;
		if(q==n)break;
	}
	for(int i=n;i>=1;i--){
		if(!book[i]){
			ans1.push_back(a[i]);
		}
	}
	for(int i=0;i<ans1.size();i++){
		int j=(i+1)%(ans1.size());
		if(abs(ans1[i]-ans1[j])>mid)return false;
	}
	
	return true;
}
int main(){
	
	gi(n);
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	sort(a+1,a+n+1);
	int l=1,r=1e9+.5;
	int ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(C(mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	C(ans);
	for(int i=0;i<ans1.size();i++){
		cout<<ans1[i]<<' ';
	}
	return 0;
}
















