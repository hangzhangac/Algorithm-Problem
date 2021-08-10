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
int main(){
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	if(a[1]==1){
		a[0]=0;
	}
	else a[0]=1004;
	
	int cnt=1;
	int maxn=1;
	int i=1;
	int flag=0;
	while(i<=n&&a[i]==i){
		i++;
	}
	if(i>2)flag=1;
	maxn=max(maxn,i-2);
	i=n;
	while(i>=1&&a[i]==1000-n+i){
		i--;
	}
	if(n-i+1>2)flag=1;
	maxn=max(maxn,n-(i+2)+1);
	i=1;
	cnt=1;
	while(1){
		//int pre=i;
		while(i<=n-1&&a[i+1]==a[i]+1){
			cnt++;
			i++;
		}
		if(i==n){
			if(cnt-2>=1)flag=1;
			maxn=max(maxn,cnt-2);
			break;
		}
		else{
			if(cnt-2>=1)flag=1;
			maxn=max(maxn,cnt-2);
			i++;
			cnt=1;
		}
	}
	//int i=0;
	if(maxn==1&&!flag){
		printf("0\n");
	}
	else printf("%d\n",maxn);
	
	
	
	return 0;
}































