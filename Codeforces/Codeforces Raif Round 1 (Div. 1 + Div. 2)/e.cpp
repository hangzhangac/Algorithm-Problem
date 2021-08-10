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
typedef pair<ll,int> P;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN];
int cnt[MAXN];
int n,k;
priority_queue<P>p;
ll get(int a,int b){
	int mod=a%b;
	ll q=a/b;
	ll ans=(q+1)*(q+1)*mod+q*q*(b-mod);
	return ans;
}
int main(){
	
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		p.push(P(get(a[i],1)-get(a[i],2),i));
	}
	while(k-->n){
		P e=p.top();
		p.pop();
		int i=e.second;
		cnt[i]++;
		p.push(P(get(a[i],cnt[i]+1)-get(a[i],cnt[i]+2),i));
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=get(a[i],cnt[i]+1);
	}
	cout<<ans<<endl;
	
		
	
	
	
	
	return 0;
}










