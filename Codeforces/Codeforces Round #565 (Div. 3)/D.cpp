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
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=2750135;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n;
int a[400005];
int book[MAXN];
int prime[MAXN];
int loc[MAXN];
int maxn=0;
vector<int>ans;
vector<int>pri;
void init(){
	pri.push_back(-1);
	int num=1;
	for(int i=2;i<MAXN;i++){
		if(prime[i]==0){
			for(int j=i*2;j<MAXN;j+=i){
				if(prime[j]==0){
					prime[j]=i;
				}
			}
			loc[i]=num++;
			//cout<<i<<' '<<loc[i]<<endl;
		}
	}
}

int main(){
	
	gi(n);
	
	for(int i=1;i<=2*n;i++){
		gi(a[i]);
		maxn=max(maxn,a[i]);
		book[a[i]]++;
	}
	init();
	for(int i=maxn;i>=2;i--){
		int t=book[i];
		if(t>0){
			if(prime[i]==0){
				int l=loc[i];
			//	cout<<i<<' '<<l<<endl;
				book[l]-=t;
				for(int j=0;j<t;j++){
					ans.push_back(l);
				}
			}
			else{
				int l=i/prime[i];
				book[l]-=t;
				for(int j=0;j<t;j++){
					ans.push_back(i);
				}
			}
		}
	}
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	
	
	
	return 0;
}

