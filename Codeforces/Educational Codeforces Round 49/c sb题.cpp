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
#include <stack>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=1000005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int book[10005];
int a[MAXN];
int ans[10005];
int read()     //输入外挂
{
	int res=0,ch,flag=0;
	if((ch=getchar())=='-')
		flag=1;
	else if(ch>='0'&&ch<='9')
		res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-'0';
	return flag?-res:res;
}
int main(){
	int T;T=read();while(T--){
	int num=0;
	int n;n=read();
	for(int i=1;i<=10000;i++){
		book[i]=0;
	}

	for(int i=1;i<=n;i++){
		a[i]=read();
		book[a[i]]++;
		if(book[a[i]]==2||book[a[i]]==4){
			ans[num++]=a[i];
		}
	}
	sort(ans,ans+num);
	int x=-1,y=-1;
	double d=10000000000000.0;
	for(int i=0;i+1<num;i++){
		double t=ans[i];
		double s=ans[i+1];
		double dis=t/s+s/t;
		if(d>dis){
			d=dis;
			x=ans[i];
			y=ans[i+1];
		}
	}
	printf("%d %d %d %d\n",x,x,y,y);
	
	}
	
	
	return 0;
}

