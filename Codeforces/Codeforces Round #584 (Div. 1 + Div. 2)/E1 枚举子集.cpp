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
int a[15][MAXN];
int f[MAXN][20];
int n,m;
int S;
void init(){
	for(int i=0;i<m;i++){
		for(int k=0;k<=S;k++){
			f[i][k]=0;
		}
	}
	return;
}
int main(){
	int T;gi(T);
	while(T--){
		gi2(n,m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)gi(a[i][j]);
		S=(1<<n)-1;
		init();
		for(int i=0;i<m;i++){
			for(int j=0;j<=S;j++){
				for(int s=j;;s=(s-1)&j){
					int u=0;
					for(int k=0;k<n;k++){
						int v=0;
						for(int q=0;q<n;q++){
							
							if(((1<<(q))&j)&&(!((1<<(q))&s)))
								v+=a[(q+k)%n][i];
						}
						u=max(u,v);
					}
					int t=(i>=1?f[i-1][s]:0);
					f[i][j]=max(f[i][j],u+t);
					if(!s)break;
				}
			}
		}
		printf("%d\n",f[m-1][S]);
		
		
	}
	return 0;
}
