//
//  main.cpp
//  test
//
//  Created by 张航 on 2019/9/27.
//  Copyright © 2019 张航. All rights reserved.
//
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
const int MAXN=2005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[12][MAXN];
int f[12][1<<12],g[12][1<<12];
int b[MAXN],c[MAXN];
int n,m;
int S;
void init(){
	for(int i=0;i<n;i++){
		for(int k=0;k<=S;k++){
			f[i][k]=0;
		}
	}
	for(int i=0;i<m;i++){
		c[i]=i;
	}
	return;
}
bool cmp(int x,int y){
	return b[x]>b[y];
}
int main(){
	int T;gi(T);
	while(T--){
		gi2(n,m);
		for(int i=0;i<m;i++)b[i]=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				gi(a[i][j]);
				b[j]=max(b[j],a[i][j]);
			}
			
		S=(1<<n)-1;
		init();
		sort(c,c+m,cmp);
		m=min(n,m);
		for(int i=0;i<m;i++){
			for(int j=0;j<=S;j++){
				int u=0;
				for(int k=0;k<n;k++){
					int v=0;
					for(int q=0;q<n;q++){
						if((1<<q)&j){
							v+=a[(k+q)%n][c[i]];
						}
					}
					u=max(u,v);
				}
				g[i][j]=u;
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<=S;j++){
				for(int x=j;;x=(x-1)&j){
					int t=(i==0?0:f[i-1][j-x]);
					f[i][j]=max(f[i][j],g[i][x]+t);
					if(!x)break;
				}
			}
		}
		printf("%d\n",f[m-1][S]);
	}
	return 0;
}