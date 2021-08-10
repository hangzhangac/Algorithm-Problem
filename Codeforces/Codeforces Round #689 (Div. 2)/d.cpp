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
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;

int a[MAXN],b[MAXN];
ll sum[MAXN];
vector<ll>cur;
void dfs(int l,int r,int minn,int maxn){
	if(l>r)return;
	cur.push_back(sum[r]-sum[l-1]);
	int q=(minn+maxn)/2;
	int id_mid=upper_bound(b+l, b+r+1, q)-b-1;
	int left_r=id_mid,right_l=id_mid+1;
	if(left_r<l||right_l>r){
		return;
	}
	else{
		dfs(l,left_r,b[l],b[left_r]);
		dfs(right_l,r,b[right_l],b[r]);
	}
}
int main(){
	int T;gi(T);while(T--){
		cur.clear();
		int n,q;
		gi2(n,q);
		for(int i=1;i<=n;i++){
			gi(a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+b[i];
		dfs(1,n,b[1],b[n]);
		sort(cur.begin(),cur.end());
		while(q--){
			ll s;
			gll(s);
			int id=lower_bound(cur.begin(), cur.end(), s)-cur.begin();
			if(id>=0&&id<cur.size()&&cur[id]==s){
				printf("Yes\n");
			}
			else printf("No\n");
		}
	}
	return 0;
}