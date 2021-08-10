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
int n,a[MAXN],book[MAXN];
map<int,int>ms[MAXN];
queue<int>q;
int main(){
	
	gi(n);
	for(int i=1;i<=n-1;i++){
		int x,y;
		gi2(x,y);
		ms[x][y]=1;
		ms[y][x]=1;
	}
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	if(a[1]!=1){
		printf("No\n");
		return 0;
	}
	q.push(1);
	int cnt=1;
	int i=2;
	for(;;){
		int u=q.front();
		q.pop();
		while(i<=n&&ms[u][a[i]]){
			q.push(a[i]);
			cnt++;
			i++;
		}
		if(i>n||q.empty())break;
	}	
	if(cnt==n){
		printf("Yes\n");
	}
	else printf("No\n");
	
	return 0;
}







