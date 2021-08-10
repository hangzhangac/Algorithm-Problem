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
const int MAXN=400005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n;
int a[MAXN],b[MAXN];
int aa[MAXN],bb[MAXN];
int book[MAXN/2];
void init(){
	mem(book,0);
}
int cnt=0;
bool C(int mid){
	init();
	mid--;
	//cout<<mid<<endl;
	int sum=0;
	for(int i=1;i<=mid;i++){
		if(b[i]>0)sum++;
	}
	if(sum+n-cnt==n)return true;
	//int l=1,r=n;
	sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			sum++;
			book[a[i]]=1;
		}
	}

	for(int i=1;i<=mid;i++){
		if(b[i]>0){
			sum++;book[b[i]]=1;
		}
	}

	int l=mid+1,r=n+mid;
	int t=1;
	while(t<=n){
		if(book[t]){
			t++;
			book[b[l]]=1;
			l++;
		}
		else return false;
	}
	return true;
	
}
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	
	gi(n);
	int flag=true;
	
	for(int i=1;i<=n;i++){
		gi(a[i]);
		if(a[i]==0){
			cnt++;
			flag=false;
		}
	}
	if(flag){
		printf("%d\n",n);return 0;
	}
	for(int i=1;i<=n;i++)gi(b[i]);
	//C(1);
	int l=1,r=n+1;
	int ans=2*n;
	while(l<=r){
		int mid=(l+r)/2;
		if(C(mid)){
			ans=mid+n-1;
			r=mid-1;
		}
		else l=mid+1;
	}
	flag=-1;
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			flag=i-1;
			break;
		}
	}
	
	if(flag!=-1){
		for(int i=1;i<=n;i++){
			if(a[i]>0){
				q.push(a[i]);
			}
		}
		int l=1,r=n;
		int ff=true;
		for(int i=1;i<=flag;i++){
			if(q.empty()){
				ff=false;
				break;
			}
			r++;
			b[r]=q.top();
			q.pop();
			if(b[l]>0)q.push(b[l]);
			l++;
		}
		for(int i=flag+2;i<=r;i++){
			if(b[i]==b[i-1]+1){
				
			}
			else ff=false;
		}
		if(ff){
			ans=min(ans,flag);
		}
	}
	printf("%d\n",ans);
	return 0;
}