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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN];
int nx[MAXN];
int book[MAXN];
int main(){
	
	int n;
	cin>>n;
	int pre=0;
	int cnt=0;
	int maxn=-inf;
	int pos=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0){
			cnt++;
			if(maxn<a[i]){
				maxn=a[i];
				pos=i;
			}
		}
		if(a[i]==0){
			nx[pre]=i;
			pre=i;
		}
	}
	nx[pre]=n+1;
	if(cnt&1){
		pre=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0||i==pos){
				nx[pre]=i;
				pre=i;
			}
		}
		nx[pre]=n+1;
	}
		int ans=0;
		int s=0,ss=0;
		book[s]=1;
		while(nx[s]!=n+1){
			if(s!=0){ss++;printf("1 %d %d\n",s,nx[s]);}
			s=nx[s];
			book[s]=1;
			
		}
		if(ss!=n-1&&s!=0)
		printf("2 %d\n",s);
		int i=1;
		while(i<=n&&book[i]==1){
			i++;
		}
		if(i>n){
			return 0;
		}
		book[i]=1;
		ans=a[i];
		int j=1;
		while(j<=n&&book[j]==1){
			j++;
		}
		if(j>n){
			return 0;
		}
		book[j]=1;
		printf("1 %d %d\n",i,j);
		i=j;
		while(1){
			while(j<=n&&book[j]==1){
				j++;
			}
			if(j>n)break;
			printf("1 %d %d\n",i,j);
			book[j]=1;
			i=j;
		}
		
	
	
	return 0;
}































