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
char a[MAXN];
int n;
int sum1[MAXN];
int sum2[MAXN];
int z,h;
int x,y;
int x2,y2;
bool C(int l,int mid){
	int t=mid-l;
	int z1=y2-(sum1[mid]-sum1[l]);
	int h1=x2-(sum2[mid]-sum2[l]);
	if(abs(x-h1)+abs(y-z1)==t)return true;
	int q=abs(x-h1)+abs(y-z1);
	if(q>t)return false;
	if((t-q)%2==0)return true;
	return false;
}
int main(){
	gi(n);
	scanf("%s",a+1);
	gi2(x, y);
	for(int i=1;i<=n;i++){
		sum1[i]=sum1[i-1];
		sum2[i]=sum2[i-1];
		if(a[i]=='U'){
			sum1[i]=sum1[i-1]+1;
		}
		else if(a[i]=='D'){
			sum1[i]=sum1[i-1]-1;
		}
		else if(a[i]=='R'){
			sum2[i]=sum2[i-1]+1;
		}
		else if(a[i]=='L'){
			sum2[i]=sum2[i-1]-1;
		}
	}
	y2=sum1[n],x2=sum2[n];//ZUOBIAO
	z=sum1[n]-y;//差值
	h=sum2[n]-x;
	//cout<<z<<' '<<h<<endl;
	if(z==0&&h==0){
		printf("0\n");
		return 0;
	}
	int ans=inf;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		int ans1=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(C(i-1,mid)){
				ans1=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		if(ans1==-1);
		else ans=min(ans,ans1-i+1);
	}
	if(ans==inf)printf("-1\n");
	else
	printf("%d\n",ans);
	return 0;
}






