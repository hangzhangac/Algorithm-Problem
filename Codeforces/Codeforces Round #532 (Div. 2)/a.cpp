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
int a[105];
int main(){
	
	int n,k;
	cin>>n>>k;
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		gi(a[i]);
		if(a[i]==1){
			cnt1++;
		}
		else{
			a[i]=2;
			cnt2++;
		}
	}
	int maxn=0;
	
	for(int b=0;b<=k-1;b++){
		int e=0,f=0;
		for(int i=0;b+i*k<=n;i++){
			if(b+i*k==0)continue;
			if(a[b+i*k]==1){
				e++;
			}
			else{
				f++;
			}
		}
		maxn=max(maxn,abs(cnt1-e-(cnt2-f)));
	}
	printf("%d\n",maxn);
	
	
	return 0;
}



















