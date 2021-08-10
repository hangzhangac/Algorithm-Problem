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
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int book[MAXN];
int x[MAXN];
int main(){
	int T;gi(T);
	int cnt=1;
	//cout<<T<<endl;
	while(T--){
		printf("Case #%d: ",cnt++);
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++){
			book[i]=0;
			x[i]=0;
		}
		if(s.size()<=8){
			printf("0\n");
			continue;
		}
		for(int i=0;i<s.size()-4;i++){
			string t="";
			for(int j=i;j<=i+3;j++){
				t+=s[j];
			}
			if(t=="KICK"){
				book[i]=1;
				x[i]=1;
			}
			if(i!=0){
				book[i]+=book[i-1];
			}
		}
		string t="";
		ll ans=0;
		for(int j=s.size()-1;j>=0;j--){
			if(t.size()<5)t+=s[j];
			else{
				t=t.substr(1);
				t+=s[j];
			}
			if(t=="TRATS"){
				ans+=book[j];
			}
			if(x[j])book[j]--;
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}










