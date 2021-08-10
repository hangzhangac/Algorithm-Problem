/*************************************************************************
	> File Name: f.cpp
    > Full Path: /Users/zhanghang/Desktop/f.cpp
	> Author: Hang Zhang
	> Created Time: 二  3/ 9 22:41:03 2021
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<stack>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll dp[MAXN][17];
int a[MAXN];
string s;
int main(){
	
	cin>>s;
	int k;
	cin>>k;
	int n=s.size();
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[i+1]=s[i]-'0';
		}
		else a[i+1]=s[i]-'A'+10;
	}
	int flag=1,mask=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=16;j++){
			dp[i][j]+=dp[i-1][j]*j%mod;
			if(j<=15){
				dp[i][j+1]+=dp[i-1][j]*(16-j)%mod;	
			}
		}
		if(!flag)dp[i][1]+=15;	
		for(int x=flag?1:0;x<a[i];x++){
			int num=__builtin_popcount(mask|(1<<x));
			dp[i][num]++;
		}	
		mask|=1<<a[i];
		flag=0;
	}
	dp[n][__builtin_popcount(mask)]++;
	cout<<dp[n][k]%mod<<endl;
	return 0;
}