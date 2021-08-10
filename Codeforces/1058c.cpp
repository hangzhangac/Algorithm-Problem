//https://www.cnblogs.com/markleaf/p/7808817.html
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
int n;
char s[105];
int main(){
	
	cin>>n;
	scanf("%s",s);
	int flag=1;
	int cnt=0;
	for(int i=0;i<n;i++){
		s[i]-='0';
		if(s[i]!=0){
			s[cnt++]=s[i];
		}
	}
	if(cnt==0){
		printf("YES\n");
	}
	else if(cnt==1){
		printf("NO\n");
	}
	else{
		int t=0;
		int f=0;
		for(int i=0;i<cnt-1;i++){
			t+=s[i];
			int j=i+1;
			int q=0;
			int flag=1;
			while(j<cnt){
				q+=s[j];
				if(q<t);
				else if(q==t){
					q=0;
				}
				else{
					flag=0;
					break;
				}
				j++;
			}
			if(q>0&&q<t){
				flag=0;
			}
			if(flag){
				f=1;break;
				break;
			}
		}
		if(f){
			printf("YES\n");
		}
		else printf("NO\n");
		
	}
	
	return 0;
}

