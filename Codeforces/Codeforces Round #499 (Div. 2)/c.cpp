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
bool C(double mid){
	double cur=m+mid;
	for(int i=1,j;i<=n;i++){
		j=i+1;
		if(j>n)j=1;
		cur-=cur/a[i];
		//cout<<cur<<endl;
		if(cur<m*1.0)return false;
		cur-=cur/b[j];
		if(cur<m*1.0)return false;
	}
	//cout<<"fea"<<endl;
	return true;
	
}
int main(){
	
	gi2(n, m);
	int flag=0;
	for(int i=1;i<=n;i++){
		gi(a[i]);
		if(a[i]==1){
			flag=1;
		}
	}
	for(int i=1;i<=n;i++){
		gi(b[i]);
		if(b[i]==1){
			flag=1;
		}
	}
	if(flag){
		printf("-1\n");
		return 0;
	}
	double x=m*1.0/(1.0*b[1]-1);
	for(int i=n;i>=1;i--){
		x+=(x+m)/(1.0*a[i]-1);
		if(i>1){
			x+=(x+m)/(1.0*b[i]-1);
		}
	}
//	if(x>1000000000.0){
//		printf("-1\n");
//	}
//	else
		printf("%.8lf\n",x);
	
	
	return 0;
}












