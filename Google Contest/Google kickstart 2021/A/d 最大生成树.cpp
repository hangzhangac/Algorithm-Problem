#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=505;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int d[MAXN][MAXN];
int n;
int c[MAXN];
int r[MAXN];

struct Node{
	int x,y;
	int val;
}node[MAXN*MAXN];
int f[MAXN*2];
bool cmp(Node a,Node b){
	return a.val>b.val;
}
int find1(int x){
	if(x==f[x])return x;
	return f[x]=find1(f[x]);
}
int main() {
	
	int cnt=1;
	int T;gi(T);while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				gi(a[i][j]);
			}
		}
		int num=0;
		ll sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				gi(b[i][j]);
				sum+=b[i][j];
				if(b[i][j]){
					++num;
					node[num].x=i;
					node[num].y=j+n;
					node[num].val=b[i][j];
				}
			}
		}
		for(int i=1;i<=n;i++)gi(r[i]);
		for(int j=1;j<=n;j++)gi(c[j]);
		
		sort(node+1,node+num+1,cmp);
		for(int i=1;i<=2*n;i++){
			f[i]=i;
		}
		for(int i=1;i<=num;i++){
			int x=node[i].x;
			int y=node[i].y;
			int fx=find1(x),fy=find1(y);
			if(fx==fy){
				continue;
			}
			sum-=node[i].val;
			f[fx]=fy;
		}
		printf("Case #%d: ",cnt++);
		cout<<sum<<endl;
	}
}