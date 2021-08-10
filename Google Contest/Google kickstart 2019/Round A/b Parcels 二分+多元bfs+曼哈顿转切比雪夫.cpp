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
const int MAXN=255;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char a[MAXN][MAXN];
bool book[MAXN][MAXN];
vector<int>xx;
vector<int>yy;
int n,m;
typedef pair<int,int> P;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool judge(int k){
	int minn[3]={inf,inf};
	int maxn[3]={-inf,-inf};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!book[i][j]){
				//cout<<i<<j<<endl;
				maxn[0]=max(maxn[0],i+j);
				maxn[1]=max(maxn[1],i-j);
				minn[0]=min(minn[0],i+j);
				minn[1]=min(minn[1],i-j);
			}
		}
	}
	int ans=inf;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int maxn1=max(abs(maxn[0]-(i+j)),abs(minn[0]-(i+j)));
			int maxn2=max(abs(maxn[1]-(i-j)),abs(minn[1]-(i-j)));
			int maxn3=max(maxn1,maxn2);
			ans=min(maxn3,ans);
			if(ans<=k)return true;
		}
	}
	return false;
}
bool C(int k){
	mem(book,0);
	int cnt=0;
	queue< pair<P,int> >q;
	for(int i=0;i<xx.size();i++){
		int x=xx[i],y=yy[i];
		book[x][y]=1;
		q.push(make_pair( make_pair(x,y),0 ));
		cnt++;
	}
	while(!q.empty()){
		pair<P,int>p=q.front();
		q.pop();
		int x=p.first.first;
		int y=p.first.second;
//		if(k==3){
//			cout<<x<<' '<<y<<endl;
//		}
		int step=p.second;
		if(step==k)continue;
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<1||nx>n||ny<1||ny>m||book[nx][ny])continue;
			book[nx][ny]=1;
			cnt++;
			q.push(make_pair(make_pair(nx,ny),step+1));
		}
	}
	if(cnt>=n*m-1)return true;
	if(judge(k)) return true;
	return false;
}
int main(){
	int T;
	gi(T);
	int cnt=1;
	while(T--){
		gi2(n,m);
		xx.clear();yy.clear();
		int num=0;
		for(int i=1;i<=n;i++){
			scanf("%s",a[i]+1);
			for(int j=1;j<=m;j++){
				if(a[i][j]=='1'){
					xx.push_back(i);
					yy.push_back(j);
					num++;
				}
			}
		}
		printf("Case #%d: ",cnt++);
		if(num>=n*m-1){
			printf("0\n");
			continue;
		}
		int l=0,r=n+m-2;
		int ans=-1;
		while(l<=r){
			int mid=(l+r)/2;
			//cout<<1<<endl;
			//cout<<mid<<endl;
			if(C(mid)){
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		printf("%d\n",ans);		
	}
	return 0;
}








