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

string a,b;
int flag=0;
vector<int>ans;
void solve(string a,char s,char t){
	int i=0;
	int cnt=0;
	while(i<a.size()&&a[i]==s){
		i++;
	}
	if(i==a.size()){
		flag=1;
		return ;
	}
	while(i<a.size()-1){
		if(a[i]==t){
			a[i]=s;
			ans.push_back(i+1);
			if(a[i+1]==t){
				a[i+1]=s;
			}
			else a[i+1]=t;
		}
		i++;
	}
	if(a[a.size()-1]==s){
		flag=1;
	}
	return;
	
	
}
void OUT(vector<int>ans){
	int t=ans.size();
	printf("%d\n",t);
	for(int i=0;i<t;i++){
		printf("%d ",ans[i]);
	}
}
int main(){
	
	int n;
	cin>>n;
	cin>>a;
	solve(a,'B','W');
	//printf("1");
	if(flag){
		OUT(ans);
		return 0;
	}
	ans.clear();
	solve(a,'W','B');
	if(flag){
		OUT(ans);
	}
	else{
		printf("-1\n");
	}
	
	
	
	
	
	return 0;
}





















