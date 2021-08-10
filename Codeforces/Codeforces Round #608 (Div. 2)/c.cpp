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
pair<int,int>node[MAXN];
int maxn=1e9;
int minn=0;
int n;
int cal(int x,int y,int flag){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(flag==0){
			if(node[i].second>=y){
				cnt++;
			}
		}
		else if(flag==1){
			if(node[i].second<=y){
				cnt++;
			}
		}
		else if(flag==2){
			if(node[i].first>=x){
				cnt++;
			}
		}
		else{
			if(node[i].first<=x){
				cnt++;
			}
		}
	}
	return cnt;
}
int main(){
	int x,y;
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		node[i].first=x;
		node[i].second=y;
	}
	int dx[]={0,0,1,-1};
	int dy[]={1,-1,0,0};
	int ans=0;
	int ansx=0,ansy=0;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0&&nx<=maxn&&ny>=0&&ny<=maxn){
			int t=cal(nx,ny,i);
			if(ans<=t){
				ans=t;
				ansx=nx,ansy=ny;
			}
		}
	}
	printf("%d\n",ans);
	printf("%d %d\n",ansx,ansy);
	
	
	
	
	
	return 0;
}














