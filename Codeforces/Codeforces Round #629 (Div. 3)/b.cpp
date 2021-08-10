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



int main(){
	
	int T;gi(T);while(T--){
		int n,k;
		cin>>n>>k;
		int sum=0;
		int flag=0;
		for(int i=n-1;i>=1;i--){
			if(sum+n-i<k){
				sum+=n-i;
			}
			else{
				flag=i;
				break;
			}
		}
		int t=k-sum;
		int flag1;
		for(int i=n;i>flag;i--){
			t--;
			if(t==0){
				flag1=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(i==flag1||i==flag){
				cout<<'b';
			}
			else cout<<'a';
			
		}
		cout<<endl;
		
		
	}
	
	
	return 0;
}











