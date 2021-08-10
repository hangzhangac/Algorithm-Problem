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
	int x[MAXN],y[MAXN];
	int a[MAXN],b[MAXN];
	int p[1002];
	map<int,int>ms[2*1000005];
	int main(){
		int n;gi(n);
		for(int i=1;i<=n;i++){
			gi2(x[i],y[i]);
			ms[x[i]+1000000][y[i]]=i;
		}
		for(int i=1;i<=n;i++){
			gi2(a[i],b[i]);
		}
		int xx,yy;
		for(int i=1;i<=n;i++){
			mem(p,0);
			p[i]=1;
			xx=a[i]+x[1],yy=b[i]+y[1];
			int flag=1;
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				int s=xx-a[j];
				int t=yy-b[j];
				s+=1000000;
				if(s>=0&&s<=2000000){
					int q=ms[s][t];
					if(q!=0&&q!=1){
						p[j]=q;
					}
					else{
						flag=0;
						break;
					}
				}
				else{
					flag=0;
					break;
				}
			}
			if(flag)break;
		}
		printf("%d %d",xx,yy);
		
		
		
		return 0;
	}



	
