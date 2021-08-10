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
int b[MAXN];
int sum[MAXN];
int main(){
	gi(n);
	for(int i=1;i<=n;i++)gi(a[i]);
	if(n>60){
		cout<<1<<endl;
		return 0;
	}
	if(n==1||n==2){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
	}
	int minn=n;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int left=sum[j]^sum[i-1];
				int rig=sum[k]^sum[j];
				if(left>rig){
					minn=min(j-i+k-(j+1),minn);
				}
			}
		}
	}
	if(minn==n)minn=-1;
	cout<<minn<<endl;
	return 0;
}























