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
const int MAXN=1000005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
string s;
int nex[MAXN][2];
int opr[MAXN];
int main(){
	int T;gi(T);while(T--){
		cin>>s;
		int n=s.size();
		pair<int,int> last[2]={{-1,0},{-1,0}};
		int cnt=0;
		for(int i=n-1;i>=0;i--){
			s[i]-='0';
			cnt+=s[i];
			nex[i][0]=last[0].first;
			nex[i][1]=last[1].first;
			if(last[0].second>last[1].second){
				opr[i]=1;
			}
			else opr[i]=0;
			last[s[i]].second=min(last[0].second,last[1].second)+1;
			last[s[i]].first=i;
			
		}
		
		if(cnt==n){
			cout<<0<<endl;
			continue;
		}
		int i=0;
//		while(i<n&&s[i]==0)i++;
//		if(i==n){
//			cout<<1<<endl;
//			continue;
//		}
		while(1){
			putchar(s[i]+'0');
			int t=opr[i];
			int id=nex[i][t];
			if(id==-1){
				putchar(t+'0');break;
			}
			i=id;
		}
		puts("");
	}
	
	return 0;
}