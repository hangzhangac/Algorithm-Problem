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
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
 char s[]={'a', 'e', 'i', 'o' ,'u'};
int in(char a){
	for(int i=0;i<5;i++){
		if(a==s[i])return 1;
	}
	return 0;
}
int main(){
	
	string a,b;
	cin>>a>>b;
	int flag=1;
	if(a.size()!=b.size()){
		flag=0;
	}
	for(int i=0;i<a.size();i++){
		if(a[i]==b[i])continue;
		if(in(a[i])+in(b[i])==1){
			flag=0;
			break;
		}
	}
	if(flag){
		printf("Yes\n");
	}
	else printf("No\n");
	
	
	
	return 0;
}






















