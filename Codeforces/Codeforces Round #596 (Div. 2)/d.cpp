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
int a[MAXN];
map< vector< pair<int,int> > ,int>ms;
int main(){
	
	int n,k;
	gi2(n,k);
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		vector< pair<int,int> >v1,v2;
		for(int j=2;j*j<=a[i];j++){
			int p=0;
			while(a[i]%j==0){
				p++;
				a[i]/=j;
			}
			if(p%k){
				v1.push_back(make_pair(j, p%k));
			}
		}
		if(a[i]>1){
			v1.push_back(make_pair(a[i], 1));
		}
		for(int j=0;j<v1.size();j++){
			v2.push_back(make_pair(v1[j].first, k-v1[j].second));
		}
		ans+=ms[v2];
		ms[v1]++;
	}
	printf("%lld\n",ans);
	return 0;
}
















