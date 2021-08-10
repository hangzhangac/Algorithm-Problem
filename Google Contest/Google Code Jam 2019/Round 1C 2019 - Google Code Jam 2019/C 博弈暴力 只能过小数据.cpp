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
char a[20][20];
int n,m;
ll ans=0;
int qq[20][20][4];

vector<int> judge(int x,int y,int dir){//dir 0水平  1竖直
	vector<int>res;
	int flag=0;
	if(dir==0){
		int l=y,r=y;
		while(l>=1){
			if(a[x][l]=='.'){
				l--;
			}
			else if(a[x][l]=='#'){
				flag=1;break;
			}
			else if(a[x][l]=='b'){
				break;
			}
		}
		l++;
		while(r<=m){
			if(a[x][r]=='.'){
				r++;
			}
			else if(a[x][r]=='#'){
				flag=1;break;
			}
			else if(a[x][r]=='b'){
				break;
			}
		}
		r--;
		//cout<<"fea1"<<endl;
		if(flag)res.push_back(-1);
		else {res.push_back(l),res.push_back(r);}
	}
	
	
	else{//dir==1
		int l=x,r=x;
		while(l>=1){
			if(a[l][y]=='.'){
				l--;
			}
			else if(a[l][y]=='#'){
				flag=1;break;
			}
			else if(a[l][y]=='b'){
				break;
			}
		}
		l++;
		while(r<=n){
			if(a[r][y]=='.'){
				r++;
			}
			else if(a[r][y]=='#'){
				flag=1;break;
			}
			else if(a[r][y]=='b'){
				break;
			}
		}
		r--;
		if(flag)res.push_back(-1);
		else res.push_back(l),res.push_back(r);
	}
	return res;
}
void change(int x,int y,int l,int r,int dir){
	if(dir==0){
		for(int i=l;i<=r;i++){
			a[x][i]='b';
		}
	}
	else {
		for(int i=l;i<=r;i++){
			a[i][y]='b';
		}
	}
}
void restore(int x,int y,int l,int r,int dir){
	if(dir==0){
		for(int i=l;i<=r;i++){
			a[x][i]='.';
		}
	}
	else{
		for(int i=l;i<=r;i++){
			a[i][y]='.';
		}
	}
}
//用b表示有细菌了
bool dfs(int s,int t,int sta,int id){ //true 表示能赢 false 表示不能赢吧
	bool flag=false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]!='.')continue;
			vector<int>res=judge(i, j, 0);
			if(res.size()==2){
				change(i,j,res[0],res[1],0);
				flag|=dfs(i,j,0,id^1);
				restore(i, j, res[0], res[1], 0);
			}
			if(flag)return false;
			res=judge(i, j, 1);
			if(res.size()==2){
				change(i,j,res[0],res[1],1);
				flag|=dfs(i,j,0,id^1);
				restore(i, j, res[0], res[1], 1);
			}
			if(flag)return false;
		}
	}
	return true;
}
int main(){
	
	
	int T,cnt=1;gi(T);
	
	while(T--){
		mem(qq,0);
		ans=0;
		printf("Case #%d: ",cnt++);
		gi2(n,m);
		for(int i=1;i<=n;i++){
			scanf("%s",a[i]+1);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]=='.'){
					
					vector<int>res=judge(i, j, 0);
					if(res.size()==2){
						change(i,j,res[0],res[1],0);
						ans+=(int)dfs(i,j,0,0);
						restore(i, j, res[0], res[1], 0);
					}
					res=judge(i, j, 1);
					if(res.size()==2){
						change(i,j,res[0],res[1],1);
						ans+=(int)dfs(i,j,1,0);
						restore(i, j, res[0], res[1], 1);
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}