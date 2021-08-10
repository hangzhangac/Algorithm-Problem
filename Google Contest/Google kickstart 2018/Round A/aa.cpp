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
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;

string s[105];
int book[105];
bool judge(string a,string b){
	int i,j;
	for(i=0,j=0;i<a.size()&&j<b.size();i++,j++){
		if(a[i]==b[j]);
		else break;
	}
	if(i==b.size())return true;
	return false;
}
int n,m;
int main(){
	freopen("A-large.in","r",stdin); //输入重定向，输入数据将从D盘根目录下的in.txt文件中读取 
	freopen("ans.out","w",stdout);
	int cnt=1;
	int T;cin>>T;while(T--){
		cin>>m>>n;
		mem(book,0);
		for(int i=1;i<=n;i++){
			cin>>s[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i||book[j]==1)continue;
				if(judge(s[i],s[j])){
					book[i]=1;
					break;
				}
			}
		}
		ll sum=1;
		for(int i=1;i<=m;i++){
			sum*=2;
		}
		for(int i=1;i<=n;i++){
			
			if(book[i])continue;
			//cout<<i<<endl;
			int t=s[i].size();
			ll s=1;
			for(int i=1;i<=m-t;i++){
				s*=2;
			}
			sum-=s;
		}
		printf("Case #%d: ",cnt++);
		printf("%lld\n",sum);
	}
	
	
	return 0;
}




























