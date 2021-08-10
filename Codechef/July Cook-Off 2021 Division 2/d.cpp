#include <iostream>
using namespace std;
const int maxn=1005;
int a[maxn];
int dp[maxn][maxn];
int cnt[maxn][maxn];
int m[maxn];
int main(){
    
    int t;cin>>t;while(t--){
        int n,k;cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=1000;i++){
            for(int j=0;j<=k;j++)cnt[i][j]=0;
        }
        for(int i=0;i<=k;i++){
            m[i]=0;
        }
        int mx=0;
        for(int i=1;i<=n;i++){
            
            //cout<<m[0]<<endl;
            for(int j=k;j>=1;j--){
                //if(cnt[a[i]][j]!=0)
                dp[i][j]=max(dp[i][j],cnt[a[i]][j]+1);
                dp[i][j]=max(dp[i][j], m[j-1]+1);
                m[j]=max(m[j],dp[i][j]);
                cnt[a[i]][j]=max(cnt[a[i]][j],dp[i][j]);
                mx=max(mx,dp[i][j]);
            }
            dp[i][0]=cnt[a[i]][0]+1;
            mx=max(mx,dp[i][0]);
            cnt[a[i]][0]++;
            int t=cnt[a[i]][0];
            m[0]=max(m[0],t);
        }
        cout<<mx<<endl;
        
        
    }
    return 0;
}
