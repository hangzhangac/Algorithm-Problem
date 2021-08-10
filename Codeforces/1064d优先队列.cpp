//https://www.cnblogs.com/markleaf/p/7808817.html
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
struct Node{
	int x,y,l,r;
	bool operator <(Node a)const{// 必须为const
		if(l==a.l)return r>a.r;
		return l>a.l;
	}
};
int n,m;
int sx,sy;
char a[2005][2005];
int x,y;
priority_queue<Node>q;
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
bool check(int x,int y){
	if(x<1||x>n||y<1||y>m||a[x][y]=='*')return false;
	return true;
}
void bfs(){
	Node e;
	e.x=sx,e.y=sy;e.l=0,e.r=0;
	q.push(e);
	a[sx][sy]='*';
	int cnt=1;
	while(!q.empty()){
		e=q.top();
		q.pop();
		for(int i=0;i<4;i++){
			int nx=e.x+dx[i];
			int ny=e.y+dy[i];
			if(!check(nx, ny))continue;
			Node s;
			s.x=nx,s.y=ny,s.l=e.l,s.r=e.r;
			if(i==0)s.l++;
			if(i==1)s.r++;
			if(s.l>x||s.r>y)continue;
			
			q.push(s);
			cnt++;
			a[nx][ny]='*';
		}
	}
	printf("%d\n",cnt);
}
int main(){
	cin>>n>>m;
	cin>>sx>>sy;
	cin>>x>>y;
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
	}
	
	bfs();
	return 0;
}


























