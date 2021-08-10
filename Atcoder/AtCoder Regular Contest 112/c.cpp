/*************************************************************************
	> File Name: c.cpp
    > Full Path: /Users/zhanghang/Desktop/c.cpp
	> Author: Hang Zhang
	> Created Time: 六  2/13 21:53:25 2021
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<stack>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;
int p[MAXN];
vector<int>G[MAXN];
int a[MAXN],turn[MAXN],son[MAXN];
int dfs(int u){
	int good=0,bad=0;
	a[u]=1;
	son[u]=0;
	turn[u]=1;
	vector<int>ans;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		son[u]+=dfs(v);
		if(!(son[v]&1)){
			if(a[v]>0)good+=a[v];
			else bad+=a[v];
		}
		else{
			ans.push_back(a[v]);
		}
	}
	sort(ans.begin(),ans.end());
	a[u]+=bad;

	if(!(ans.size()&1)){
		a[u]+=good;
	}
	else{
		a[u]-=good;
	}
	for(int i=0;i<ans.size();i++){
		if(i&1)a[u]-=ans[i];
		else a[u]+=ans[i];
	}
	return son[u]+=1;
}


int main(){
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		G[x].push_back(i);
	}
	dfs(1);
	cout<<(n+a[1])/2<<endl;

}












