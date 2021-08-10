/*************************************************************************
	> File Name: e.cpp
    > Full Path: /Users/zhanghang/Downloads/e.cpp
	> Author: Hang Zhang
	> Created Time: 三  4/28 14:59:02 2021
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
const int MAXN=105;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;

struct Matrix
{
	ll ma[MAXN][MAXN];
	int n;
	Matrix(int n):n(n){ //nn is the dimension of matrix
		memset(ma,0,sizeof ma);
	}
};
Matrix mul(Matrix A,Matrix B,long long mod)
{
	int n=A.n;
	Matrix C(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				C.ma[i][j]=(C.ma[i][j]+A.ma[i][k]*B.ma[k][j])%mod;
			}
		}
	}
	return C;
}
Matrix pow_mod(Matrix A,long long k, long long mod)
{
	int n=A.n;
	Matrix B(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			B.ma[i][j]=0;
		}
		B.ma[i][i]=1;
	}
	while(k)
	{
		if(k&1) B=mul(B,A,mod);
		A=mul(A,A,mod);
		k>>=1;
	}
	return B;
}


long long quick_pow(long long a, long long b, long long mod) {
	a %= mod;
	long long res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
int a[MAXN];
vector<int>G[MAXN];
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		x--;y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	ll tmp=quick_pow(m*2LL,1LL*mod-2,mod);
	Matrix t(n);
	for(int i=0;i<n;i++){
		int d=G[i].size();
		t.ma[i][i]=((1LL-tmp*d%mod)%mod+mod)%mod;
		for(auto v:G[i]){
			t.ma[i][v]=tmp;
		}
	}
	Matrix e=pow_mod(t,k,mod);
	for(int i=0;i<n;i++){
		ll ans=0;
		for(int j=0;j<n;j++){
			ans+=e.ma[i][j]*a[j];
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	

	return 0;
}
