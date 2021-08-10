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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
struct Node{
	int x,y;
	int d;
}node[MAXN];
bool cmp(Node a,Node b){
	return a.d>b.d;
}
int pos[MAXN*2];
vector< pair<int,int> >ans;
int main(){
	
	int n;
	gi(n);
	for(int i=1;i<=n;i++){
		gi(node[i].d);
		node[i].x=2*i-1;
		node[i].y=2*i;
	}
	int maxn=n,cnt=1;
	sort(node+1,node+n+1,cmp);
	for(int i=1;i<=n;i++){
		while(pos[cnt])cnt++;
		pos[cnt]=node[i].x;
		if(cnt+node[i].d==maxn+1){
			pos[maxn+1]=node[i].y;
			maxn++;
		}
		else{
			ans.push_back(make_pair(cnt+node[i].d-1,node[i].y));
		}
	}

	for(int i=1;i<maxn;i++){
		ans.push_back(make_pair(i,pos[i+1]));
	}
	for(auto v:ans){
		printf("%d %d\n",pos[v.first],v.second);
	}
	return 0;
}









