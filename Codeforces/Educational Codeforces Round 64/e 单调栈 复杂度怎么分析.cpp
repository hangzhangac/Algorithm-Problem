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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n,a[MAXN];
int l[MAXN],r[MAXN];
int book[MAXN];
stack<int>s;
int main(){
	
	gi(n);
	for(int i=1;i<=n;i++){
		gi(a[i]);
	}
	for(int i=1;i<=n;i++){
		l[i]=i-1;
		r[i]=i+1;
	}
	a[0]=a[n+1]=inf;

	s.push(1);
	for(int i=2;i<=n+1;i++){
		while(!s.empty()){
			if(a[s.top()]<a[i]){
				r[s.top()]=i;
				s.pop();
			}
			else break;
		}
		s.push(i);
	}
	while(!s.empty()){
		s.pop();
	}
	s.push(n);
	for(int i=n-1;i>=0;i--){
		while(!s.empty()){
			if(a[s.top()]<a[i]){
				l[s.top()]=i;
				s.pop();
			}
			else break;
		}
		s.push(i);
	}
	ll cnt=0;
	for(int i=1;i<=n;i++)book[a[i]]=i;
	
	for(int i=1;i<=n;i++){
		int ll=l[i]+1;
		int rr=r[i]-1;
		if(i-ll<rr-i){
			for(int j=ll;j<i;j++){
				int t=a[i]-a[j];
				if(t>=1&&t<=n&&book[t]>i&&book[t]<=rr){
					cnt++;
				}
			}
		}
		else{
			for(int j=i+1;j<=rr;j++){
				int t=a[i]-a[j];
				if(t>=1&&t<=n&&book[t]<i&&book[t]>=ll){
					cnt++;
				}
			}
		}
	}
	printf("%lld\n",cnt);

	return 0;
}








