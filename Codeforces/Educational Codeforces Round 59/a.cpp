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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char a[MAXN];
vector<int>ans;
int main(){
	
	int T;
	gi(T);
	while(T--){
		int n;
		gi(n);
		scanf("%s",a);
		ans.clear();
		for(int i=0;i<n;i++){
			a[i]=a[i]-'0';
		}
		int cur=0;
		ans.push_back(a[0]);
		int i=1;
		if(n==2&&a[1]<=a[0]){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		printf("2\n");
		printf("%d ",a[0]);
		for(int i=1;i<n;i++){
			printf("%d",a[i]);
		}
		printf("\n");
	}
	
	
	return 0;
}

















