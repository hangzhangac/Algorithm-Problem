#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 2005;
int sum[N][N], n;
char s[N][N];
void update(int x, int y, int m){
	sum[x][y]+=m;
}
int main()
{
	int n,k;
	int cnt=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		int flag=0;
		for(int j=1;j<=n;j++){
			if(s[i][j]=='B'){
				flag=1;break;
			}
		}
		if(!flag)cnt++;
	}
	for(int j=1;j<=n;j++){
		int flag=0;
		for(int i=1;i<=n;i++){
			if(s[i][j]=='B'){
				flag=1;break;
			}
		}
		if(!flag)cnt++;
	}
	for(int j=1;j<=n;j++){
		int y=j,xx=0,x=n+1;
		for(int i=1;i<=n;i++){
			if(s[i][j]=='B'){
				xx=max(xx,i);
				x=min(x,i);
			}
		}
		if(x==n+1)continue;
		if(xx-x+1<=k){
			int x1=xx-k+1;
			int y11=y-k+1;
			x1=max(1,x1);
			y11=max(y11,1);
			int x2=x,y2=y;
			update(x1, y11, 1);
			update(x1, y2+1, -1);
			update(x2+1, y11, -1);
			update(x2+1, y2+1, 1);
		}
		
	}
	for(int i=1;i<=n;i++){
		int x=i,yy=0,y=n+1;
		for(int j=1;j<=n;j++){
			if(s[i][j]=='B'){
				yy=max(yy,j);
				y=min(y,j);
			}
		}
		if(y==n+1)continue;
		if(yy-y+1<=k){
			int x1=x-k+1;
			int y11=yy-k+1;
			x1=max(1,x1);
			y11=max(y11,1);
			int x2=x,y2=y;
			update(x1, y11, 1);
			update(x1, y2+1, -1);
			update(x2+1, y11, -1);
			update(x2+1, y2+1, 1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum[i][j]=sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			ans=max(ans,sum[i][j]);
		}
	}
	printf("%d\n",ans+cnt);
		
	
	return 0;
}