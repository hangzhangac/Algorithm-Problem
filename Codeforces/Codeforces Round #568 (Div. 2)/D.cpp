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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;

ll dif[MAXN];
map<ll,int>ms;
struct Node{
	ll a;
	int id;
}a[MAXN];
bool cmp(Node a,Node b){
	return a.a<b.a;
}
int main(){
	
	int n;gi(n);
	for(int i=1;i<=n;i++){
		gll(a[i].a);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	if(n<=3){
		printf("%d\n",a[n].id);return 0;
	}
	int cnt=0;
	for(int i=2;i<=n;i++){
		ll t=a[i].a-a[i-1].a;
		if(ms[t]==0){
			cnt++;
			ms[t]=1;
		}
		else{
			ms[t]++;
		}
		
	}
	ll t=a[2].a-a[1].a;
	if(cnt==1){
		printf("%d\n",a[1].id);
		return 0;
	}
	if(ms[t]==1&&cnt==2){
		printf("%d\n",a[1].id);
		return 0;
	}
	t=a[n].a-a[n-1].a;
	if(ms[t]==1&&cnt==2){
		printf("%d\n",a[n].id);
		return 0;
	}
	for(int i=2;i<=n-1;i++){
		ll t1=a[i].a-a[i-1].a;
		ll t2=a[i+1].a-a[i].a;
		ll t3=a[i+1].a-a[i-1].a;
		ms[t1]--;
		if(!ms[t1])cnt--;
		ms[t2]--;
		if(!ms[t2])cnt--;
		if(ms[t3]==0)cnt++;
		if(cnt==1){
			printf("%d\n",a[i].id);
			return 0;
		}
		if(ms[t3]==0)cnt--;
		ms[t1]++;
		if(ms[t1]==1)cnt++;
		ms[t2]++;
		if(ms[t2]==1)cnt++;
		
	}
	printf("-1\n");
	return 0;
	
}