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
int a[MAXN];
int book[MAXN];
int sum[MAXN];
int flag[MAXN];
int main(){
	
	int n;gi(n);
	
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	int cur=0,cnt=0,ans=1,ans1=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			ans1++;
		}
		else break;
	}
	for(int i=1;i<=n;i++){
		int t=a[i];
		if(!book[t]){
		}
		else{
			sum[book[t]]--;
			if(sum[book[t]]==0){
				cnt--;
			}
		}
		book[t]++;
		if(sum[book[t]]==0)cnt++;
		sum[book[t]]++;
		cur=book[t];
		if(cnt==1){
			if(sum[1])ans=i;
		}
		else if(cnt==2){
			if(sum[cur+1]==1){
				ans=i;
			}
			else if(sum[cur]==1&&sum[cur-1]){
				ans=i;
			}
			else if(sum[1]==1){
				ans=i;
			}
		}
	}
	printf("%d\n",max(ans1,ans));
	
	
	
	
	return 0;
}


