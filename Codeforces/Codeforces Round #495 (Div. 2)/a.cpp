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
int x[MAXN];
map<int,int>ms;
int main(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		gi(x[i]);
	}
	int cnt=1;
	for(int i=1;i<=n;i++){
		int t=x[i]+d;
		if(t<x[i+1]&&x[i+1]-t>=d||i==n){
			if(!ms[t]){
				cnt++;
				ms[t]=1;
			}
			//cnt++;
		}
		if(i!=n){
			int t=x[i+1]-d;
			if(t-x[i]>=d){
				if(!ms[t]){
					cnt++;
					ms[t]=1;
				}
			}
		}
	}
	printf("%d\n",cnt);
	
	
	return 0;
}































