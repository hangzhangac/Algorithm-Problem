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
const int MAXN=300005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
typedef pair<int,int> P;
int n;
pair<int, pair<int,int> >a[MAXN];
//priority_queue< pair<int,int> ,vector<pair<int,int> >, greater< pair<int,int> > >p;
priority_queue< pair<int,int> >p;
vector< pair<int,int> >ans;
bool cmp(P x,P y){
	return a[x.second].first<a[y.second].first;
}
int main() {
	
	int T;gi(T);while(T--){
		ans.clear();
		gi(n);
		for(int i=1;i<=n;i++)gi(a[i].second.first);
		for(int i=1;i<=n;i++){
			gi(a[i].first);
			a[i].second.second=i;
		}
		sort(a+1,a+n+1);
		int cur=0;
		for(int i=1;i<=n;i++){
			int leave=a[i].first;
			int t=a[i].second.first;
			if(cur+t<=leave){
				cur+=t;
				p.push({t,i});
				continue;
			}
			else{
				if(p.empty())continue;
				auto v=p.top();
				if(v.first<=t)continue;
				if(cur-v.first+t<=leave){
					cur=cur-v.first+t;
					p.pop();
					p.push({t,i});
				}
			}
		}
		while(!p.empty()){
			ans.push_back(p.top());
			p.pop();
		}
		sort(ans.begin(),ans.end(),cmp);
		cout<<ans.size()<<endl;
		cur=0;
		for(int i=0;i<ans.size();i++){
			int id=ans[i].second;
			int t=ans[i].first;
			int ori_id=a[id].second.second;
			cout<<ori_id<<' '<<cur<<' '<<cur+t<<endl;
			cur+=t;
		}
	}
	return 0;
}