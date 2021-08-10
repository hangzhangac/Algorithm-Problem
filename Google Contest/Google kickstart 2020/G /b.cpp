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
const int MAXN=1005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[MAXN][MAXN];
int main(){
	int T;gi(T);
	int cnt=1;
	//cout<<T<<endl;
	while(T--){
		printf("Case #%d: ",cnt++);
		int n;
		cin>>n;
		queue< pair<int,int> >q;
		for(int i=1;i<=n;i++){
			q.push(make_pair(1,i));
			if(i>1)q.push(make_pair(i,1));
			for(int j=1;j<=n;j++){
				gi(a[i][j]);
			}
		}
		ll maxn=0;
		while(!q.empty()){
			ll cur=0;
			pair<int,int>p=q.front();
			q.pop();
			int x=p.first,y=p.second;
			while(x<=n&&y<=n){
				cur+=a[x][y];
				x++;y++;
			}
			maxn=max(maxn,cur);
		}
		cout<<maxn<<endl;
	}
	
	return 0;
}










