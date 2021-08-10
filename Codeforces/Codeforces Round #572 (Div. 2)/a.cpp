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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char a[MAXN];
int main(){
	
	int n;gi(n);
	scanf("%s",a);
	int cnt1=0,cnt0=0;
	for(int i=0;i<n;i++){
		if(a[i]=='1'){
			cnt1++;
		}
		else{
			cnt0++;
		}
	}
	if(cnt1!=cnt0){
		printf("%d\n",1);
		cout<<a<<endl;
	}
	else{
		char s=a[n-1];
		a[n-1]='\0';
		
		cout<<2<<endl;
		cout<<a<<' ';
		cout<<s<<endl;
		
	}
	
	
	
	
	
	
	return 0;
}








