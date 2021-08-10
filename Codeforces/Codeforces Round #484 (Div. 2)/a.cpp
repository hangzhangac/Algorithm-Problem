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
string a;
int main(){
	
	int n;
	cin>>n;
	cin>>a;
	int flag=0;
	for(int i=0;i<n;i++){
		int cnt=0;
		if(a[i]=='1'){
			if(i-1>=0){
				if(a[i-1]=='1')cnt++;
			}
			if(i+1<n){
				if(a[i+1]=='1')cnt++;
			}
			if(cnt!=0){
				flag=1;break;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		int cnt=0;
		if(a[i]=='0'){
			if(i-1>=0){
				if(a[i-1]=='1')cnt++;
			}
			if(i+1<n){
				if(a[i+1]=='1')cnt++;
			}
			if(cnt){
				
			}
			else{
				flag=1;break;
			}
		}
	}
	if(flag){
			printf("No\n");return 0;
		}
	else printf("Yes\n");
	
	
	
	
	
	return 0;
}





























