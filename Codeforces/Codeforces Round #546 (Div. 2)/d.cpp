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
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
map<int,int>ms[MAXN];
int p[MAXN];
int n,m;
int book[MAXN];
int main(){
	gi2(n,m);
	for(int i=1;i<=n;i++){
		gi(p[i]);
	}
	while(m--){
		int u,v;
		gi2(u,v);
		ms[u][v]=1;
		if(v==p[n]){
			book[u]=1;
		}
	}
	book[p[n]]=1;
	for(int i=n-1;i>=1;i--){
		if(!book[p[i]])continue;
		int j=i;
		int flag=0;
		while(j+1<n&&(ms[p[j]][p[j+1]]||book[p[j+1]])){
			if(book[p[j+1]]){
				book[p[j]]=1;
				flag=1;
				break;
			}
			swap(p[j],p[j+1]);
			j++;
		}
		if(!flag){
			if(ms[p[j]][p[j+1]]==0){
				book[p[j]]=0;
			}
		}
	}
	int i=n;
	while(i>=1&&book[p[i]]){
		i--;
	}
	printf("%d\n",n-i-1);
	
	
	
	return 0;
}



























