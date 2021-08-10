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
int a[MAXN];
int t[MAXN];
int ff[MAXN];
int main(){
	
	int T;gi(T);while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ff[i]=0;
		}
		int cnt1=0;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				cnt1++;
			}
		}
		if(cnt1==n-1){
			cout<<1<<endl;
			for(int i=1;i<=n;i++){
				cout<<1;
				cout<<(i==n?'\n':' ');
			}
			continue;
		}
		int cnt=1;
		t[1]=1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				t[i]=t[i-1];
			}
			else{
				int flag=0;
				for(int j=1;j<=cnt;j++){
					if(t[i-1]!=j){
						t[i]=j;
						flag=1;
						break;
					}
				}
				if(!flag)t[i]=++cnt;
			}
		}
		if(t[n]==t[1]&&a[n]!=a[1]){
			int flag=0;
			for(int i=2;i<=n;i++){
				ff[i]=ff[i]|ff[i-1];
				if(ff[i])continue;
				if(a[i]==a[i-1]){
					ff[i]=1;
					flag=1;
				}
			}
			if(flag){
				cout<<cnt<<endl;
				for(int i=1;i<=n;i++){
					if(ff[i]){
						if(t[i]==1)t[i]=2;
						else t[i]=1;
					}
				}
				for(int i=1;i<=n;i++){
					cout<<t[i];
					cout<<(i==n?'\n':' ');
				}
				continue;
				
			}
			flag=0;
			int q;
			if(a[n]!=a[n-1]){
				q=t[n-1];
			}
			else{
				q=-1;
			}
			for(int j=1;j<=cnt;j++){
				if(t[1]!=j&&j!=q){
					t[n]=j;
					flag=1;
					break;
				}
			}
			if(!flag)t[n]=++cnt;
		}
		cout<<cnt<<endl;
		for(int i=1;i<=n;i++){
			cout<<t[i];
			cout<<(i==n?'\n':' ');
		}
	}
	
	
	return 0;
}

