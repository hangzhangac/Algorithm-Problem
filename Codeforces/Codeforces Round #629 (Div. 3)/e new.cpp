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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
int n,m,root=1,num=0,head[MAXN],dep[MAXN],f[MAXN][23];
struct edg{
	int next,to;
}edge[MAXN<<1];
void edge_add(int u,int v)//链式前向星存图
{
	num++;
	edge[num].next=head[u];edge[num].to=v;head[u]=num;
	edge[++num].next=head[v];edge[num].to=u;head[v]=num;
}
void dfs(int u,int father)//对应深搜预处理f数组
{
	dep[u]=dep[father]+1;
	for(int i=1;(1<<i)<=dep[u];i++){
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==father)continue;//双向图需要判断是不是父亲节点
		f[v][0]=u;
		dfs(v,u);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--)//从大到小枚举使x和y到了同一层
	{
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
		if(x==y)return x;
	}
	for(int i=20;i>=0;i--)//从大到小枚举
	{
		if(f[x][i]!=f[y][i])//尽可能接近
		{
			x=f[x][i];y=f[y][i];
		}
	}
	return f[x][0];//随便找一个**输出
}
void init(){
	num=0;
	dep[0]=-1;
	for(int i=1;i<=n;i++){
		head[i]=0;
		for(int j=0;j<=20;j++){
			f[i][j]=0;
		}
	}
	
}
vector<int>q;
bool cmp(int x,int y){
	return dep[x]>dep[y];
}
int distance(int x,int y){
	int l=lca(x, y);
	return dep[x]+dep[y]-2*dep[l];
}
bool judge(vector<int>&q){
	if(q.size()==1)return true;
	int tar=f[q[0]][0];
	int t=dep[tar];
	for(int i=1;i<q.size();i++){
		if(distance(q[i], tar)+distance(q[i], 1)<=t+2)continue;
		return false;
	}
	return true;
}
int main(int argc, char *argv[]) {
	
	
	gi2(n, m);
	init();
	for(int i=1;i<n;i++){
		int u,v;
		gi2(u, v);
		edge_add(u,v);
	}
	dfs(1,0);
	while(m--){
		int k;gi(k);
		int x;
		q.clear();
		for(int i=1;i<=k;i++)gi(x),q.push_back(x);
		sort(q.begin(),q.end(),cmp);
		if(judge(q))puts("YES");
		else puts("NO");
	}
	
	
	return 0;
}


