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
ll a[MAXN];
char s[MAXN];
vector<int>ans;
int main(){
	
	int n,k;
	gi2(n,k);
	for(int i=1;i<=n;i++){
		gll(a[i]);
	}
	scanf("%s",s+1);
	char cur=s[1];
	ll sum=0;
	int i=1;
	while(i<=n){
		char cur=s[i];
		ans.push_back(a[i]);
		i++;
		while(i<=n&&s[i]==cur){
			ans.push_back(a[i]);
			i++;
		}
		sort(ans.begin(),ans.end());
		int t=ans.size()-1;
		int q=k;
		while(t>=0&&q>0){
			q--;
			sum+=ans[t];
			t--;
		}
		ans.clear();
	}
	printf("%lld\n",sum);
	
	
	
	
	
	
	return 0;
}

















