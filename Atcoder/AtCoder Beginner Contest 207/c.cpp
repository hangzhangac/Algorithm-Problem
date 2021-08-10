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
struct Node{
	int t;
	double l,r;
	
}node[2005];
bool cmp(Node a,Node b){
//	if(a.l==b.l)return a.r==b.r;
//	return a.l<b.l;
	return a.t<b.t;
}
bool judge(Node a,Node b){
	if(b.l>=a.l&&b.l<=a.r)return true;
	if(b.r>=a.l&&b.r<=a.r)return true;
	return false;
}
int main() {
	gi(n);
	for(int i=1;i<=n;i++){
		cin>>node[i].t>>node[i].l>>node[i].r;
		if(node[i].t==2){
			node[i].r-=0.1;
		}
		else if(node[i].t==3){
			node[i].l+=0.1;
		}
		else if(node[i].t==4){
			node[i].l+=0.1;
			node[i].r-=0.1;
		}
		//cout<<node[i].l<<' '<<node[i].r<<endl;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(judge(node[i],node[j])||judge(node[j], node[i])){
				cnt++;
				//cout<<i<<' '<<j<<endl;
			}
		}
	}
	cout<<cnt<<endl;
	
	
	return 0;
}
















