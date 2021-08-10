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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;

int sum[MAXN][6];
char s[MAXN];
string book[6]={"abc","acb","bac","bca","cab","cba"};
int main(){
	
	int n,m;
	gi2(n,m);
	scanf("%s",s);
	for(int j=0;j<6;j++){
		string tmp=book[j];
		for(int i=0;i<n;i++){
			if(i==0)sum[i][j]=0;
			else sum[i][j]=sum[i-1][j];
			if(tmp[i%3]!=s[i]){
				sum[i][j]++;
			}
		}
	}
	while(m--){
		int l,r;
		gi2(l, r);
		l--,r--;
		int ans=inf;
		for(int i=0;i<6;i++){
			int tmp=0;
			if(l-1>=0){
				tmp=sum[l-1][i];
			}
			int cur=sum[r][i]-tmp;
			ans=min(ans,cur);
		}
		printf("%d\n",ans);
	}
	
	
	return 0;
}







