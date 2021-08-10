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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n;
int a[MAXN];
vector<int>q[MAXN];
int book[MAXN];
int flag[MAXN];
int main(){
	
	gi(n);
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	mem(flag,-1);mem(book,-1);
	int T;
	gi(T);
	for(int i=1;i<=T;i++){
		int t,p,x;
		gi(t);q[i].push_back(t);
		if(t==1){
			gi2(p,x);q[i].push_back(p);
			q[i].push_back(x);
		}
		else{
			gi(x);
			q[i].push_back(x);
		}
	}
	int maxn=-1;
	for(int i=T;i>=1;i--){
		if(q[i][0]==1){
			int p=q[i][1],x=q[i][2];
			if(flag[p]==-1){
				flag[p]=max(maxn,q[i][2]);
			}
		}
		else{
			maxn=max(maxn,q[i][1]);
		}
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==-1){
			flag[i]=max(a[i],maxn);
		}
		printf("%d ",flag[i]);
	}
	return 0;
}