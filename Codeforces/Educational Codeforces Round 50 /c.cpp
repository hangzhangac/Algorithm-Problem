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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char l[25];
char r[25];
int suml[25];
int sumr[25];

ll C(int n,int m){
	if(n==0){
		return 1LL;
	}
	ll fenzi=1;
	ll fenmu=1;
	for(ll i=n-m+1;i<=n;i++){
		fenzi*=i;
	}
	for(ll i=1;i<=m;i++){
		fenmu*=i;
	}
	return fenzi/fenmu;
}
int main(){
	int T;gi(T);while(T--){
		scanf("%s",l+1);
		scanf("%s",r+1);
		int n=strlen(l+1);
		int m=strlen(r+1);
		for(int i=1;i<=n;i++){
			if(l[i]!='0'){
				suml[i]=suml[i-1]+1;
			}
			else suml[i]=suml[i-1];
		}
		for(int i=1;i<=m;i++){
			if(r[i]!='0'){
				sumr[i]=sumr[i-1]+1;
			}
			else sumr[i]=sumr[i-1];
		}
		int i=n;
		ll ans1=0;
		ll ans2=0;
		while(1){
			while(l[i]=='0'){
				i--;
			}
			//int t=suml[i];
			for(char j=l[i]-1;j>='0';j--){
				int t=suml[i];
				if(j=='0'){
					t--;
				}
				if(t>3){
					continue;
				}
				if(t==3){
					ans1++;
					continue;
				}
				int maxn=3-t;
				int wei=n-i;
				for(int i=0;i<=min(maxn,wei);i++){
					ll p=pow(9,i)+eps;
					ans1+=C(1LL*wei,1LL*i)*p;
				}
			}
			i--;
			if(i==0){
				break;
			}
		}

		i=m;
		while(1){
			while(r[i]=='0'){
				i--;
			}
			for(char j=r[i]-1;j>='0';j--){
				int t=sumr[i];
				if(j=='0'){
					t--;
				}
				if(t>3){
					continue;
				}
				if(t==3){
					ans2++;
					continue;
				}
				int maxn=3-t;
				int wei=m-i;
				for(int i=0;i<=min(maxn,wei);i++){
					ll p=pow(9,i)+eps;
					ans2+=C(1LL*wei,1LL*i)*p;
				}
			}
			i--;
			if(i==0){
				break;
			}
		}
		int cnt=0;
		for(int i=1;i<=m;i++){
			if(r[i]!='0'){
				cnt++;
			}
		}
		if(cnt<=3){
			ans2++;
		}
		printf("%lld\n",ans2-ans1);
		
	}
	
	
	return 0;
}




























