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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;

int d[MAXN];
struct edge{
	int to,cost;
};
typedef pair<int,int>P;
vector<edge>G[MAXN];
int dij(int s,int t,int n){
	priority_queue<P, vector<P>, greater<P> >que;
	fill(d, d+n+1, inf);
	d[s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		P p=que.top();que.pop();
		int v=p.second;
		if (d[v]<p.first)continue;
		if(v==t)break;
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			if(d[e.to]>d[v]+1){
				d[e.to]=d[v]+1;
				que.push(P(d[e.to],e.to));
			}
		}
	}
	if(d[t]==inf)return -1;
	return d[t];
}
int handle(int x){
	if(x==0)return 1;
	vector<int>a;
	while(x){
		a.push_back(x&1);
		x/=2;
	}
	for(int i=0;i<a.size();i++){
		a[i]^=1;
	}
	int ans=0;
	int base=1;
	for(int i=0;i<a.size();i++){
		ans+=a[i]*base;
		base*=2;
	}
	return ans;
}
int trans(string s){
	int ans=0;
	for(int i=0;i<s.size();i++){
		ans*=2;
		ans+=s[i]-'0';
	}
	return ans;
}

map<string,int>ms;
string double_solve(string u){
	if(u.size()>=200)return "";
	if(u=="0")return u;
	return u+"0";
}
string not_solve(string u){
	for(int i=0;i<u.size();i++){
		if(u[i]=='0')u[i]='1';
		else u[i]='0';
	}
	string ans="";
	int i=0;
	while(i<u.size()&&u[i]=='0')i++;
	if(i==u.size())return "0";
	while(i<u.size()){
		ans+=u[i];
		i++;
	}
	return ans;
}
bool bfs(string s,string t){
	queue<string>q;
	ms[s]=1;
	int cnt=0;
	q.push(s);
	while((!q.empty())&&cnt<1000000){
		string u=q.front();
		q.pop();
		
		if(u==t)return true;
		
		cnt++;
		string nex=double_solve(u);
		if(nex==""||ms[nex]);
		else{
			q.push(nex);
			ms[nex]=ms[u]+1;
		}
		nex=not_solve(u);
		if(nex==""||ms[nex]);
		else{
			q.push(nex);
			ms[nex]=ms[u]+1;
		}
	}
	return ms[t]!=0;
}
int main(){
	
	int maxx=(1<<15);
	for(int i=0;i<maxx;i++){
		int t=2*i;
		if(t<maxx){
			edge e;e.to=t;e.cost=1;
			G[i].push_back(e);
		}
		t=handle(i);
		if(t<maxx){
			edge e;e.to=t;e.cost=1;
			G[i].push_back(e);
		}
	}
	int T,cnt1=1;gi(T);while(T--){
		string ss,tt;
		cin>>ss>>tt;
		printf("Case #%d: ",cnt1++);
		if(ss.size()<=8&&tt.size()<=8){
			int s=trans(ss);
			int t=trans(tt);
			int ans=dij(s, t, (1<<15)+5);
			if(ans==-1)printf("IMPOSSIBLE\n");
			else printf("%d\n",ans);
			continue;
		}
		if(bfs(ss,tt)){
			cout<<ms[tt]-1<<endl;
		}
		else cout<<"IMPOSSIBLE\n";
		
		
		
		ms.clear();
		
	}
	
	
	
	return 0;
}




















