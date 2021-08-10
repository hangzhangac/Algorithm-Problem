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
int book[10];
bool judge(int x){
	mem(book,0);
	while(x){
		int t=x%10;
		if(book[t]==1)return false;
		book[t]++;
		x/=10;
	}
	return true;
}
int main(){
	
	int l,r;
	cin>>l>>r;
	int ans=0;
	for(int x=l;x<=r;x++){
		if(judge(x)){
			printf("%d\n",x);return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}














