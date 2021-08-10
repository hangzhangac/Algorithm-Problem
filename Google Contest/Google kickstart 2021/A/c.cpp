#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=305;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
int a[MAXN][MAXN];
priority_queue< pair<int, pair<int,int> > >p;
int book[MAXN][MAXN];
int main() {
	
	int cnt=1;
	int T;gi(T);while(T--){
		int n,m;
		cin>>n>>m;
		while(!p.empty()){
			p.pop();
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				book[i][j]=0;
				cin>>a[i][j];
				p.push(make_pair(a[i][j], make_pair(i, j)));
			}
		}
		ll ans=0;
		int idx[]={0,0,-1,1};
		int idy[]={1,-1,0,0};
		while(!p.empty()){
			pair<int, pair<int,int> > e=p.top();
			p.pop();
			int h=e.first;
			int curx=e.second.first;
			int cury=e.second.second;
			if(book[curx][cury])continue;
			book[curx][cury]=1;
			for(int i=0;i<4;i++){
				int nx=curx+idx[i];
				int ny=cury+idy[i];
				if(nx>n||nx<1||ny>m||ny<1)continue;
				if(book[nx][ny])continue;
				if(a[nx][ny]>=h-1)continue;
				ans+=(h-1)-a[nx][ny];
				a[nx][ny]=h-1;
				p.push(make_pair(a[nx][ny], make_pair(nx, ny)));
			}
		}
		printf("Case #%d: ",cnt++);
		cout<<ans<<endl;
	}
	
	return 0;
}
















