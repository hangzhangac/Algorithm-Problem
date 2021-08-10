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
int a[MAXN];
int col[MAXN];
queue<int>q[4];
queue<int>row;
vector< pair<int,int> >ans;
typedef pair<int, int> P;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		row.push(i);
		q[a[i]].push(i);
	}
	int flag=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<4;j++){
			if(!q[j].empty()&&q[j].front()==i){
				q[j].pop();break;
			}
		}
		if(a[i]==1){
			if(col[i]==1)continue;
			if(row.empty()){
				flag=1;break;
			}
			int r=row.front();
			row.pop();
			ans.push_back(P(r,i));
		}
		else if(a[i]==2){
			if(row.empty()){
				flag=1;break;
			}
			int r=row.front();
			row.pop();
			if(q[1].empty()){
				flag=1;break;
			}
			int c=q[1].front();
			q[1].pop();
			col[c]=1;
			ans.push_back(P(r,i));
			ans.push_back(P(r,c));
		}
		else if(a[i]==3){
			if(row.empty()){
				flag=1;break;
			}
			int r=row.front();
			row.pop();
			ans.push_back(P(r,i));
			int c=n+1;
			int id=-1;
			for(int j=1;j<=3;j++){
				if(!q[j].empty()){
					if(c>q[j].front()){
						c=q[j].front();
						id=j;
					}
				}
			}
			if(c==n+1){
				flag=1;break;
			}
			q[id].pop();
			ans.push_back(P(r,c));
		}
	}
	if(flag){
		printf("-1\n");
	}
	else{
		int n=ans.size();
		cout<<n<<endl;
		for(int i=0;i<n;i++){
			printf("%d %d\n",ans[i].first,ans[i].second);
		}
	}
	
	return 0;
}










