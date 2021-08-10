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
#include <stack>
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
struct Node{
	int x,y;
}node[5];
int book[1005][1005];
int vis[1005][1005];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
pair<int,int>pre[1005][1005];

bool cmp(Node a,Node b){
	if(a.x!=b.x)return a.x<b.x;
	return a.y<b.y;
}
queue<pair<int,int> >q;
vector<int>ans1,ans2;
int main(){
	int n=3;
	mem(pre,-1);
	for(int i=0;i<3;i++){
		cin>>node[i].x>>node[i].y;
	}
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=1000;j++){
			pre[i][j].first=pre[i][j].second=-1;
		}
	}
	sort(node,node+n,cmp);
	q.push(make_pair(node[2].x, node[2].y));
	
	int x=node[0].x,y=node[0].y;
	while(x!=node[1].x){
		//printf("%d %d\n",x,y);
		ans1.push_back(x);
		ans2.push_back(y);
		book[x][y]=1;
		x++;
	}
	while(y!=node[1].y){
		//printf("%d %d\n",x,y);
		ans1.push_back(x);
		ans2.push_back(y);
		book[x][y]=1;
		if(y<node[1].y)
			y++;
		else{
			y--;
		}
	}
	ans1.push_back(x);
	ans2.push_back(y);
	book[x][y]=1;
	int cnt=0;
	vis[node[2].x][node[2].y]=1;
	while(!q.empty()){
//		cnt++;
//		if(cnt>=100)break;
		pair<int,int>p=q.front();
		q.pop();
		if(book[p.first][p.second]){
			//cout<<p.first<<' '<<p.second<<endl;
			int cnt1=0;
			while(pre[p.first][p.second].first!=-1){
				cnt1++;
				//if(cnt1>=10)break;
				ans1.push_back(pre[p.first][p.second].first);
				ans2.push_back(pre[p.first][p.second].second);
			//	printf("%d %d\n",pre[p.first][p.second].first,pre[p.first][p.second].second);
				p=pre[p.first][p.second];
			}
			break;
		}
		for(int i=0;i<4;i++){
			int x=p.first+dx[i];
			int y=p.second+dy[i];
			if(x>=0&&x<=1000&&y>=0&&y<=1000&&!vis[x][y]){
				pre[x][y]=make_pair(p.first, p.second);
				vis[x][y]=1;
				q.push(make_pair(x, y));
			}
		}
	}
	printf("%lu\n",ans1.size());
	for(int i=0;i<ans1.size();i++){
		printf("%d %d\n",ans1[i],ans2[i]);
	}
	return 0;
}































