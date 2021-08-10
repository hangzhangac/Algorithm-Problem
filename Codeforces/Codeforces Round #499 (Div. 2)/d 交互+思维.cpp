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
int n,m;
int a[MAXN];
int b[MAXN];
int p[MAXN];
int main(){
	
	cin>>m>>n;
	int flag=0;
	for(int i=1;i<=n;i++){
		cout<<1<<endl;
		int t;
		cin>>t;
		if(t==-1){//jia
			p[i]=0;
		}
		if(t==1){//zhen
			p[i]=1;
		}
		if(t==0){
			return 0;
			flag=1;
		}
	}
	int cnt=1;
	int cnt1=0;
	int l=2,r=m;
	while(cnt1<=30){
		if(cnt>n)cnt=1;
		int mid=(l+r)/2;
		cout<<mid<<endl;
		int t;
		cin>>t;
		if(t==0){
			return 0;
		}
		if(p[cnt]==0){//jia
			t=-t;
		}
		if(t==1){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
		cnt1++;
		cnt++;
	}
	return 0;
}