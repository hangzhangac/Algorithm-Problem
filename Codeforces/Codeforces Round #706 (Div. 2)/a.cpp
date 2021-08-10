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

string s;
int n,k;
int main(){
	
	int t;gi(t);while(t--){
		cin>>n>>k;
		cin>>s;
		int flag=0;
		for(int i=0,j=n-1;i<k;i++,j--){
			if(s[i]==s[j]){
				
			}
			else flag=1;
		}
		if(flag){
			printf("NO\n");
		}
		else{
			if(n%2==0&&k==n/2){
				printf("NO\n");
			}
			else printf("YES\n");
		}
	}
	
	return 0;
}















