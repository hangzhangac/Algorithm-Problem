#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
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
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=500005;
const ll mo=1e7+9;
const int inf=0x3f3f3f3f;
ll qMul(ll a,ll b,ll mo){
	ll an = 0;
	while(b) {
		if(b&1) an =(an+a) % mo;
		a = (a+a)%mo;
		b>>=1;
	}return an%mo;
}
//扩展欧几里得算法，返回gcd(a,b),并计算出ax+by = gcd(a,b)中的x和y
ll exGcd(ll a,ll b,ll &x,ll &y){
	if( b == 0 ) { x = 1;y = 0; return a;}
	ll gcd = exGcd(b,a%b,y,x);  //注意x和y的顺序
	y = y - a/b*x;
	return gcd;
}
ll exCRT(ll mod[],ll yu[],int n){
	ll ans = yu[1],M = mod[1] ,t,y;  //ans表示前i-1个方程式的特解（余数），M为前i-1个方程式的模数的最小公倍数(i从2开始)
	for(int i = 2;i <= n;i++){
		ll mi = mod[i],res = ((yu[i] - ans)%mi + mi)%mi;  //res是等式的右边部分，不能出现负数
		ll gcd = exGcd(M,mi,t,y);        //求出gcd(mi,M)
		if(res % gcd != 0) {return -1;}   //如果等式右边不能整除gcd，方程组无解
		t = qMul(t,res/gcd,mi);            //求出t还要乘上倍数，注意是快速乘取模mi (对谁取模要分清)
		ans += t * M;                               //得到前i个方程的特解（余数）
		M = mi /gcd * M;                         //M等于lcm(M,mi)，注意乘法要在除法后面做，否则会爆long long
		ans = (ans%M+M)%M;                //让特解范围限定在0~(M-1)内，防止会出现负数
	}
	return ans;
}

int book[10000005];
int a[MAXN],b[MAXN];
pair<ll,ll>c[MAXN];
int n,m;
ll k;
bool C(ll mid){
	ll ans=0;
	for(int i=0;i<m;i++){
		if(c[i].second!=0){
			if(c[i].first+1>mid)continue;
			ans+=(mid-(c[i].first+1))/c[i].second+1;
		}
	}
	return mid-ans>=k;
}
int main(){
	memset(book,-1,sizeof(book));
	gi2(n, m);
	gll(k);
	for(int i=0;i<n;i++){
		gi(a[i]);
		book[a[i]]=i;
	}
	ll mod[3],yu[3];
	ll x,y;
	ll gc=n/exGcd(n, m, x, y)*m;
	for(int i=0;i<m;i++){
		gi(b[i]);
		if(book[b[i]]!=-1){
			mod[1]=n;yu[1]=book[b[i]];
			mod[2]=m;yu[2]=i;
			ll ans=exCRT(mod, yu, 2);
			if(ans==-1)continue;
			c[i].first=ans;
			c[i].second=gc;
		}
	}
	/*
	4 3 3
	1 2 3 4
	1 2 3*/
	ll l=1,r=1LL*max(n,m)*k;
	while(l<=r){
		ll mid=(l+r)/2;
		if(C(mid)){
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<l<<endl;
	
	
	
	
	return 0;
}

















