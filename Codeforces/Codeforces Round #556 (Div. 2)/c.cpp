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
const int MAXN=400005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n;int cnt1=0,cnt2=0;
int prime[MAXN];
vector<int>p;
void init(){
	p.push_back(0);
	for(int i=2;i<=2*n;i++){
		if(prime[i]==0){//zhishu
			p.push_back(i);
			for(int j=i*2;j<=2*n;j+=i){
				prime[j]=1;
			}
		}
	}
}
int main(){
	
	gi(n);
	init();
	for(int i=1;i<=n;i++){
		int x;
		gi(x);
		if(x==1)cnt1++;
		else cnt2++;
	}
	int cur=0;
	for(int i=1;i<p.size();i++){
		int t=p[i]-p[i-1];
		if(cnt1==0||cnt2==0)break;
		if(t&1){
			cnt1--;
			t--;
			printf("1 ");
		}
		while(t){
			if(cnt2){
				cnt2--;
				t-=2;
				printf("2 ");
			}
			else if(cnt1>=2){
				cnt1-=2;
				printf("1 1 ");
			}
			else break;
		}
	}
	while(cnt1--){
		printf("1 ");
	}
	while(cnt2--){
		printf("2 ");
	}
	
	
	
	
	return 0;
}





