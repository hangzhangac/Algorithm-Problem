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
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;
vector<int>ans;
int main(){
	int cnt1=1;
	int T;gi(T);while(T--){
		ans.clear();
		int n;gi(n);
		printf("Case #%d: ",cnt1++);
		int a,b,c;gi2(a,b);gi(c);
		if(a+b-c>n||(a==1&&b==1&&n!=1)){
			printf("IMPOSSIBLE\n");
			continue;
		}
		if(n==1){
			cout<<"1"<<endl;
			continue;
		}
		if(n==2){
			if(a==1&&b==2){//2 1
				cout<<"2 1"<<endl;
			}
			else if(a==2&&b==1){//1 2 
				cout<<"1 2"<<endl;
			}
			else if(a==2&&b==2){
				cout<<"2 2"<<endl;
			}
			continue;
		}
		int t=1;
		while(t<=a-c){
			ans.push_back(2);
			t++;
		}
		if(c!=1){
			ans.push_back(3);
			t=1;
			while(t<=n-(a+b-c)){ans.push_back(1);t++;}
			t=1;
			while(t<=c-1){ans.push_back(3);t++;}
			t=1;
			while(t<=b-c){ans.push_back(2);t++;}
		}
		else{
			
			int flag=0;
			if(a-c!=0){
				flag=1;
				t=1;
				while(t<=n-(a+b-c)){ans.push_back(1);t++;}
			}
			ans.push_back(3);
			if(flag==0){
				t=1;
				while(t<=n-(a+b-c)){ans.push_back(1);t++;}
			}
			t=1;
			while(t<=b-c){ans.push_back(2);t++;}
		}
		for(int i=0;i<ans.size();i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
		
		
	}
	
	
	
	return 0;
}


















