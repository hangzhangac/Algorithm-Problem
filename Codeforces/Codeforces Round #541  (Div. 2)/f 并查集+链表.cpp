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
const int MAXN=150005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int you[MAXN];
int zuo[MAXN];
int l[MAXN];
int r[MAXN];
int n;
void init(){
	for(int i=1;i<=n;i++) you[i]=zuo[i]=l[i]=r[i]=i;
}
int find1(int f[],int x){
	if(x==f[x])return x;
	return f[x]=find1(f,f[x]);
}
int main(){
	gi(n);init();
	for(int i=1;i<=n-1;i++){
		int x,y;
		gi2(x,y);
		int fx=find1(you,x);
		int fy=find1(zuo,y);
		r[fx]=fy;
		l[fy]=fx;
		you[fx]=find1(you,y);
		zuo[fy]=find1(zuo,x);
	}
	int flag=-1;
	for(int i=1;i<=n;i++){
		if(l[i]==i){
			flag=i;break;
		}
	}
	while(r[flag]!=flag){
		cout<<flag<<' ';
		flag=r[flag];
	}
	cout<<flag<<endl;
	return 0;
}











