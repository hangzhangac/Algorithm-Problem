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
int book[1005];
int main(){
	
	string a;
	cin>>a;
	int i=0;
	while(1){
		while(i<a.size()&&a[i]=='b'){
			i++;
		}
		
		if(i>=a.size())break;
		int pre=i-1;
		while(i<a.size()&&a[i]=='a'){
			i++;
		}
		int cur=i-1;
		book[cur]=1;
		book[pre]=1;
	}
	for(int i=0;i<a.size();i++){
		printf("%d ",book[i]);
	}
	
	
	return 0;
}