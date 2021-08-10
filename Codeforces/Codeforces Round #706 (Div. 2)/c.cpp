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

vector<int>x,y;


int main(){
	
	int T;gi(T);while (T--) {
		int n;
		cin>>n;
		x.clear();y.clear();
		for(int i=1;i<=2*n;i++){
			int xx,yy;
			cin>>xx>>yy;
			if(xx==0){
				y.push_back(yy);
			}
			else x.push_back(xx);
		}
		for(int i=0;i<n;i++){
			x[i]=abs(x[i]);
			y[i]=abs(y[i]);
		}
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		double ans=0.0;
		for(int i=0,j=n-1;i<n;i++,j--){
			ans+=sqrt(1.0*x[i]*x[i]+1.0*y[i]*y[i]);
		}
		printf("%.13lf\n",ans);
		
	}
	
	return 0;
}















