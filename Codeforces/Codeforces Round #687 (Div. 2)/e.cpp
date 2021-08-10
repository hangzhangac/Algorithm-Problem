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
const int MAXN=500005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;

vector<int>a,b;
ll sum[MAXN];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int n,k;
	gi2(n,k);
	for(int i=0;i<n;i++){
		int x;gi(x);
		a.push_back(x);
	}
	sort(a.begin(),a.end(),cmp);
	ll bb=0,ans=0;
	int i=0;
	while(i<n&&(bb+a[i]>=0||k==0)){
		ans+=bb;
		bb+=a[i];
		i++;
	}
	if(k!=0&&i!=n)
		ans+=bb;
	for(int j=n-1;j>=i;j--){
		b.push_back(a[j]);
	}
	k++;
	int t=b.size();
	if(t==0){
		cout<<ans<<endl;
		return 0;
	}
	vector<int>head;
	ll base=0;
	for(int i=0;i<b.size();i++){
		int cur_col=i/k;
		base+=1LL*cur_col*b[i];
	}
	ll maxn=base;
	for(int i=0;i<b.size();i+=k){
		head.push_back(b[i]);
	}
	sum[0]=head[0];
	for(int i=1;i<head.size();i++)sum[i]=sum[i-1]+head[i];
	for(int i=0;i<b.size();i++){
		int cur_col=i/k;
		int insert_col=upper_bound(head.begin(), head.end(), b[i]+bb)-head.begin()-1;
		maxn=max(maxn,base-1LL*b[i]*cur_col+1LL*(b[i]+bb)*cur_col-sum[insert_col]+sum[cur_col]+(b[i]+bb)*(insert_col-cur_col));
	}
	cout<<maxn+ans<<endl;
	return 0;
}
























