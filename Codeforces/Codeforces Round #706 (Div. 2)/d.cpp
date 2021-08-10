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
const int MAXN=100005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;
int n;
int a[MAXN];
int l[MAXN],r[MAXN];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	l[1]=0;
	r[n]=0;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			l[i]=l[i-1]+1;
		}
		else l[i]=0;
	}
	for(int i=n-1;i>=1;i--){
		if(a[i]>a[i+1]){
			r[i]=r[i+1]+1;
		}
		else r[i]=0;
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		int aa=max(l[i],r[i]);
		maxn=max(aa,maxn);
	}
	int cnt=0;
	int flag=1;
	for(int i=1;i<=n;i++){
		if(l[i]==maxn||r[i]==maxn){
			cnt++;
		}
	}
	if(cnt>=2){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		int qq=int((l[i]==maxn))+int((r[i]==maxn));
		if(qq==2){
			if(l[i]&1){
				printf("0\n");
			}
			else{
				printf("1\n");
			}
			return 0;
		}
	}
	printf("0\n");
	
	
	return 0;
}















