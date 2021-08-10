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
const int MAXN=100020;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
vector< pair<int,int> >point;
vector<int>pp;
int x[MAXN],y[MAXN];
char s[MAXN],s1[5];
int flag=0;
int xx,yy;
int sumx[MAXN];
int sumy[MAXN];
void judge(int i,int j){
	if((s[i]=='N'||s[i]=='S')&&(s[j]=='N'||s[j]=='S')){
		flag=1;
		return ;
	}
	if((s[i]=='W'||s[i]=='E')&&(s[j]=='W'||s[j]=='E')){
		flag=1;
		return ;
	}
	flag=0;
	if(s[i]=='W'||s[i]=='E'){
		if(s[i]=='W'){
			xx=x[i]-1;
		}
		else xx=x[i]+1;
		if(s[j]=='N'){
			yy=y[j]+1;
		}
		else{
			yy=y[j]-1;
		}
		
	}
	else{
		if(s[j]=='W'){
			xx=x[j]-1;
		}
		else xx=x[j]+1;
		if(s[i]=='N'){
			yy=y[i]+1;
		}
		else{
			yy=y[i]-1;
		}
	}
	return;
}
int main(){
	
	int T,cnt=1;
	gi(T);
	while(T--){
		point.clear();
		pp.clear();
		printf("Case #%d: ",cnt++);
		int n,q;
		gi2(n,q);
		q++;
		for(int i=1;i<=q;i++){
			sumx[i]=0;
			sumy[i]=0;
		}
		int ansx=1,ansy=1;
		for(int i=1;i<=n;i++){
			gi2(x[i],y[i]);
			x[i]++,y[i]++;
			scanf("%s",s1);
			s[i]=s1[0];
		}
		x[n+1]=2;y[n+1]=1;s[n+1]='W';n++;
		x[n+1]=1;y[n+1]=2;s[n+1]='S';n++;
		x[n+1]=q-1;y[n+1]=1;s[n+1]='E';n++;
		x[n+1]=1;y[n+1]=q-1;s[n+1]='N';n++;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				judge(i,j);
				if(flag)continue;
				point.push_back(make_pair(xx,yy));
			}
		}
		for(int i=1;i<=n-4;i++){
			if(s[i]=='N'){
				sumy[y[i]+1]++;
			}
			else if(s[i]=='S'){
				sumy[1]++;
				sumy[y[i]]--;
			}
			else if(s[i]=='W'){
				sumx[1]++;
				sumx[x[i]]--;
			//	cout<<x[i]<<" fea"<<endl;
			}
			else{
				sumx[x[i]+1]++;
			}
		}
		for(int i=1;i<=q;i++){
			sumx[i]=sumx[i-1]+sumx[i];
			sumy[i]=sumy[i-1]+sumy[i];
		}
		for(int i=0;i<point.size();i++){
			pair<int,int>e=point[i];
			pp.push_back(sumx[point[i].first]+sumy[point[i].second]);
		}
		int val=-1;
		for(int i=0;i<point.size();i++){
			int t=pp[i];
			if(pp[i]>val){
				ansx=point[i].first;
				ansy=point[i].second;
				val=pp[i];
			}
			else if(pp[i]==val){
				if(ansx>point[i].first){
					ansx=point[i].first;
					ansy=point[i].second;
				}
				else if(ansx==point[i].first){
					if(ansy>point[i].second){
						ansy=point[i].second;
					}
				}
			}
		}
		printf("%d %d\n",ansx-1,ansy-1);
		
	}
	return 0;
}





