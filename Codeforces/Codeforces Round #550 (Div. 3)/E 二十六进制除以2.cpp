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
char s[MAXN],t[MAXN];
int ans[MAXN];
int main(){
	int n;gi(n);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;i++){
		s[i]-='a';
		t[i]-='a';
	}
	for(int i=n;i>=1;i--){
		ans[i]+=s[i]+t[i];
		if(ans[i]>=26){
			ans[i-1]++;
			ans[i]-=26;
		}
	}
	for(int i=0;i<=n;i++){
		if(ans[i]&1){
			ans[i+1]+=26;
		}
		ans[i]/=2;
		s[i]=ans[i]+'a';
	}
	cout<<s+1<<endl;
	return 0;
}












