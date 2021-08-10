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
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n,m;
int a[MAXN];
struct Node{
	int val;
	int id;
	int pri;
}b[MAXN];
vector<int>ans1[1<<9];
vector<Node>ans[1<<9];
int book[1<<9];
void dfs(int id,int cur){
	if(book[cur])return;
	book[cur]=1;
	ans1[id].push_back(cur);
	for(int i=0;i<9;i++){
		int t=1<<i;
		if((t&cur)==0){
			dfs(id,cur|t);
		}
	}
}
bool cmp(Node a,Node b){
	if(a.val>b.val)return a.pri<b.pri;
	return a.val>b.val;
}
int main(){
	gi2(n,m);
	for(int i=1;i<=n;i++){
		int t,res=0;
		gi(t);
		while(t--){
			int x;gi(x);
			x--;
			res|=(1<<x);
		}
		a[i]=res;
	}
	for(int i=1;i<=m;i++){
		int t,res=0;
		gi(b[i].pri);
		gi(t);
		while(t--){
			int x;gi(x);
			x--;
			res|=(1<<x);
		}
		b[i].val=res;
		b[i].id=i;
		if(ans[res].size()<=1){
			ans[res].push_back(b[i]);
		}
		else{
			for(int j=0;j<2;j++){//记录两个价格最小的
				if(ans[res][j].pri>b[i].pri){
					swap(b[i], ans[res][j]);
				}
			}
		}
	}
	for(int i=1;i<=(1<<9)-1;i++){//这里的book数组代表i已经被搜过了,不需要再搜了
		mem(book,0);
		dfs(i,i);
	}
	mem(book,0);//这里的book[i]代表有多少人可以被成分为i的pizza满足
	for(int i=1;i<=n;i++){
		for(int j=0;j<ans1[a[i]].size();j++){
			int t=ans1[a[i]][j];
			book[t]++;
			
		}
	}
	int maxn=-1;
	int p=inf;
	int ii,jj;
	for(int i=0;i<(1<<9);i++){
		for(int j=0;j<(1<<9);j++){
			for(int k=0;k<ans[i].size();k++){
				for(int q=0;q<ans[j].size();q++){
					if(i==j&&k==q)continue;
					int t1=ans[i][k].val,t2=ans[j][q].val;			
					int t=t1|t2;
					if(book[t]>maxn){
						maxn=book[t];
						ii=ans[i][k].id;
						jj=ans[j][q].id;
						p=ans[i][k].pri+ans[j][q].pri;
					}
					else if(book[t]==maxn){
						if(p>ans[i][k].pri+ans[j][q].pri){
							p=ans[i][k].pri+ans[j][q].pri;
							ii=ans[i][k].id;
							jj=ans[j][q].id;
						}
					}
				}
			}
		}
	}
	printf("%d %d\n",ii,jj);
	return 0;
}