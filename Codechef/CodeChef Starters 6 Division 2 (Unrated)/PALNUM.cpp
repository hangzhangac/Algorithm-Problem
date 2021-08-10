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
const int MAXN=100005;
const ll mod=1e9+7;
const ll inf=1e12;
using namespace std;
typedef pair<ll,int>P;
ll dis[10][10];
vector< P >cur;
void floyd(){
	
	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}
string s;
int32_t main(){
	
	int T;cin>>T;while(T--){
		int n,m,k;
		cur.clear();
		cin>>n>>m>>k;
		
		cin>>s;
		for(int i=0;i<=9;i++){
			for(int j=0;j<=9;j++){
				dis[i][j]=inf;
			}
		}
		for (int i = 0; i < 10; i++) dis[i][i] = 0;
		while(m--){
			int x,y;ll z;
			cin>>x>>y>>z;
			dis[x][y]=z;
		}
		floyd();
		ll sum=0;
		for(int i=0,j=s.size()-1;i<j;i++,j--){
			if(s[i]!=s[j]){
				int x=s[i]-'0',y=s[j]-'0';
				ll ans=inf;
				int pos=-1;
				for(int k1=9;k1>=0;k1--){
					if(ans>dis[x][k1]+dis[y][k1]){
						ans=dis[x][k1]+dis[y][k1];
						pos=k1;
					}
				}
				//if(ans==inf){flag=1;break;}
				sum+=ans;
				
				cur.push_back({ans,pos});
			}
			else{
				cur.push_back({0,0});
			}
		}
		if(sum>k){printf("-1\n");continue;}
		for(int i=0,j=s.size()-1;i<j;i++,j--){
			int x=s[i]-'0',y=s[j]-'0';
			sum-=cur[i].first;
			for(int k1=9;k1>=cur[i].second;k1--){
				ll tmp=dis[x][k1]+dis[y][k1];
				if(tmp>=inf)continue;
				if(sum+tmp<=k){
					s[i]='0'+k1;
					s[j]=s[i];
					sum+=tmp;
					break;
				}
			}
		}
		
		if(n&1){
			n/=2;
			for(int k1=9;k1>s[n]-'0';k1--){
				ll tmp=dis[s[n]-'0'][k1];
				if(tmp>=inf)continue;
				if(sum+tmp<=k){
					s[n]='0'+k1;
					sum+=tmp;
					break;
				}
			}
		}
		
		cout<<s<<endl;
		
	}

}















