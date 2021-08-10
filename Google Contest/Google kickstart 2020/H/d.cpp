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
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=50005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;

int a[26][26];
string s[MAXN];
int main(){
	
	int T,cnt1=1;gi(T);
	while(T--){
		for(int i=0;i<26;i++)for(int j=0;j<26;j++)if(i==j)a[i][j]=0;else a[i][j]=1e5;
		printf("Case #%d: ",cnt1++);
		int n,q;
		gi2(n,q);
		for(int i=1;i<=n;i++){
			cin>>s[i];
			for(int j=0;j<s[i].size();j++){
				for(int k=j+1;k<s[i].size();k++){
					if(s[i][j]==s[i][k])continue;
					int curx=s[i][j]-'A',cury=s[i][k]-'A';
					a[curx][cury]=1;
					a[cury][curx]=1;
				}
			}
		}
		for(int k=0;k<26;k++){
			for(int i=0;i<26;i++){
				for(int j=0;j<26;j++){
					if(a[i][j]>a[i][k]+a[k][j]){
						a[i][j]=a[i][k]+a[k][j];
					}
				}
			}
		}
		while(q--){
			int x,y;
			int ans=1e5;
			cin>>x>>y;
			string xx=s[x],yy=s[y];
			if(x==y){cout<<0<<' ';continue;}
			for(auto x:xx){
				for(auto y:yy){
					ans=min(ans,a[x-'A'][y-'A']+2);
				}
			}
			if(ans==1e5)cout<<-1<<' ';
			else cout<<ans<<' ';
		}
		cout<<endl;
		
		
	}
	
	
	
	return 0;
}








