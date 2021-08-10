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
int a[MAXN];
int b[MAXN];
int main(){
	int flag=0;
	cout<<"? "<<0<<' '<<0<<endl;
	cin>>flag;
	int testa=0;
	int testb=0;
	for(int i=29;i>=0;i--){
		int x,y;
		int q=1<<i;
		cout<<"? "<<(testa|q)<<' '<<testb<<endl;
		cin>>x;
		cout<<"? "<<testa<<' '<<(testb|q)<<endl;
		cin>>y;
		if(x!=y){
			if(x==-1&&y==1){
				a[i]=b[i]=1;
				testa|=q;
				testb|=q;
			}
			else if(x==1&&y==-1){
				a[i]=b[i]=0;
			}
		}
		else{
			if(flag==1){
				a[i]=1;b[i]=0;
				testa|=q;
			}
			else if(flag==-1){
				a[i]=0;b[i]=1;
				testb|=q;
			}
			if(x==1&&y==1){
				flag=1;
			}
			else if(x==-1&&y==-1){
				flag=-1;
			}
			else{
				flag=0;
			}
		}
	}
	int a1=0,b1=0;
	for(int i=0;i<30;i++){
		if(a[i]==1)
		a1|=(1<<i);
		if(b[i]==1)
		b1|=(1<<i);
	}
	cout<<"! "<<a1<<' '<<b1<<endl;
	
	
	return 0;
}































