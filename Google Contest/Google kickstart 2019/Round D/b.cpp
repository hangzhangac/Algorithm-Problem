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
vector<int>a[2][MAXN];//0 is pos , 1 is anti
int book[MAXN];
int book1[MAXN];
int flag[MAXN];
int s[MAXN];
int num[2][MAXN];
int n,g,m;
int ss[MAXN];
queue<int>q;
int dis(int a,int b){
	if(a<=b){
		return b-a;
	}
	else{
		return n-a+b;
	}
}
void init(){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++){
		num[0][i]=num[1][i]=0;
		a[0][i].clear();
		a[0][i+n].clear();
		a[1][i].clear();
		a[1][i+n].clear();
		book[i]=-1;
		book1[i]=-1;
		flag[i]=0;
	}
	if(m>=2*n){
		m%=n;
		m+=n;
	}
}
int main(){
	
	int T,cnt=1;
	gi(T);
	while(T--){
		printf("Case #%d:",cnt++);
		int l=1,r=0;
		gi3(n,g,m);//n 不是乘客
		init();
		for(int i=1;i<=g;i++){
			ss[i]=0;
			int x;char s1[3];
			gi(x);scanf("%s",s1);
			if(s1[0]=='C'){
				a[0][x].push_back(i);
				a[0][x+n].push_back(i);
			}
			else{
				a[1][x].push_back(i);
				a[1][x+n].push_back(i);
			}
		}
		n*=2;
		for(int i=n-m+1;i<=n;i++){
			if(a[0][i].size()){
				q.push(i);
			}
		}
		if(a[0][1].size()){
			q.push(1);
		}
		for(int i=1;i<=m+1;i++){
			if(a[1][i].size()){
				++r;
				s[r]=i;
			}
		}
		for(int i=1;i<=n/2;i++){
			if(i!=1){
				while(!q.empty()&&(dis(q.front(),i)>m||q.front()==i)){
					q.pop();
				}
				if(a[0][i].size()){
					q.push(i);
				}
				int nx=i+m;
				if(nx>n)nx-=n;
				if(a[1][nx].size()){
					++r;
					s[r]=nx;
				}
			}
			if(q.empty()&&l>r){
				flag[i]=-1;
				book[i]=-1;
			}
			else if(q.empty()){
				flag[i]=1;
				book[i]=s[r];
			}
			else if(l>r){
				flag[i]=0;
				book[i]=q.front();
			}
			else{
				int t1=dis(q.front(), i);
				int t2=dis(i,s[r]);
				if(t1==t2){
					flag[i]=2;
					book[i]=q.front();
					book1[i]=s[r];
				}
				else if(t1>t2){
					flag[i]=0;
					book[i]=q.front();
				}
				else{
					flag[i]=1;
					book[i]=s[r];
				}
			}
			if(l<=r&&s[l]==i){
				l++;
			}
		}
		n/=2;
		for(int i=1;i<=n;i++){
			if(flag[i]==0||flag[i]==1){
				int t=book[i];
				while(t>n)t-=n;
				num[flag[i]][t]++;
			}
			else if(flag[i]==2){
				int t=book[i];
				while(t>n)t-=n;
				num[0][t]++;
				
				t=book1[i];
				while(t>n)t-=n;
				num[1][t]++;
			}
		}
		for(int i=0;i<=1;i++){
			for(int j=1;j<=n;j++){
				for(int q=0;q<a[i][j].size();q++){
					int id=a[i][j][q];
					ss[id]+=num[i][j];
				}
			}
		}
		for(int i=1;i<=g;i++){
			printf(" %d",ss[i]);
		}
		puts("");
	}//T--
	return 0;
}







