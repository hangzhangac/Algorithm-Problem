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
int n;
string s;
int a[MAXN];
stack<char>q;
stack<int>lay;

int main(){
	
	int n;
	gi(n);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='('){
			if(q.empty()){
				lay.push(1);
				q.push('(');
				a[i]=1;
			}
			else{
				q.push('(');
				lay.push(lay.top()+1);
				a[i]=lay.top();
			}
		}
		else{
			q.pop();
			int t=lay.top();
			lay.pop();
			a[i]=t;
		}
	}
	int maxn=0;
	for(int i=0;i<n;i++){
		maxn=max(maxn,a[i]);
	}
	maxn++;maxn/=2;
	for(int i=0;i<n;i++){
		if(a[i]<=maxn){
			putchar('0');
		}
		else putchar('1');
	}
	return 0;
}











