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
int num[10];
pair<ll,ll> cmp(string a,string b){
	ll aa=0,bb=0;
	int book[10];
	memset(book,0,sizeof book);
	for(int i=0;i<a.size();i++){
		book[a[i]-'0']++;
	}
	for(int i=1;i<=9;i++){
		int t=book[i];
		ll ans=1;
		while(t--){
			ans*=10;
		}
		aa+=i*ans;
	}
	memset(book,0,sizeof book);
	for(int i=0;i<a.size();i++){
		book[b[i]-'0']++;
	}
	for(int i=1;i<=9;i++){
		int t=book[i];
		ll ans=1;
		while(t--){
			ans*=10;
		}
		bb+=i*ans;
	}
	return make_pair(aa,bb);
}
int main(){
	
	string a,b;
	int k;
	cin>>k;
	cin>>a>>b;
	a[4]=b[4]='0';
	pair<ll,ll>e=cmp(a, b);
	ll ina=e.first,inb=e.second;
	ll inc=inb-ina;
	for(int i=1;i<=9;i++){
		num[i]=k;
	}
	for(int i=0;i<4;i++){
		num[a[i]-'0']--;
		num[b[i]-'0']--;
	}
	ll sum=k*9-8;
	double ans=0.0;
	for(int i=1;i<=9;i++){
		if(!num[i])continue;
		double proi=1.0*num[i]/sum;
		num[i]--;
		a[4]=i+'0';
		
		for(int j=1;j<=9;j++){
			if(!num[j]){
				continue;
			}
			double proj=1.0*num[j]/(sum-1);
			b[4]=j+'0';
			e=cmp(a,b);
			ll naa=e.first,nbb=e.second;
			if(naa>nbb){
				ans+=proi*proj;
			}
		}
		num[i]++;
	}
	printf("%.7lf",ans);
	
	return 0;
}


