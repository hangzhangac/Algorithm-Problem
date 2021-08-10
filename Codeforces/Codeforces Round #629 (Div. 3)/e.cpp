#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int n,m,s,num=0,head[MAXN],dep[MAXN],f[MAXN][23];
int fa[MAXN];
int a1,a2;
struct edg{
	int next,to;
}edge[MAXN*2];
void edge_add(int u,int v)//链式前向星存图 
{
	num++;
	edge[num].next=head[u];edge[num].to=v;head[u]=num;
	edge[++num].next=head[v];edge[num].to=u;head[v]=num;
}
void dfs(int u,int father)//对应深搜预处理f数组 
{
	dep[u]=dep[father]+1;
	fa[u]=father;
	for(int i=1;(1<<i)<=dep[u];i++)
	{
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(int i=head[u];i;i=edge[i].next)
	{
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
	for(int i=1;i<=n;i++){
		head[i]=0;
	}
}
bool cmp(int a,int b){
	return dep[a]>dep[b];
}
int main(){
	scanf("%d%d",&n,&m);
	int root=1;
	init();
	for(int i=1;i<n;i++){
		scanf("%d",&a1);scanf("%d",&a2);
		edge_add(a1,a2);//链式存边 
	}
	dfs(root,0);
	vector<int>ans;
	for(int i=1;i<=m;i++){
		int k;scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x;scanf("%d",&x);
			x=fa[x];
			if(x)ans.push_back(x);
		}
		sort(ans.begin(),ans.end(),cmp);
		int flag=1;
		for(int j=1;j<ans.size();j++){
			int x=ans[j-1],y=ans[j];
			if(lca(x, y)==y)continue;
			flag=0;break;
		}
		if(flag)puts("YES");
		else puts("NO");
		ans.clear();
	}
}