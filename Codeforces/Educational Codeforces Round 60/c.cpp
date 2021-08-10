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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int x,y;
int x2,y2;
int n;
char a[MAXN];
ll lf=0,ud=0,lr=0,ld=0;
char l,u,r,d;
ll sum=0;
ll s[5];
/*
0 0
3 7
4
LRRR
卡我的样例*/
int C(ll mid){
	ll rr=mid*lf; ll fr=mid*lr;
	ll uu=mid*ud; ll fu=mid*ld;
	ll z=mid*sum;
	
	for(int i=1;i<=n;i++){
		if(a[i]==l){rr++;z++;}
		if(a[i]==u){uu++;z++;}
		if(a[i]==r){fr++;}
		if(a[i]==d)fu++;
		s[0]=rr;s[1]=uu;s[2]=z;s[3]=fr;s[4]=fu;
		if(rr>abs(x2)){
			ll cha=rr-abs(x2);
			ll cha1=max(0LL,cha-fr);
			z+=min(fr,cha);
			z-=cha1;
			rr=abs(x2);
		}
		if(uu>abs(y2)){
			ll cha=uu-abs(y2);
			ll cha1=max(0LL,cha-fu);
			z+=min(fu,cha);
			z-=cha1;
			uu=abs(y2);
		}
		z-=abs(x2)-rr;
		z-=abs(y2)-uu;
		if(z>=0) return i;
		rr=s[0];uu=s[1];z=s[2];fr=s[3];fu=s[4];
	}
	return -1;
}
int main(){
	
	cin>>x>>y>>x2>>y2>>n;
	scanf("%s",a+1);
	x2-=x;y2-=y;x=y=0;
	if(x2>=0)l='R',r='L';
	else l='L',r='R';
	if(y2>=0)u='U',d='D';
	else u='D',d='U';
	for(int i=1;i<=n;i++){
		if(a[i]==l){lf++;sum++;}
		if(a[i]==r){lr++;}
		
		if(a[i]==u){ud++;sum++;}
		if(a[i]==d){ld++;}
	}
	ll ll1=0,rr=2000000000;
	ll ans=-1;
	while(ll1<=rr){
		ll mid=(ll1+rr)/2;
		ll t=C(mid);
		if(t!=-1){
			rr=mid-1;
			ans=mid*n+t;
		}
		else{
			ll1=mid+1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}












