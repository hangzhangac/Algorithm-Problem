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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
vector<int>G[MAXN];
int in[MAXN];
int book[MAXN];
int n,m,k;
int cnt=0;
int x[MAXN];
int y[MAXN];
queue<int>q;
void dag(){
	
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			
			in[v]--;
			if(in[v]<k){
				if(!book[v]){
					q.push(v);
					cnt++;
				}
				book[v]=1;
			}
		}
	}
}
vector<int>ans;
int main(){
	
	
	gi3(n, m, k);
	int qq=m;
	while(qq--){
		gi2(x[qq+1],y[qq+1]);
		G[x[qq+1]].push_back(y[qq+1]);
		G[y[qq+1]].push_back(x[qq+1]);
		in[x[qq+1]]++;in[y[qq+1]]++;
	}
	for(int i=1;i<=n;i++){
		if(in[i]<k){
			q.push(i);
			cnt++;
			book[i]=true;
		}
	}
	dag();
	ans.push_back(n-cnt);
	int pre=n-cnt;
	for(int i=1;i<m;i++){
		G[x[i]].pop_back();
		G[y[i]].pop_back();
		if(book[x[i]]||book[y[i]]){
			ans.push_back(pre);
		}
		else{
			in[x[i]]--;
			in[y[i]]--;
			if(in[x[i]]<k){q.push(x[i]);cnt++;book[x[i]]=1;}
			if(in[y[i]]<k){q.push(y[i]);cnt++;book[y[i]]=1;}
			dag();
			ans.push_back(n-cnt);
			pre=n-cnt;
		}
	}
	for(int i=m-1;i>=0;i--){
		printf("%d\n",ans[i]);
	}
	return 0;
}































