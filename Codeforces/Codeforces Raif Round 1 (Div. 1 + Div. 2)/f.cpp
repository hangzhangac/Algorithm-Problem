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
const int MAXN=500005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char a[MAXN];
int s[MAXN];
int rig[MAXN];
typedef pair<int,int> P;
stack<P>st;
ll ans[MAXN];
int main(){
	int n;
	gi(n);
	cin>>(a+1);
	int cnt=0;
	for(int i=n;i>=1;i--){
		a[i]-='0';
		if(a[i]==0){
			cnt=s[i]=0;
		}
		else{
			cnt++,s[i]=cnt;
		}
	}
	ll num=0;
	for(int i=n;i>=1;i--){
		while(!st.empty()&&s[i]>=st.top().second){
			st.pop();
		}
		if(st.empty())rig[i]=-1;
		else rig[i]=st.top().first;
		st.push(P(i,s[i]));
		if(rig[i]==-1){
			int j=i+s[i]-1;
			ans[i]=(1LL+s[i])*s[i]/2+1LL*(n-j)*s[i];
		}
		else{
			int j=i+s[i]-1;
			int k=rig[i];
			ans[i]=1LL*(k-j-1)*s[i]+ans[k]+1LL*s[i]*s[i];//以下两步合并为一步
//			ans[i]=(1LL+s[i])*s[i]/2+1LL*(k-j-1)*s[i];
//			ans[i]+=ans[k]-(1LL+s[i])*s[i]/2+1LL*s[i]*s[i];
		}
		num+=ans[i];
	}
	cout<<num<<endl;
	return 0;
}