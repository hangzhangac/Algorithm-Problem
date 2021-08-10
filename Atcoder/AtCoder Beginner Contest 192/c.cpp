#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
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
const int MAXN=100005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;
int flag=0;
ll trans(vector<int>ans){
	ll a=0;
	for(int i=0;i<ans.size();i++){
		a*=10;
		a+=ans[i];
	}
	//cout<<a<<endl;
	return a;
}
bool cmp(int a,int b){
	return a>b;
}
ll f(ll a){
	vector<int>ans;
	while(a){
		ans.push_back(a%10);
		//cout<<a%10<<endl;
		a/=10;
		
	}
	sort(ans.begin(),ans.end(),cmp);
	ll aa=trans(ans);
	sort(ans.begin(),ans.end());
	aa-=trans(ans);
	return aa;
}
ll a[MAXN];
int main(){
	
	ll n;int k;
	cin>>n>>k;
	a[0]=n;
	for(int i=1;i<=k;i++){
		if(i==1)flag=1;
		else flag=0;
		a[i]=f(a[i-1]);
	}
	cout<<a[k]<<endl;
	return 0;
}













