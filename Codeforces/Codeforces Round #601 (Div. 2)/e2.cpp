#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>
#define lson i<<1
#define rson i<<1|1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define gc(x) scanf("%c",&x)
#define gc2(x,y) scanf("%c%c",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const double PI = acos(-1.0); 
const int MAXN=1000005;
const ll mod=1e7+9;
const ll llinf = (ll)(1e18) + 500;
const int inf=0x3f3f3f3f;
ll a[MAXN];
ll b[MAXN];
int n;
std::vector<ll> p;
void Solve(ll n)  
{  
    p.clear();  
    for(ll i=2; i*i<=n; i++){  
        if(n%i==0){  
            p.push_back(i);  
            while(n%i==0) n/=i;  
        }
    }  
    if(n>1)  
    	p.push_back(n);  //这个不可以缺少
}
void OUT(std::vector<ll> v){
	for(int i=0;i<v.size();i++){
		ll x=v[i];
		cout<<x<<endl;
	}
}
void copy(ll b[],ll a[]){
	for(int i=1;i<=n;i++){
		a[i]=b[i];
	}
	return;
}  
int main(){
	//Solve(130);
	//OUT(p);
	//freopen("in.txt","r",stdin); 
	ll sum=0;
	gi(n);
	for(int i=1;i<=n;i++){
		gll(a[i]);
		sum+=a[i];
		b[i]=a[i];
	}
	if(sum==1){
		printf("-1\n");
		return 0;
	}
	Solve(sum);
	queue< pair<int,ll> >q;
	ll minn=1e18+1;
	for(int i=0;i<p.size();i++){
		ll base=p[i];
		//cout<<base<<endl;
		ll ans=0;
		while(!q.empty())q.pop();
		for (int i = 1; i <=n ; ++i){
 
			while(!q.empty()){
				pair<int,ll>s=q.front();
				q.pop();
				ll need=s.second;
				int cor=s.first;
				ll t=min(a[i],need);
				a[i]-=t;
				need-=t;
				ans+=1ll*(i-cor)*t;
				if(need!=0){
					s.second=need;
					q.push(s);
				}
				if(a[i]==0){
					break;
				}
			}
			ll m=a[i]%base;
			if(m==0){
				continue;
			}
			else if(m<=base/2){//往后移动
				a[i]-=m;
				a[i+1]+=m;
				ans+=m;
			}
			else{//等待补充
				q.push(make_pair(i,base-m));
			}
		}
		minn=min(minn,ans);
		copy(b,a);
	}
	cout<<minn<<endl;
	return 0;
}
