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
int main(){
	int T;
	cin>>T;while (T--) {
		int flag=0;
		int d;
		cin>>d;
		if(d==0||d>=4){
			double t=sqrt(d*d-4*d);
			double b=(d+t)/2;
			if(b>=0&&d-b>=0){
				printf("Y %.10lf %.10lf\n",b,d-b);
				continue;
			}
			b=(d-t)/2;
			if(b>=0&&d-b>=0){
				printf("Y %.10lf %.10lf\n",b,d-b);
				continue;
			}
			printf("N\n");
		}
		else{
			printf("N\n");
		}
	}
}