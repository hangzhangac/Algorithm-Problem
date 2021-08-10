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
const int MAXN=65;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
double dp[MAXN][MAXN][MAXN];
int nex[MAXN][MAXN][MAXN];
int main(){
	
	int T;int cnt1=1;gi(T);
	int x;gi(x);
	while(T--){
		for(int i=0;i<MAXN;i++){
			for(int j=0;j<MAXN;j++){
				for(int k=0;k<MAXN;k++){
					dp[i][j][k]=0.0;
				}
			}
		}
		double w,e;
		cin>>w>>e;
		dp[1][0][0]=(w+e)/3.0;
		
		dp[0][1][0]=(w+e)/3.0;
		dp[0][0][1]=(w+e)/3.0;
		nex[1][0][0]=0;
		nex[0][1][0]=1;
		nex[0][0][1]=2;
		nex[0][0][0]=-1;
		//s r p 0 1 2
		for(int all=2;all<=60;all++){
			for(int r=0;r<=all;r++){
				for(int s=0;s+r<=all;s++){
					int p=all-s-r;
					double m=all-1;
					if(p>=1){
						// s/all 出r  r/all 出p (p-1)/all 出s
						double tmp=dp[s][r][p-1]+e*r/all+w*s/all;
						if(dp[s][r][p]<tmp){
							dp[s][r][p]=tmp;
							nex[s][r][p]=2;
						}
					}
					if(r>=1){
						// s/all 出r  r-1/all 出p p/all 出s
						double tmp=dp[s][r-1][p]+e*s/all+w*p/all;
						if(dp[s][r][p]<tmp){
							dp[s][r][p]=tmp;
							nex[s][r][p]=1;
						}
					}
					if(s>=1){
						// s-1/all 出r  r/all 出p p/all 出s
						double tmp=dp[s-1][r][p]+e*p/all+w*r/all;
						if(dp[s][r][p]<tmp){
							dp[s][r][p]=tmp;
							nex[s][r][p]=0;
						}
					}
				}
			}
		}
		double maxn=0.0;
		int pp,ss,rr;
		for(int all=60;all<=60;all++){
			for(int r=0;r<=all;r++){
				for(int s=0;s+r<=all;s++){
					int p=all-r-s;
					if(dp[s][r][p]>maxn){
						maxn=dp[s][r][p];
						ss=s;rr=r;pp=p;
					}
				}
			}
		}
		map<int,char>ms;
		ms[0]='S';
		ms[1]='R';
		ms[2]='P';
		stack<char>sta;
		while(nex[ss][rr][pp]!=-1){
			int t=nex[ss][rr][pp];
			sta.push(ms[t]);
			if(t==0)ss--;
			else if(t==1)rr--;
			else{
				pp--;
			}
		}
		printf("Case #%d: ",cnt1++);
		while(sta.size()){
			cout<<sta.top();
			sta.pop();
		}
		cout<<endl;
	}
	return 0;
}