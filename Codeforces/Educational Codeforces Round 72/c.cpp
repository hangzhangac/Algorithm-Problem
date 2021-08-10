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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char a[MAXN][20],s[MAXN];
int l[MAXN];
int num[MAXN];
void cal(int x){
	int i=x;
	int cnt=0;
	while(x){
		a[i][cnt++]=(x%2)+'0';
		x/=2;
	}
	num[i]=cnt;
	a[i][cnt]='\0';
	for(int k=0,j=cnt-1;k<j;k++,j--){
		swap(a[i][k],a[i][j]);
	}
	num[i]=i-num[i];
}
int cal(int k,int j){
	int val=0;
	for(int i=k;i<=j;i++){
		val*=2;
		val+=s[i]-'0';
	}
	return val;
}
int main(){
	int n=200000;
	for(int i=1;i<=n;i++){
		cal(i);
	}
	int T;scanf("%d",&T);while(T--){
		scanf("%s",s);
		n=strlen(s);
		int cnt=0,ans=0;
		for(int i=0;i<n;i++){
			l[i]=cnt;
			if(s[i]=='0'){
				cnt++;
			}
			else cnt=0;
		}
		for(int i=0;i<n;i++){
			if(s[i]=='0')continue;
			int t=min(i+18-1,n-1);
			int val=cal(i,t);
			t=t-i+1;
			while(t){
				if(val<=200000){
					int len=num[val];
					if(l[i]>=num[val])ans++;
				}
				t--;
				val>>=1;
			}
		}
		printf("%d\n",ans);
		
	}

	return 0;
}









