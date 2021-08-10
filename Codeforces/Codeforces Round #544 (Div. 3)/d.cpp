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
const int MAXN=600005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int gcd(int a,int b){
	//if(a==0&&b==0)printf("YES\n");
	if(b==0)return a;
	else return gcd(b,a%b);
}
int a[MAXN];
int b[MAXN];
struct Node{
	int a,b;
}node[MAXN];
bool cmp3(Node a,Node b){
	if(a.a==b.a)return a.b<b.b;
	else return a.a<b.a;
}
map<int,int>ms[2];
int main(){
	int n;
	gi(n);
	for(int i=1;i<=n;i++)gi(node[i].a);
	for(int i=1;i<=n;i++){
		gi(node[i].b);
	}
	int st=1;
	for(int i=1;i<=n;i++){
		if(node[i].a==node[i].b&&node[i].a==0){
			swap(node[i],node[st++]);
		}
	}
	if(st==n+1){
		printf("%d\n",n);
		return 0;
	}
	int cnt=st-1;
	int st1=st;
	for(int i=st;i<=n;i++){
		if(node[i].a==0){
			swap(node[i],node[st1++]);
		}
	}
	if(st1==n+1){
		printf("%d\n",cnt);return 0;
	}
	
	int st2=st1;
	for(int i=st1;i<=n;i++){
		if(node[i].b==0){
			swap(node[i],node[st2++]);
		}
	}
	if(st2==n+1){
		printf("%d\n",cnt+n-st1+1);
		return 0;
	}
	//if(st2>n){printf("YES\n");return 0;}
	int maxn=cnt+st2-st1;
	int len=0;
	for(int i=st2;i<=n;i++){
		ll t=1ll*node[i].a*node[i].b;
		int flag;
		if(t<0){
			flag=1;
			node[i].a=abs(node[i].a);
			node[i].b=abs(node[i].b);
		}
		else flag=0;
		int g=gcd(node[i].a,node[i].b);
		//if(node[i].g==0){printf("YES\n");return 0;}
		node[i].a/=g;
		node[i].b/=g;
		if(flag)node[i].a=-node[i].a;
		a[len++]=node[i].a;
		b[len-1]=node[i].b;
	}
	int len1=len;
	sort(a,a+len);
	len=unique(a, a+len)-a;
	sort(b,b+len1);
	len1=unique(b,b+len1)-b;
	for(int i=0;i<len;i++){
		ms[0][a[i]]=i+1;
	}
	for(int i=0;i<len1;i++){
		ms[1][b[i]]=i+1;
	}
	for(int i=st2;i<=n;i++){
		
		node[i].a=ms[0][node[i].a];
		node[i].b=ms[1][node[i].b];
	//	cout<<node[i].a<<' '<<node[i].b<<endl;
	}
	//cout<<1<<endl;
	if(st1>n){printf("YES\n");return 0;}
	sort(node+st2,node+n+1,cmp3);
	int minn=1;
	int cur=1;
	//cout<<st2<<endl;
	for(int i=st2+1;i<=n;i++){
		//cout<<"fea"<<endl;
		if(node[i].a==node[i-1].a&&node[i].b==node[i-1].b){
			cur++;
		}
		else{
			minn=max(cur,minn);
			cur=1;
		}
		
	}
	//cout<<cur<<endl;
	minn=max(cur,minn);
	maxn=max(minn+cnt,maxn);
	printf("%d\n",maxn);
	return 0;
}
/*
10
6 2 2 0 0 0 0 4 5 11
3 0 1 4 0 2 0 0 1 1
*/











