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
int a[10005];
int main(){
	
	mem(a,-1);
	for(int i=3;i<=360;i++){
		for(int j=1;j<=i-2;j++){
			if(j*180%i==0&&j*180/i<180){
				int t=j*180/i;
				if(a[t]==-1)a[t]=i;
			}
		}
	}
	int T;
	cin>>T;
	while(T--){
		int ag;
		cin>>ag;
		cout<<a[ag]<<endl;
	}
	
	
	
	return 0;
}