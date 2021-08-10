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
int f0[MAXN],f1[MAXN];
int sz0[MAXN],sz1[MAXN];
int n;
int find1(int x,int f[]){
	if(f[x]==x)return x;
	return f[x]=find1(f[x],f);
}
void init(){
	for(int i=1;i<=n;i++){
		f0[i]=i;f1[i]=i;
		sz0[i]=1;sz1[i]=1;
	}
}
void merge(int x,int y,int f[],int sz[]){
	int fx=find1(x,f),fy=find1(y,f);
	if(fx==fy)return ;
	f[fx]=fy;
	sz[fy]+=sz[fx];
}
int main(){
	
	gi(n);
	init();
	for(int i=1;i<=n-1;i++){
		int x,y,z;
		gi3(x,y,z);
		if(z){
			merge(x, y, f1, sz1);
		}
		else merge(x,y,f0,sz0);
	}
	ll cnt=0;
//	for(int i=1;i<=n;i++){
//		cout<<i<<":";	cout<<find1(i,f0)<<" "<<find1(i,f1)<<endl;
//	}
	for(int i=1;i<=n;i++){
		if(f0[i]==i){
			cnt+=1LL*sz0[i]*(sz0[i]-1);
		}
		if(f1[i]==i){
			cnt+=1LL*sz1[i]*(sz1[i]-1);
		}
		int fi0=find1(i,f0),fi1=find1(i, f1);
		cnt+=1LL*(sz0[fi0]-1)*(sz1[fi1]-1);
	}
	printf("%lld\n",cnt);
	
	
	
	
	return 0;
}





