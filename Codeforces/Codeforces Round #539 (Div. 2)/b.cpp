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
int a[MAXN];
int main(){
	
	int n;
	gi(n);
	int sum=0;
	int minn=101;
	for(int i=1;i<=n;i++){
		gi(a[i]);
		sum+=a[i];
		minn=min(minn,a[i]);
	}
	int num=0;
	int sum1=sum;
	//cout<<minn<<endl;
	for(int x=2;x<=100;x++){
		int maxn=0;
		for(int i=1;i<=n;i++){
			if(a[i]%x==0){
				maxn=max(a[i],maxn);
			}
		}
		if(maxn!=0){
			num=sum1;
			num+=(x-1)*minn;
			num-=maxn;
			num+=maxn/x;
			sum=min(sum,num);
		//	cout<<sum<<' '<<x<<endl;
		}
		
	}
	printf("%d\n",sum);
	
	
	
	return 0;
}


















