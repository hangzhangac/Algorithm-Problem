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
int x[MAXN];
int y[MAXN];
int dx[]={1,1,-1,-1};
int dy[]={1,-1,1,-1};
int ms[1005][1005];
int id[5];
int cnt[5];
bool cmp(int i,int j){
	return cnt[i]<cnt[j];
}
int main(){
	
	int n=666;
	int s,t;
	cin>>s>>t;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		ms[x[i]][y[i]]=1;
	}
	while(s!=500||t!=500){
		int flag=0;
		for(int i=0;i<4;i++){
			int nx=s+dx[i];
			int ny=t+dy[i];
			if(nx<=0||nx>999||ny<=0||ny>999)continue;
			if(ms[nx][ny]==1){
				if(i==0||i==1){
					cout<<s+1<<' '<<t<<endl;
					s++;
				}
				else{
					cout<<s-1<<' '<<t<<endl;
					s--;
				}
				flag=1;break;
			}
		}
		
		int zx=500,zy=500;
		if(!flag){
			if(s>zx){
				s--;
			}
			else if(s<zx){
				s++;
			}
			if(t>zy){
				t--;
			}
			else if(t<zy){
				t++;
			}
			cout<<s<<' '<<t<<endl;
		}
		int k,p,q;
		cin>>k>>p>>q;
		if(k==0){
			return 0;
		}
		if(k==-1)return 0;
		ms[x[k]][y[k]]=0;
		x[k]=p,y[k]=q;
		ms[x[k]][y[k]]=1;
	}
	for(int i=1;i<500;i++){
		for(int j=1;j<500;j++){
			if(ms[i][j]){
				cnt[0]++;
			}
		}
	}
	for(int i=1;i<500;i++){
			for(int j=501;j<1000;j++){
				if(ms[i][j]){
					cnt[1]++;
				}
			}
		}
	for(int i=501;i<1000;i++){
			for(int j=1;j<500;j++){
				if(ms[i][j]){
					cnt[2]++;
				}
			}
		}
	for(int i=501;i<1000;i++){
			for(int j=501;j<1000;j++){
				if(ms[i][j]){
					cnt[3]++;
				}
			}
		}
	for(int i=0;i<4;i++){
		id[i]=i;
	}
	sort(id,id+4,cmp);
	int q=id[0];
	while(s>=1&&s<=999&&t>=1&&t<=999){
		int flag=0;
		for(int i=0;i<4;i++){
			int nx=s+dx[i];
			int ny=t+dy[i];
			if(nx<=0||nx>999||ny<=0||ny>999)continue;
			if(ms[nx][ny]==1){
				if(i==0||i==1){
					cout<<s+1<<' '<<t<<endl;
					s++;
				}
				else{
					cout<<s-1<<' '<<t<<endl;
					s--;
					//flag=1;break;
				}
				flag=1;break;
			}
		}
		if(!flag){
			s+=dx[q];
			t+=dy[q];
			cout<<s<<' '<<t<<endl;
		}
		int k,p,q;
		cin>>k>>p>>q;
		if(k==0){
			return 0;
		}
		if(k==-1)return 0;
		ms[x[k]][y[k]]=0;
		x[k]=p,y[k]=q;
		ms[x[k]][y[k]]=1;
	}
	
	
	
	return 0;
}


















