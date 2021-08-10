/*************************************************************************
	> File Name: tmp.cpp
    > Full Path: /Users/zhanghang/Downloads/tmp.cpp
	> Author: Hang Zhang
	> Created Time: 日  7/25 18:15:05 2021
 ************************************************************************/

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
int a[MAXN];
int dp[MAXN][2];
void del(multiset<int>&s,int val){
	auto iter=find(s.begin(),s.end(),val);
	s.erase(iter);
}
deque< pair<int,int> >s1,s2;
int main(){
	int T;cin>>T;while(T--){
		int n,k;
		gi2(n, k);
		for(int i=1;i<=n;i++)gi(a[i]);
		for(int i=1;i<=n;i++)dp[i][0]=dp[i][1]=inf;
		dp[1][0]=0;
		dp[1][1]=a[1];
		s1.clear();s2.clear();
		s1.push_back({0,0});
		s2.push_back({0,0});
		for(int i=1;i<=n;i++){
			//i i-1 i-2 i-3 ... i-k i-k-1
			while(i-k-1>=s1.front().second){
				s1.pop_front();
			}
			dp[i][0]=s1.front().first;
			while(i-k-2>=s2.front().second){
				s2.pop_front();
			}
			dp[i][1]=s2.front().first+a[i];
			while(s1.size()&&dp[i][1]<=s1.back().first){
				s1.pop_back();
			}
			while(s2.size()&&dp[i][1]<=s2.back().first){
				s2.pop_back();
			}
			s1.push_back({dp[i][1],i});
			s2.push_back({dp[i][1],i});
		}
		printf("%d\n",min(dp[n][1],dp[n][0]));
	}
	return 0;
}







