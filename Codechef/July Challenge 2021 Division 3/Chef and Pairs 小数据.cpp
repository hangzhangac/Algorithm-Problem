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
int v[11];
int n,root,num=0,head[MAXN],dep[MAXN],f[MAXN][23];
struct edg{
	int next,to;
}edge[MAXN<<1];
void edge_add(int u,int v)//链式前向星存图 双向加边
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
	int cnt=0;
	if(x==y)return 0;
	for(int i=20;i>=0;i--)//从大到小枚举使x和y到了同一层
	{
		if(dep[f[x][i]]>=dep[y]){x=f[x][i];cnt+=(1<<i);}
		if(x==y)return cnt;
	}
	for(int i=20;i>=0;i--)//从大到小枚举
	{
		if(f[x][i]!=f[y][i])//尽可能接近
		{
			x=f[x][i];y=f[y][i];
			cnt+=(1<<(i+1));
		}
	}
	cnt+=2;
	//return f[x][0];//随便找一个**输出
	return cnt;
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
int main() {
	int T;gi(T);
	while(T--){
		root=1;
		int q;
		gi2(n, q);
		init();
		for(int i=1;i<n;i++){
			int u,v;
			gi2(u, v);
			edge_add(u, v);
		}
		dfs(root, 0);
		while(q--){
			int k,d;
			gi2(k, d);
			for(int i=1;i<=k;i++){
				gi(v[i]);
			}
			int cnt=0;
			for(int i=1;i<=k;i++){
				for(int j=i+1;j<=k;j++){
					if(v[i]>n||v[i]<1||v[j]>n||v[j]<1)continue;
					if(lca(v[i], v[j])==d){
						cnt++;
					}
				}
			}
			printf("%d\n",cnt);
		}
		
	}
	
	return 0;
}





