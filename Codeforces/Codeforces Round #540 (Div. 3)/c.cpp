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
int book[1005];
int a[30][30];
int main(){
	
	
	int n;gi(n);int maxn=1000;
	int t=n*n;
	for(int i=1;i<=t;i++){
		int x;
		gi(x);
		book[x]++;
	
	}
	
		int row1=1,row2=n;
		int l1=1,r1=n;
		int l2=1,r2=n;
		int flag=0;
		while(row1<row2){
			int cnt=-1;
			for(int i=1;i<=1000;i++){
				if(book[i]>=4){
					book[i]-=4;
					cnt=i;
					break;
				}
			}
			if(cnt==-1){flag=1;}
			a[row1][l1++]=a[row1][r1--]=cnt;
			a[row2][l2++]=a[row2][r2--]=cnt;
			if(l1>=r1){
				row1++;row2--;
				l1=1;r1=n;
				l2=1;r2=n;
			}
		}
		if(n&1){
			int row=row1;
			while(l1<r1){
				int cnt=-1;
				for(int i=1;i<=1000;i++){
					if(book[i]>=2){
						book[i]-=2;
						cnt=i;
						break;
					}
				}
				if(cnt==-1)flag=1;
				a[row][l1++]=a[row][r1--]=cnt;
			}
			while(l2<r2){
				int cnt=-1;
				for(int i=1;i<=1000;i++){
					if(book[i]>=2){
						book[i]-=2;
						cnt=i;
						break;
					}
				}
				if(cnt==-1)flag=1;
				a[l2++][row]=a[r2--][row]=cnt;
			}
			for(int i=1;i<=1000;i++){
				if(book[i]){
					a[row][row]=i;
					break;
				}
			}
		}
		if(flag){
			printf("NO\n");
			return 0;
		}
		printf("YES\n");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%d%c",a[i][j],j==n?'\n':' ');
			}
		}
	return 0;
}








