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
const int MAXN=305;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN];
int l[MAXN];
int r[MAXN];
int book[MAXN];
int main(){
	
	int n,m;
	gi2(n,m);
	for(int i=1;i<=n;i++){
		gi(a[i]);
		//b[i]=a[i];
	}
	for(int i=1;i<=m;i++){
		gi2(l[i],r[i]);
	}	
	if(n==1){
		printf("%d\n%d\n",0,0);
		return 0;
	}
	int maxn=0;
	int s=0,t=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			int cnt=0;
			for(int k=1;k<=m;k++){
				if(i>=l[k]&&i<=r[k]){
					continue;
				}
				if(j>=l[k]&&j<=r[k]){
					cnt++;
				}
			}
			if(maxn<a[i]-a[j]+cnt){
				maxn=max(a[i]-a[j]+cnt,maxn);
				s=i,t=j;
			}
			
		}
	}
	int i=s,j=t;
	printf("%d\n",maxn);
	int cnt=0;
	for(int k=1;k<=m;k++){
		if(i>=l[k]&&i<=r[k]){
			continue;
		}
		if(j>=l[k]&&j<=r[k]){
			cnt++;
			book[k]=1;
		}
	}
	printf("%d\n",cnt);
	for(int k=1;k<=m;k++){
		if(book[k]){
			printf("%d ",k);
		}
	}

	
	
	
	
	return 0;
}

