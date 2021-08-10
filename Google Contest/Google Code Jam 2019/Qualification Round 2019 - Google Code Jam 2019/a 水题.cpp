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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char a[105];
char ans1[105],ans2[105];
int main(){
	
	int cnt=1;
	int T;
	cin>>T;
	while(T--){
		scanf("%s",a+1);
		int n=strlen(a+1);
		int len1=n,len2=n;
		for(int i=n;i>=1;i--){
			a[i]-='0';
			if(a[i]==0){
				ans1[len1--]=0;
				ans2[len2--]=0;
			}
			else if(a[i]==5){
				ans1[len1--]=2;
				ans2[len2--]=3;
			}
			else{
				ans1[len1--]=1;
				ans2[len2--]=a[i]-1;
			}
		}
		len1++;len2++;
		while(len1<=n&&ans1[len1]==0){
			len1++;
		}
		while(len2<=n&&ans2[len2]==0){
			len2++;
		}
		ans1[n+1]='\0';ans2[n+1]='\0';
		for(int i=len1;i<=n;i++){
			ans1[i]+='0';
		}
		for(int i=len2;i<=n;i++){
			ans2[i]+='0';
		}
		printf("Case #%d: ",cnt++);
		cout<<ans1+len1<<' '<<ans2+len2<<endl;
	}

	return 0;
}