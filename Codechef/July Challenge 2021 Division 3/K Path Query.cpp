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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
int n,root,num=0,head[MAXN],dep[MAXN],f[MAXN][23];
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
	for(int i=1;(1<<i)<=dep[u];i++)
	{
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
	for(int i=1;i<=n;i++){
		head[i]=0;
		dep[i]=0;
		for(int j=0;j<=20;j++){
			f[i][j]=0;
		}
	}
}
vector<int>query;
bool cmp(int a,int b){
	return dep[a]<dep[b];
}
bool judge(vector<int>& query,int r){
	int last[2]={r,r};
	for(auto x: query){
		int flag=1;
		for(int i=0;i<2;i++){
			if(lca(x,last[i])==last[i]){
				flag=0;
				last[i]=x;
				break;
			}
		}
		if(flag){
			return false;
		}
		int t=lca(last[0],last[1]);
		if(t!=r&&t!=last[0]&&t!=last[1]){
			return false;
		}
	}
	return true;
}
int main(int argc, char *argv[]) {
	int T;gi(T);while(T--){
		gi(n);
		init();
		root=1;
		for(int i=1;i<n;i++){
			int u,v;
			gi2(u, v);
			edge_add(u, v);
		}
		dfs(root, 0);
		int q;gi(q);
		while(q--){
			int k;gi(k);
			query.clear();
			int r=-1;
			for(int i=1;i<=k;i++){
				int x;gi(x);
				query.push_back(x);
				if(i==1)r=x;
				else{
					r=lca(x, r);
				}
			}
			sort(query.begin(),query.end(),cmp);
			if(judge(query, r)){
				printf("YES\n");
			}
			else printf("NO\n");
		}
		
	}

	return 0;
}