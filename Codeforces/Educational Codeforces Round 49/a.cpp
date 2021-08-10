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
#include <stack>
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
vector<char> change(char s){
	vector<char>a;
	if(s=='a'){
		a.push_back('b');
	}
	else if(s=='z'){
		a.push_back('y');
	}
	else {
		a.push_back(s+1);
		a.push_back(s-1);
	}
	return a;
}
int main(){
	string s;
	int n,m;
	int T;
	gi(T);while(T--){
		cin>>n;
		cin>>s;
		int oo=0;
		for(int i=0,j=s.size()-1;i<j;i++,j--){
			vector<char>a=change(s[i]);
			vector<char>b=change(s[j]);
			int flag=0;
			for(int t=0;t<a.size();t++){
				for(int q=0;q<b.size();q++){
					if(a[t]==b[q]){
						flag=1;break;
					}
				}
				if(flag)break;
			}
			if(flag){
				
			}
			else{
				oo=1;break;
			}
		}
		if(oo){
			printf("NO\n");
		}
		else printf("YES\n");
		
		
	}
	
	
	
	
	return 0;
}




