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
const int MAXN=1000000+10;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
int dp[MAXN][3];
vector<int>G[MAXN];
int init(){
    for(int i=1;i<MAXN;i++){
        int x=1;
        while(x*i<MAXN){
            G[x*i].push_back(i);
            x++;
        }
    }
    for(int i=0;i<MAXN;i++){
        
        for(int k=0;k<G[i].size();k++){
            int j=G[i][k];
            if(j!=1&&i/j>=3){
                int t=i/j-1;
                dp[i][1]=max(dp[i][1],dp[t][1]+1);
            }
            if(j>=3&&i/j>=3){
                int t=i/j-1;
                dp[i][2]=max(dp[i][2],dp[t][1]+1);
            }
        }
        dp[i][1]=max(dp[i][1],1);
        dp[i][2]=max(dp[i][2],1);
    }
    return 1;
}
int main(){
    
    int T,cnt1=1;gi(T);
    init();
    while(T--){
        int n;
        cin>>n;
        printf("Case #%d: ",cnt1++);
        cout<<dp[n][2]<<endl;
    }
    return 0;
}