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
const int MAXN=105;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n;
void copy(char a[MAXN][MAXN],char b[MAXN][MAXN]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=b[i][j];
		}
	}
}
char a[MAXN][MAXN];
char b[MAXN][MAXN];


int book[MAXN][MAXN][2];//0代表左上到右下 1代表右上到左下
vector< pair<int,int> >id[4*MAXN];
int vis[MAXN*4]; //true有黑有白 初始化别忘了
int ans=0;
int flag=0;
void dfs(int cur,int v){
	if(vis[cur]||flag==-1){
		flag=-1;
		return;
	}
	vis[cur]=1;
	ans++;
	for(int i=0;i<id[cur].size();i++){
		pair<int,int>p=id[cur][i];
		int x=p.first,y=p.second;
		if(a[x][y]=='#')a[x][y]='.';
		else a[x][y]='#';
		if(a[x][y]=='.'){
			dfs(book[x][y][v^1],v^1);
		}
	}
}
int judge(int x,int y,int v,int flag){
	int cnt=0,cntw=0;
	if(v==0){
		while(x>=1&&x<=n&&y>=1&&y<=n){
			if(a[x][y]=='.')cntw++;
			if(flag)a[x][y]='#';
			x++;y++;
			cnt++;
		}
		if(cntw==cnt){
			return cnt;
		}
		else return -1;
	}
	else{
		while(x>=1&&x<=n&&y>=1&&y<=n){
			if(a[x][y]=='.')cntw++;
			if(flag)a[x][y]='#';
			x++;y--;
			cnt++;
		}
		if(cntw==cnt){
			return cnt;
		}
		else return -1;
	}
}
int main(){
	int cnt11=1;
	int T;gi(T);while(T--){
		printf("Case #%d: ",cnt11++);
		gi(n);
		for(int i=1;i<=n;i++){
			scanf("%s",a[i]+1);
		}
		copy(b,a);
		int len=0;
		int q=0;
		for(int i=n;i>=1;i--){
			len++;
			int x=i,y=1;
			int cnt=0,cntb=0,cntw=0;
			while(x>=1&&x<=n&&y>=1&&y<=n){
				book[x][y][0]=len;
				id[len].push_back(make_pair(x, y));
				if(a[x][y]=='#')cntb++;
				else cntw++;
				cnt++;
				x++;y++;	
			}
			if(cntw!=0&&cntb!=0){
				vis[len]=1;
				q++;
			}
		}
		for(int i=2;i<=n;i++){
			len++;
			int x=1,y=i;
			int cnt=0,cntb=0,cntw=0;
			while(x>=1&&x<=n&&y>=1&&y<=n){
				book[x][y][0]=len;
				id[len].push_back(make_pair(x, y));
				if(a[x][y]=='#')cntb++;
				else cntw++;
				cnt++;
				x++;y++;	
			}
			if(cntw!=0&&cntb!=0){
				vis[len]=1;
				q++;
			}
		}
		
		for(int i=1;i<=n;i++){
			len++;
			int x=1,y=i;
			int cnt=0,cntb=0,cntw=0;
			while(x>=1&&x<=n&&y>=1&&y<=n){
				book[x][y][1]=len;
				id[len].push_back(make_pair(x, y));
				if(a[x][y]=='#')cntb++;
				else cntw++;
				cnt++;
				x++;y--;	
			}
			if(cntw!=0&&cntb!=0){
				vis[len]=1;
				q++;
			}
		}
		
		for(int i=2;i<=n;i++){
			len++;
			int x=i,y=n;
			int cnt=0,cntb=0,cntw=0;
			while(x>=1&&x<=n&&y>=1&&y<=n){
				book[x][y][1]=len;
				id[len].push_back(make_pair(x, y));
				if(a[x][y]=='#')cntb++;
				else cntw++;
				cnt++;
				x++;y--;	
			}
			if(cntw!=0&&cntb!=0){
				vis[len]=1;
				q++;
			}
		}
		if(q==0){
			if(a[1][1]=='#')printf("0\n");
			else printf("%d\n",2*n-1);
			for(int i=1;i<=len;i++)id[i].clear();
			for(int i=1;i<=len;i++)vis[i]=0;
			flag=0;
			ans=0;
			continue;
		}
		int pos=1;
		for(int i=1;i<=4*n-2;i++){
			if(vis[i]){
				pos=i;
				break;
			}
		}
		int xx=1,yy=1;
		for(int i=0;i<id[pos].size();i++){
			pair<int,int> p=id[pos][i];;
			int x=p.first,y=p.second;
			if(a[x][y]=='.'){
				xx=x,yy=y;break;
			}
		}
		for(int i=1;i<=len;i++)vis[i]=0;
		ans=0;
		int idx=book[xx][yy][0];
		dfs(idx,0);
		for(int i=1;i<=n;i++){
			if(flag==-1)break;
			for(int j=1;j<=n;j++){
				if(a[i][j]=='#')continue;
				ans++;
				int cnt1=judge(i,j,0,0);
				int cnt2=judge(i,j,1,0);
				if(cnt1==cnt2&&cnt1==-1){
					flag=-1;break;
				}
				else if(cnt1==-1){
					judge(i,j,1,1);
				}
				else if(cnt2==-1){
					judge(i,j,0,1);
				}
				else if(cnt1>=cnt2){
					judge(i,j,0,1);
				}
				else judge(i,j,1,1);
			}
			if(flag==-1)break;
		}
		if(flag==-1)ans=-1;
		int minn=ans;
		ans=0;
		copy(a,b);
		flag=0;
		for(int i=1;i<=len;i++)vis[i]=0;
		idx=book[xx][yy][1];
		dfs(idx,1);
		for(int i=1;i<=n;i++){
			if(flag==-1)break;
			for(int j=1;j<=n;j++){
				if(a[i][j]=='#')continue;
				ans++;
				int cnt1=judge(i,j,0,0);
				int cnt2=judge(i,j,1,0);
				if(cnt1==cnt2&&cnt1==-1){
					flag=-1;break;
				}
				else if(cnt1==-1){
					judge(i,j,1,1);
				}
				else if(cnt2==-1){
					judge(i,j,0,1);
				}
				else if(cnt1>=cnt2){
					judge(i,j,0,1);
				}
				else judge(i,j,1,1);
			}
			if(flag==-1)break;
		}
	
		if(minn==-1)printf("%d\n",ans);
		else if(flag==-1) printf("%d\n",minn);
		else printf("%d\n",min(minn,ans));
		for(int i=1;i<=len;i++)id[i].clear();
		for(int i=1;i<=len;i++)vis[i]=0;
		flag=0;
		ans=0;
	}
	return 0;
}














