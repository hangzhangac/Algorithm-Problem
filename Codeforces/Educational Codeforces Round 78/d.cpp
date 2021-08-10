#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>
#define lson i<<1
#define rson i<<1|1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define gc(x) scanf("%c",&x)
#define gc2(x,y) scanf("%c%c",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const double PI = acos(-1.0); 
const int MAXN=500005;
const ll mod=1e7+9;
const ll llinf = (ll)(1e18) + 500;
const int inf=0x3f3f3f3f;
int f[MAXN];
int n;
int find1(int x){
	if(x==f[x])return x;
	return f[x]=find1(f[x]);
}
void init(){
	for(int i=1;i<=n;i++)f[i]=i;
}
pair<int,int>a[MAXN];
set< pair<int,int> >s; //first是坐标的y second是坐标的编号
int main(){
 
	//freopen("in.txt","r",stdin); 
	gi(n);
	init();
	for(int i=1;i<=n;i++){
		int x,y;
		gi2(x,y);
		a[i].first=x;
		a[i].second=y;
	}
	int ans=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int x=a[i].first,y=a[i].second;
		set< pair<int,int> >::iterator it,it1,it2;
		it1=s.lower_bound(make_pair(x,0));
		it2=s.lower_bound(make_pair(y,0));
		for(it=it1;it!=it2;it++){
			pair<int,int >tmp=(*it);
			int fx=find1(tmp.second),fy=find1(i);
			if(fx==fy){
				printf("NO\n");return 0;
			}
			f[fx]=fy;
			ans++;
		}
		s.insert(make_pair(y,i));
 
	}
	if(ans!=n-1){
		printf("NO\n");
	}
	else printf("YES\n");
	return 0;
}
 
 