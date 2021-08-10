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
const ll mod=9;
const int inf=0x3f3f3f3f;
char a[MAXN];
ll f[25][2][10];
ll Solve(char a[]){
	int n=strlen(a+1);
	a[0]=0;
	for(int i=1;i<=n;i++){
		a[i]-='0';
	}
	a[n+1]=0;
//	for(int i=1;i<=n;i++){
//		printf("%d",a[i]);
//	}
//	printf("\n");
	f[0][1][0]=1;
	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=1;j++){
			for(int k=0;k<=8;k++){
				if(!f[i][j][k])continue;
				if(j==1){
					f[i+1][j][(k+a[i+1])%mod]+=f[i][j][k];
					for(int nx=0;nx<a[i+1];nx++){
						f[i+1][0][(nx+k)%mod]+=f[i][j][k];
					}
				}
				else{
					for(int nx=0;nx<=8;nx++){
						f[i+1][j][(nx+k)%mod]+=f[i][j][k];
					}
				}
			}
		}
	}
//	cout<<f[1][1][1]<<' '<<f[1][0][0]<<endl;
//	cout<<f[2][1][7]<<endl;
//	cout<<"fea"<<endl;
//	for(int i=1;i<=8;i++){
//		cout<<i<<' '<<f[2][0][i]<<endl;
//	}
	ll ans=0;
	for(int i=1;i<=8;i++){
		ans+=f[n][0][i]+f[n][1][i];
	}
//	cout<<"---"<<endl;
	return ans;
}
int main(){
	int cnt=1;
	int T;gi(T);
	while(T--){
		mem(f,0);
		scanf("%s",a+1);
		ll ans=Solve(a);
		mem(f,0);
		scanf("%s",a+1);
		ans=Solve(a)-ans;
		
		printf("Case #%d: %lld\n",cnt++,ans+1);
	}
	
	
	
	
	return 0;
}






