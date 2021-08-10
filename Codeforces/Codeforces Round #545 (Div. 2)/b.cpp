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
//struct Node{
//	int a,b;
//}node[MAXN];
char s1[MAXN];
char s2[MAXN];
vector<int>a[4];
int siz[4];
int n;
vector<int> solve(){
	for(int i=0;i<=siz[2];i++){
		for(int j=0;j<=siz[3];j++){
			if(i+j>n/2)continue;
			int cnt1_1=i+j;
			int cnt11=siz[3]-j;
			int cnt01=siz[1];
			if(cnt11>cnt1_1||cnt11+cnt01<cnt1_1){
				continue;
			}
			int cnt01_1=cnt11+cnt01-cnt1_1;
			if(cnt01_1+cnt1_1>n/2||cnt1_1+siz[2]-i>n/2){
				continue;
			}
			vector<int>ans;
			ans.push_back(i);
			ans.push_back(j);
			ans.push_back(cnt01_1);
			return ans;
		}
	}
	vector<int>ans;
	ans.push_back(-1);
	return ans;
}
int main(){
	
	
	
	gi(n);
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	n=strlen(s1+1);
	for(int i=1;i<=n;i++){
		if(s1[i]=='0'&&s2[i]=='0'){
			a[0].push_back(i);
		}else if(s1[i]=='0'&&s2[i]=='1'){
			a[1].push_back(i);
		}else if(s1[i]=='1'&&s2[i]=='0'){
			a[2].push_back(i);
		}else{
			a[3].push_back(i);
		}
	}
	for(int i=0;i<4;i++){
		siz[i]=a[i].size();
	}
	vector<int>ans=solve();
	if(ans.size()==1){
		printf("-1\n");
	}
	else{
		int sum=0;
		for(int i=0;i<3;i++){
			sum+=ans[i];
		}
		int cnt00=n/2-sum;
		vector<int>mm;
		for(int i=0;i<cnt00;i++){
			mm.push_back(a[0][i]);
		}
		for(int i=0;i<ans[0];i++){
			mm.push_back(a[2][i]);
		}
		for(int i=0;i<ans[1];i++){
			mm.push_back(a[3][i]);
		}
		for(int i=0;i<ans[2];i++){
			mm.push_back(a[1][i]);
		}
		for(int i=0;i<mm.size();i++){
			printf("%d ",mm[i]);
		}
	}
	
	return 0;
}

















