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
int in[MAXN];
bool del[MAXN];
vector<int>G[MAXN];
int n,k;
int bfs(){
	queue<pair<int,int>>q;
	int num=0,cnt=n;
	for(int i=1;i<=n;i++){
		if(in[i]==1){
			num++;
			q.push({i,1});
		}
	}
	if(k==1||k==2)return k;
	int ans=num;
	while(!q.empty()){
		pair<int,int> cur=q.front();q.pop();
		int u=cur.first;
		int len=cur.second;
		del[u]=true;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(del[v]==true)continue;
			in[v]--;
			if(in[v]==1){
				q.push({v,len+1});
			}
			else{
				num--;
				cnt-=len;
				if(cnt>=k){
					ans=num;
				}
			}
		}
		if(cnt<k)break;
	}
	return max(ans,2);
}
int main() {
	int T;gi(T);
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)in[i]=0,del[i]=false;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			in[u]++;in[v]++;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cout<<bfs()<<endl;
		for(int i=1;i<=n;i++)G[i].clear();
	}
	return 0;
}
/*
10
7 5
1 2
2 3
3 4
3 5
5 6
3 7
6 4
1 2
1 3
1 4
1 5
1 6
3 1
1 2
2 3
4 1
1 2
2 3
3 4
5 5
1 2
2 3
2 4
2 5
7 5
1 2
2 3
3 4
3 5
5 6
3 7
6 4
1 2
1 3
1 4
1 5
1 6
3 1
1 2
2 3
4 1
1 2
2 3
3 4
5 2
1 2
2 3
2 4
2 5

*/







