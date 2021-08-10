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
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=400005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n,I;
map<int,int>ms;
int a[MAXN];
int b[MAXN];
int book[MAXN];
int sum[MAXN];
int main(){
	gi2(n,I);I*=8;
	int k=I/n;
	int num=1;
	for(int i=0;i<n;i++){
		gi(a[i+1]);
		b[i]=a[i+1];
	}
	sort(b,b+n);
	int cnt=unique(b, b+n)-b;
	for(int i=0;i<cnt;i++){
		ms[b[i]]=i+1;
	}
	while(k--){
		num*=2;
		if(num>=cnt)break;
	}
	if(num>=cnt){
		printf("0\n");
	}
	else{
		for(int i=1;i<=n;i++){
			int t=ms[a[i]];
			book[t]++;
		}
		for(int i=1;i<=cnt;i++){
			sum[i]=sum[i-1]+book[i];
		}
		int minn=inf;
		for(int i=1;i+num-1<=cnt;i++){
			int j=i+num-1;
			int nn=sum[i-1]+sum[cnt]-sum[j];
			minn=min(nn,minn);
		}
		printf("%d\n",minn);
	}
	return 0;
}









