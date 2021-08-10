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
string a[3];
int p[MAXN];
map<string,int>ms;
map<string,int>m1;
map<char,string>f;


int gcd(int a,int b){
	if(b==0)return a;
	else return gcd(b,a%b);
}
int main(){
	f['T']="F";
	f['F']="T";
	int T,cnt1=1;gi(T);while(T--){
		ms.clear();
		m1.clear();
		int n,q;
		cin>>n>>q;
		for(int i=0;i<n;i++){
			cin>>a[i]>>p[i];
		}
		for(int i=0;i<n;i++){
			int r=p[i];
			int nn=q;
			for(int s=(1<<r)-1;s<1<<nn;){
				int cur=s;
				//cout<<(bitset<3>)s<<endl;
				string ans="";
				int cnt=0;
				for(int j=0;j<q;j++){
					if((cur>>j)&1){
						ans+=a[i][j];
						cnt++;
					}
					else{
						ans+=f[a[i][j]];
						cnt++;
					}
				}
				//cout<<ans<<"ff"<<cnt<<endl;
				ms[ans]++;
				int x=s&-s;
				int y=s+x;
				s=((s&~y)/x>>1)|y;
			}
		}
		map<string,int>::iterator iter=ms.begin();
		while(iter != ms.end()) {
			if(iter->second==n){
				m1[iter->first]=1;
			}
			iter++;
		}
		
		int aa=0;
		int pp=0;
		int ans1=0,ans2=0;
		string aaa="";
		for(int i=0;i<(1<<q);i++){
			map<string,int>::iterator iter=m1.begin();
			int t=m1.size();
			int p=0;
			while(iter != m1.end()) {
				string ans=iter->first;
				
				for(int j=0;j<q;j++){
					if(ans[j]=='T'&&((i>>j)&1)){
						p++;
					}
					else if(ans[j]=='F'&&((i>>j)&1)==0){
						p++;
					}
				}
				iter++;
			}
			if(p>pp){
				pp=p;
				aa=i;
			}
		}
		
		int g=gcd(pp, 1*m1.size());
		printf("Case #%d: ",cnt1++);
		for(int i=0;i<q;i++){
			if((aa>>i)&1){
				cout<<"T";
			}
			
			
			
			else cout<<"F";
		}
		cout<<" ";
		printf("%d/%d\n",pp/g,m1.size()/g);
		
	}
	
	return 0;
	
}