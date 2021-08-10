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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;

int n;
int f[MAXN];
int a[MAXN];
int find1(int x){
	if(x==f[x])return x;
	else return f[x]=find1(f[x]);
}
map<int,int>ms;
int main() {
	gi(n);
	for(int i=1;i<=n;i++){
		
		gi(a[i]);
	}
	for(int i=1;i<=200000;i++){
		f[i]=i;
	}
	for(int i=1;i<=n/2;i++){
		int j=n+1-i;
		if(a[i]==a[j]){
			continue;
		}
		int x=find1(a[i]),y=find1(a[j]);
		if(x==y)continue;
		f[x]=y;
	}
	for(int i=1;i<=200000;i++){
		int t=find1(i);
		ms[t]++;
	}
	auto it=ms.begin();
	int cnt=0;
	while(it!=ms.end()){
		int x=it->first;
		int num=it->second;
		cnt+=num-1;
		it++;
		//cout<<x<<' '<<num<<endl;
	}
	cout<<cnt<<endl;
	
	
	
	return 0;
	
}

















