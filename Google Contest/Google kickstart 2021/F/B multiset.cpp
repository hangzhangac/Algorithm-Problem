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

multiset<int>s1;
multiset<int, greater<int> >s2;
pair<int,pair<int,int> >a[MAXN];
vector<int>G[2][MAXN];
int main(int argc, char *argv[]) {
	int T,cnt1=1;gi(T);
	while(T--){
		s1.clear();s2.clear();
		printf("Case #%d: ",cnt1++);
		int d,n,k;
		cin>>d>>n>>k;
		for(int i=1;i<=d+1;i++){
			G[0][i].clear();
			G[1][i].clear();
		}
		
		for(int i=1;i<=n;i++){
			gi(a[i].second.second);
			gi2(a[i].first, a[i].second.first);
			a[i].second.first++;
			G[0][a[i].second.first].push_back(a[i].second.second);
			G[1][a[i].first].push_back(a[i].second.second);
		}
		
		sort(a+1, a+n+1);
		ll sum=0,num=0;
		ll maxn=0;
		for(int i=1;i<=d;i++){
			
			for(auto v:G[0][i]){
				auto it=s2.find(v);
				if(it!=s2.end()){
					s2.erase(it);
					continue;
				}
				it = s1.find(v);
				s1.erase(it);
				sum-=v;
				if(s2.size()){
					s1.insert(*s2.begin());
					sum+=*s2.begin();
					s2.erase(s2.begin());
				}
			}
			
			for(auto v:G[1][i]){
				if(s1.size()<k){
					s1.insert(v);
					sum+=v;
				}
				else{
					if(*s1.begin()>=v){
						s2.insert(v);
					}
					else{
						int t=*s1.begin();
						s1.erase(s1.begin());
						s1.insert(v);
						s2.insert(t);
						sum-=t;
						sum+=v;
					}
				}
			}
			
			maxn=max(maxn,sum);
		}
		printf("%lld\n",maxn);
	}
	
}