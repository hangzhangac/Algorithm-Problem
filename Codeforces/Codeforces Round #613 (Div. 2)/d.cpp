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
int a[MAXN][32];
int b[MAXN];
int dfs(int j,vector<int>cur){
	if(j==-1)return 0;
	int cnt[]={0,0};
	vector<int>ans1;
	vector<int>ans0;
	for(int i=0;i<cur.size();i++){
		cnt[a[cur[i]][j]]++;
		if(a[cur[i]][j]==0){
			ans0.push_back(cur[i]);
		}
		else ans1.push_back(cur[i]);
	}
	if(cnt[0]==0){
		return dfs(j-1,cur);
	}
	else if(cnt[1]==0){
		return dfs(j-1,cur);
	}
	else{
		return min(dfs(j-1,ans0)+(1<<j),dfs(j-1,ans1)+(1<<j));
	}
}
int main(){
	int n;
	gi(n);
	vector<int>ans;
	for(int i=1;i<=n;i++){
		ans.push_back(i);
		gi(b[i]);
		for(int j=0;j<30;j++){
			a[i][j]=b[i]&1;
			b[i]>>=1;
		}
	}
	cout<<dfs(29,ans)<<endl;
	return 0;
}