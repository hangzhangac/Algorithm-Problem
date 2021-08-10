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
const int MAXN=505;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char a[MAXN][MAXN];
int cnt=0;
	int n,m;
bool judge(int q,int p){
	int x=q-1,y=p;
	int c=1;
	int cc=0;
	while(x>=1&&a[x][y]=='*'){
		cc++;
		x--;
	}
	c+=cc;
	if(cc==0)return false;
	x=q+1;cc=0;
	while(x<=n&&a[x][y]=='*'){
		cc++;
		x++;
	}
	c+=cc;
	if(cc==0)return false;
	x=q;y=p-1;cc=0;
	while(y>=1&&a[x][y]=='*'){
		cc++;
		y--;
	}
	c+=cc;
	if(cc==0)return false;
	y=p+1;cc=0;
	while(y<=m&&a[x][y]=='*'){
		cc++;
		y++;
	}
	c+=cc;
	if(cc==0)return false;
	if(c!=cnt)return false;
	return true;
	
}
int main(){

	gi2(n,m);
	int flag=true;
	int xx=-1;
	int yy=-1;
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
		for(int j=1;j<=m;j++){
			if(a[i][j]=='*'){
				cnt++;
			}
		}
	}
	for(int i=2;i<=n-1;i++){
		for(int j=2;j<=m-1;j++){
			if(a[i][j]=='*'&&a[i-1][j]=='*'&&a[i+1][j]=='*'&&a[i][j-1]=='*'&&a[i][j+1]=='*'){
				if(judge(i,j)){
					printf("YES\n");

				}
				else printf("NO\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	
	
	
	return 0;
	
}
