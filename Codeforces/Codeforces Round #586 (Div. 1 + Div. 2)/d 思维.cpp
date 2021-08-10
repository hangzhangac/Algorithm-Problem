#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <time.h>
#include <map>
#include <set>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n;
ll a[MAXN],b[MAXN];
int book[MAXN];
vector<int>ans;
vector<int>ans1;
int main(){
	gi(n);
	for(int i=1;i<=n;i++){
		gll(a[i]);
		b[i]=a[i];
	}
	int maxn=0;
	while(1){
		int cnt=0;
		int flag=0;
		ans1.clear();
		for(int i=1;i<=n;i++){
			if(book[i])continue;
			if(a[i]&1){
				cnt++;
				book[i]=1;
				ans1.push_back(i);
			}
			else{
				flag=1;
				a[i]/=2;
			}
		}
		if(maxn<cnt){
			maxn=cnt;
			ans=ans1;
		}
		if(!flag)break;
		
	}
	printf("%d\n",n-maxn);
	mem(book,0);
	for(auto v:ans){
		book[v]=1;
	}
	for(int i=1;i<=n;i++){
		if(!book[i]){
			printf("%lld ",b[i]);
		}
	}
	return 0;
}
