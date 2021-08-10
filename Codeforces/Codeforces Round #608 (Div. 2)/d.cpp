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
const int MAXN=5005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int maxn[MAXN];
int n,m,k;
int a[MAXN],b[MAXN],c[MAXN];
vector<int>s[MAXN];
void init(){
	for(int i=1;i<=n;i++){
		maxn[i]=i;
	}
}
priority_queue<int,vector<int>, greater<int> > q;
bool cmp(int i,int j){
	return c[i]>c[j];
}
int main(){
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=n;i++){
		gi3(a[i],b[i],c[i]);
	}
	for(int i=1;i<=m;i++){
		int u,v;
		gi2(u,v);
		maxn[v]=max(maxn[v],u);
	}
	for(int i=1;i<=n;i++){
		int t=maxn[i];
		s[t].push_back(i);
	}
	for(int i=1;i<=n;i++){
		sort(s[i].begin(),s[i].end(),cmp);
	}
	int k1=k;
	for(int i=1;i<=n;i++){
		if(k1<a[i]){
			printf("-1\n");
			return 0;
		}
		k1+=b[i];
	}
	for(int i=1;i<=n;i++){
		while(k<a[i]){
			q.pop();
			k++;
		}
		k+=b[i];
		for(int j=0;j<s[i].size();j++){
			if(k==0)break;
			k--;
			q.push(c[s[i][j]]);
		}
	}
	int ans=0;
	while(!q.empty()){
		ans+=q.top();
		q.pop();
	}
	printf("%d\n",ans);
	
	
	return 0;
}














