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
int book[1000];
bool judge(int l,int r){
	for(int i=l,j=r;i<j;i++,j--){
		if(a[i]!=a[j])return false;
	}
	return true;
}
int cal(int l,int r){
	int t=r-l+1;
	int mid=(l+r)/2;
	if(t&1){
		if(judge(l, r)){
			return 2;
		}
		return 1;
	}
	if(judge(l,r)){
		return cal(l,mid);
	}
	else{
		return 1;
	}
}
int main(){
	scanf("%s",a+1);
	int n=strlen(a+1);
	if(n==1||n==2||n==3){
		printf("Impossible\n");
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(book[a[i]]==0){
			book[a[i]]=1;
			cnt++;
		}
		if(cnt>=2)break;
	}
	if(cnt==1){
		printf("Impossible\n");
		return 0;
	}
	mem(book,0);
	
	if(n&1){
		cnt=0;
		int mid=(1+n)/2;
		for(int i=1;i<=n;i++){
			if(i==mid)continue;
			if(!book[a[i]]){
				book[a[i]]=1;
				cnt++;
			}
		}
		if(cnt==1){
			printf("Impossible\n");
			return 0;
		}
	}
	if(n%2==0){
		int mid=(1+n)/2;
		int ans=1;
		if(!judge(1,mid)){
			ans=1;
		}
		else{
			if(mid&1)ans=2;
			else{
				ans=cal(1,n);
			}
		}
		printf("%d\n",ans);
		return 0;
		
	}
	else{
		int ans=2;
		printf("%d\n",ans);
	}
	return 0;
}


















