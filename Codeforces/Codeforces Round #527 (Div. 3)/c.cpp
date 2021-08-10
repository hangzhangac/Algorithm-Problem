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
vector<string>G[105];
vector<int>id[105];
int vis[105][2];
int ans[105];
int book[205];
int cnt=0;
int n;
int f=0;
void dfs(int cur,string pre){
	//cout<<1<<endl;
	if(cur==n){
		//cout<<pre<<endl;
		if(vis[1][0]){
			pre+=G[1][1];
		}
		else{
			pre+=G[1][0];
		}
		//cout<<pre<<endl;
		int flag=0;
		for(int cur=2;cur<=n-1;cur++){
			for(int i=0;i<G[cur].size();i++){
				if(!vis[cur][i]){
					for(int j=pre.size()-1,k=G[cur][i].size()-1;k>=0;j--,k--){
						if(pre[j]!=G[cur][i][k]){
							flag=1;
							break;
						}
					}
				}
			}
			if(flag)break;
		}
		if(!flag){f=1;}
		return ;
	}
	if(f==1)return;
	for(int i=0;i<G[cur].size();i++){
		if(f==1)return;
		string a=G[cur][i];
		int flag=1;
		for(int j=0;j<pre.size();j++){
			if(pre[j]!=a[j]){
				flag=0;break;
			}
		}
		if(flag){
			ans[cnt++]=id[cur][i];
			vis[cur][i]=1;
			dfs(cur+1, a);
			if(f==1)return;
			vis[cur][i]=0;
			cnt--;
		}
	}
}
int main(){
	
	
	cin>>n;
	string a;
	for(int i=1;i<=n*2-2;i++){
		cin>>a;
		G[a.size()].push_back(a);
		id[a.size()].push_back(i);
	//	cout<<a<<endl;
	}
	dfs(1,"");
	for(int i=0;i<cnt;i++){
		book[ans[i]]=1;
	}
	for(int i=1;i<=2*n-2;i++){
		if(book[i]){
			printf("P");
		}
		else printf("S");
	}
	return 0;
}