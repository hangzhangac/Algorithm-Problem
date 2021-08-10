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
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int r,c,l1,r1,l2,r2;
double lg[MAXN];
vector<double>ans;
void add(int nx,int ny){
	int n=nx+ny;
	ans.push_back(lg[n]-lg[nx]-lg[n-nx]-n);
}
int main(){
	lg[0]=0;
	for (int i=1;i<2e5+1;i++) {
		lg[i]=lg[i-1]+log2(i);
	}
	int cnt1=1;
	int T;gi(T);while(T--){
		ans.clear();
		cin>>r>>c>>l1>>r1>>l2>>r2;
		printf("Case #%d: ",cnt1++);
		if((l2-l1+1==r)||(r2-r1+1==c)){
			printf("0.0\n");
			continue;
		}
		int y=r1-1;
		if(y>=1){
			int t=l2,flag=0;
			if(l2==r){
				flag=1;t--;
			}
			for(int l=l1;l<=t;l++){
				int nx=l-1,ny=y-1;
				add(nx,ny);
			}
			if(flag){
				for(int i=1;i<=y;i++){
					add(r-2,i-1);
				}
			}
		}
		int x=l1-1;
		if(x>=1){
			int t=r2,flag=0;
			if(r2==c){
				flag=1;t--;
			}
			for(int r=r1;r<=t;r++){
				int nx=x-1,ny=r-1;
				add(nx,ny);
			}
			if(flag){
				for(int i=1;i<=x;i++){
					add(i-1,c-2);
				}
			}
		}
		double sum=0.0;
		for(int i=0;i<ans.size();i++){
			sum+=pow(2, ans[i]);
		}
		sum/=2.0;
		printf("%.7lf\n",1.0-sum);
	}
	return 0;
}