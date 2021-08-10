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
const int MAXN=25;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
int n,m;
vector<int>G[MAXN];
vector<int>tmp[MAXN];
int book[MAXN];
vector<ll>ans;
int num[MAXN];
int mm[MAXN][MAXN];
int col[MAXN];
//ll q=0;
bool judge(int v,int j){
	for(auto x:tmp[v]){
		if(col[x]==j)return false;
	}
	return true;
}
void dfs(int u,vector<int>&a){
	for(auto v:G[u]){
		if(!book[v]){
			book[v]=1;
			a.push_back(v);
			dfs(v, a);
		}
	}
}
ll dfs(int u,int col1,int all,int cnt, vector<int>&a){
	if(u+1==all)return 1;
	col[a[u]]=col1;
	ll ans=0;
	for(int j=1;j<=3;j++){
		if(judge(a[u+1], j)){
			ans+=dfs(u+1,j,all,cnt,a);
		}
	}
	col[a[u]]=0;
	return ans;
}
int main() {
	
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		gi2(a,b);
		G[a].push_back(b);
		G[b].push_back(a);
		mm[a][b]=mm[b][a]=1;
	}
	for(int i=1;i<=n;i++){
		vector<int>a;
		if(book[i])continue;
		book[i]=1;
		a.push_back(i);
		dfs(i,a);
		for(int j=1;j<=n;j++){
			tmp[i].clear();
		}
		for(int j=0;j<a.size();j++){
			for(int k=j+1;k<a.size();k++){
				if(mm[a[j]][a[k]]){
					tmp[a[j]].push_back(a[k]);
					tmp[a[k]].push_back(a[j]);
				}
			}
		}
		ll q=0;
		for(int j=1;j<=3;j++){
			q+=dfs(0, j, a.size(), 0,a);
		}
		ans.push_back(q);
	}
	ll sum=1;
	for(int i=0;i<ans.size();i++){
		sum*=ans[i];
	}
	cout<<sum<<endl;
	return 0;
}










//#include<bits/stdc++.h>
//#define pb push_back
//const int N=20;
//int n,m,col[N];
//std::vector<int>e[N];
//long long ans;
//void dfs(int dep,long long coef){
//	if(dep==n)return void(ans+=coef);
//	if(e[dep].empty())dfs(dep+1,coef*3LL);
//	else{
//		for(int i=0;i<3;++i){
//			bool flag=1;
//			for(auto v:e[dep])if(col[v]==i){flag=0;break;}
//			if(flag)col[dep]=i,dfs(dep+1,coef),col[dep]=-1;
//		}
//	}
//}
//int main(){
//	scanf("%d%d",&n,&m);
//	memset(col,-1,sizeof(col));
//	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),--x,--y,e[x].pb(y),e[y].pb(x);
//	dfs(0,1),printf("%lld\n",ans);
//	return 0;
//}
//







