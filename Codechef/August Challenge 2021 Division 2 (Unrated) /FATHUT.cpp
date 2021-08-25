#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>
#include <stack>
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
struct Node{
	int a,c,l,r;
}node[MAXN];
bool cmp(Node a,Node b){
	return a.c<b.c;
}
vector<int>tmp;
int main(int argc, char *argv[]) {
	
	int T;gi(T);while(T--){
		tmp.clear();
		int n;
		gi(n);
		for(int i=1;i<=n;i++){
			gi2(node[i].a, node[i].c);
			gi2(node[i].l, node[i].r);
		}
		sort(node+1, node+n+1,cmp);
		int maxl=0;
		int flag=0;
		
		for(int i=1;i<=n;i++){
			if(maxl>=node[i].r){
				flag=1;
				break;
			}
			
			while(tmp.size()&&tmp.back()>=node[i].r){
				tmp.pop_back();
			}
			auto it=lower_bound(tmp.begin(), tmp.end(), node[i].a);
			if(node[i].a>maxl)
			if(it==tmp.end())tmp.push_back(node[i].a);
			else *it=node[i].a;
			maxl=max(maxl,node[i].l);
		}
		if(flag){
			cout<<"-1"<<endl;
		}
		else{
			cout<<n-tmp.size()<<endl;
		}
		
	}
	
	return 0;
}