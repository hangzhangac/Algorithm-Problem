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
char a[MAXN];
int s[MAXN];
int t[MAXN];
int len[MAXN];
int main(){
	
	int n;
	cin>>n;
	int cnt=0;
	scanf("%s",a+1);
	int i=1;
	while(i<=n){
		if(a[i]=='G'){
			s[++cnt]=i;
			while(i<=n&&a[i]=='G'){
				i++;
			}
			t[cnt]=i-1;
			len[cnt]=t[cnt]-s[cnt]+1;
		}
		else{
			i++;
		}
	}
	if(cnt==0){
		printf("0\n");
		return 0;
	}
	if(cnt==1){
		printf("%d\n",t[cnt]-s[cnt]+1);	
	}
	else if(cnt==2){
		if(t[1]+2==s[2]){
			printf("%d\n",len[1]+len[2]);
		}
		else{
			printf("%d\n",1+max(len[1],len[2]));
		}
		//GGSSGGGGGGGSSGG
	}
	else{
		int maxn=0;
		for(int i=1;i<=cnt;i++){
			maxn=max(len[i]+1,maxn);
		}
		for(int i=1;i<=cnt-1;i++){
			if(t[i]+2==s[i+1]){
				maxn=max(len[i]+len[i+1]+1,maxn);
			}
		}
		//cout<<1<<endl;
		printf("%d\n",maxn);
	}
	
	
	return 0;
}


