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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int last[MAXN];
int main(){
	
	string s;
	int T;gi(T);while(T--){
		
		cin>>s;
		int n=s.size();
		int cnt=n;
		for(int i=0;i<n;i++){
			last[i]=i-1;
		}
		for(int i=0;i<n;i++){
			if(last[i]!=-1){
				string t="";
				t+=s[last[i]];
				t+=s[i];
				if(t=="BB"||t=="AB"){
					cnt-=2;
					last[i+1]=last[last[i]];
				}
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}