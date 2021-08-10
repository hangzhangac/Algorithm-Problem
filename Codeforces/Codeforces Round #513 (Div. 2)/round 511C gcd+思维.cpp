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
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=15000001;
int a[MAXN];

int s1[inf];
int s2[inf];
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
//使用：  v=read();
void Out(int a)    //输出外挂
{
	if(a>9)
		Out(a/10);
	putchar(a%10+'0');
}
int gcd(int n,int m){
	if(m==0)return n;
	return gcd(m,n%m);
}
int main(){
	
	int n;
	n=read();
	int gc=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		gc=gcd(gc,a[i]);
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		a[i]/=gc;
		s1[a[i]]++;
		maxn=max(maxn,a[i]+1);
	}
	int t=0;
	for(int i=2;i<maxn;i++){
		if(!s2[i]){
			int h=0;
			for(int j=i;j<maxn;j+=i){
				s2[j]=1;
				h+=s1[j];
			}
			t=max(h,t);
		}
	}
	if(t==0){
		putchar('-');
		putchar('1');
	}
	else{
		Out(n-t);
	}
	
	return 0;
}













