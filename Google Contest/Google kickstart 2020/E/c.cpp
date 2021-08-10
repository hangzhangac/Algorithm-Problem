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
const int MAXN=100005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;
int n;
struct Node{
	int e,r,id;
}node[MAXN],node1[MAXN];
bool operator<(Node a,Node b){
	return a.e+a.r<b.e+b.r;
}
priority_queue<Node>q;
ll c[MAXN];
int lowbit(int k){
	return k&(-k);
}
ll getsum(int i){
	ll sum=0;
	while(i>0){
		sum+=c[i];
		i-=lowbit(i);
	}
	return sum;
}
bool cmp(Node a,Node b){
	return a.e+a.r>b.e+b.r;
}
void update(int i,int j){
	while(i<=n){
		c[i]+=j;
		i+=lowbit(i);
	}
}
int main(){
	int T;gi(T);
	int cnt1=1;
	while(T--){
		//cout<<1<<endl;
		gi(n);
		ll sum=0,tmp=0,ans=0;
		int cur=1;
		printf("Case #%d: ",cnt1++);
		for(int i=0;i<=n;i++)c[i]=0;
		for(int i=1;i<=n;++i){
			gi2(node[i].e,node[i].r);
			node1[i]=node[i];
			sum+=node[i].e;
			node[i].id=i;
		}
		tmp=sum;
		sort(node1+1,node1+n+1,cmp);
		for(int i=1;i<=n;++i){
			if(node1[i].e+node1[i].r>sum){
				sum-=node1[i].e;
				ans++;
			}
		}
		if(ans<n){
			printf("%lld INDEFINITELY\n",ans);
			continue;
		}
		sum=tmp;
		while(!q.empty())q.pop();
		ll maxn=sum;
		ll cur_time=sum;
		int num=0;
		int cnt=0;
		for(int i=1;i<=n;++i){
			q.push(node[i]);
			cur_time+=node[i].e;
			while(!q.empty()&&q.top().e+q.top().r>sum){
				cur_time-=2*q.top().e;
				sum-=q.top().e;
				q.pop();
				cnt++;
			}
			if(cur_time>maxn){
				maxn=cur_time;
				num=cnt;
			}
		}
		printf("%d %lld\n",num,maxn);
	}
	return 0;
}













