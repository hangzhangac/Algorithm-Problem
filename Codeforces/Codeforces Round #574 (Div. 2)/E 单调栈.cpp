#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int MAXN=3002;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int c[MAXN][MAXN];
int q[MAXN];
int n,m;
int aa,bb;
typedef long long ll;
ll g,x,y,z;
int main(){
	
	scanf("%d%d%d%d",&n,&m,&aa,&bb);
	scanf("%lld%lld%lld%lld",&g,&x,&y,&z);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=g;
			g=(g*x+y)%z;
		}
	}
	for(int i=1;i<=n;i++){
		int l=1,r=0;
		for(int j=1;j<=m;j++){
			if(l<=r&&j-q[l]+1>bb){
				l++;
			}
			while(l<=r&&a[i][j]<=a[i][q[r]])r--;
			q[++r]=j;
			b[i][j]=a[i][q[l]];
		}
	}
	for(int j=1;j<=m;j++){
		int l=1,r=0;
		for(int i=1;i<=n;i++){
			if(l<=r&&i-q[l]+1>aa){
				l++;
			}
			while(l<=r&&b[i][j]<=b[q[r]][j])r--;
			q[++r]=i;
			c[i][j]=b[q[l]][j];
		}
	}
	ll ans=0;
	for(int i=aa;i<=n;i++){
		for(int j=bb;j<=m;j++){
			ans+=c[i][j];
		}
	}
	printf("%lld\n",ans);
	return 0;
}



