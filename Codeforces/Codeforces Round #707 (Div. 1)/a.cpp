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
const int MAXN=200005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;
vector<int>book[5000005];
int n;
pair<int,int>a[MAXN];
int main(){
	gi(n);
	for(int i=1;i<=n;i++){
		gi(a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	if(n<=2500){
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int t=a[i].first+a[j].first;
				if(book[t].size()){
					if(book[t][0]==i||book[t][0]==j){
						continue;
					}
					if(book[t][1]==i||book[t][1]==j){
						continue;
					}
					cout<<"YES\n";
					cout<<a[book[t][0]].second<<' '<<a[book[t][1]].second;
					cout<<' '<<a[i].second<<' '<<a[j].second;
					return 0;
				}
				else{
					book[t].push_back(i);
					book[t].push_back(j);
				}
			}
		}
		
		cout<<"NO\n";
		return 0;
	}
	int cnt=1;
	for(int i=2;i<=n;i++){
		if(a[i].first==a[i-1].first){
			cnt++;
		}
		else{
			cnt=1;
		}
		int s=a[i].first-a[i-1].first;
		if(book[s].size()){
			if(book[s][1]==a[i-1].second){
				continue;
			}
			else{
				cout<<"YES\n";
				cout<<book[s][1]<<' '<<a[i-1].second<<' ';
				cout<<a[i].second<<' '<<book[s][0]<<endl;
				return 0;
			}
		}
		book[s].push_back(a[i-1].second);
		book[s].push_back(a[i].second);
	}
	cout<<"NO\n";
	return 0;
}





















