#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=505;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;

int a[MAXN];
int main(){
	int T;gi(T);
	while(T--){
		int n,x;
		gi2(n,x);
		for(int i=0;i<n;i++)gi(a[i]);
		//a[n]=x;
		vector<int>tmp;
		int cnt=0;
		int flag=1;
		tmp.push_back(a[0]);
		for(int i=1;i<n;i++){
			if(tmp.back()<=a[i]){
				tmp.push_back(a[i]);
				//cout<<1<<endl;
			}
			else{
				stack<int>s;
				while(tmp.size()&&x<tmp.back()){
					s.push(tmp.back());
					tmp.pop_back();
				}
				//cnt+=s.size();
				tmp.push_back(x);
				int last=-1;
				while(s.size()){
					int e=s.top();
					if(e!=last)cnt++;
					last=e;
					tmp.push_back(e);
					s.pop();
				}
				x=tmp.back();
				tmp.pop_back();
				
				if(tmp.back()>a[i]){
					flag=0;
					break;
				}
				else{
					tmp.push_back(a[i]);
				}
			}
		}
		if(flag)printf("%d\n",cnt);
		else printf("-1\n");
		
	}
	
	
	
	
	return 0;
}






















