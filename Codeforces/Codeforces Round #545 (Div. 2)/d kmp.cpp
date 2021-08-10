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
const int MAXN=500005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char s[MAXN];
char t[MAXN];
int f[MAXN];
void getf(char *b){
	int m=strlen(b);
	f[0]=-1;
	int i,j;
	for(i=1;i<m;i++){
		j=f[i-1];
		while(b[j+1]!=b[i]&&j>=0) j=f[j];
		if(b[j+1]==b[i]) f[i]=j+1;
		else f[i]=-1;
	}
}
int main(){
	
	scanf("%s",s);
	int n=strlen(s);
	scanf("%s",t);
	int m=strlen(t);
	getf(t);
	int len=f[m-1]+1;
	
	int cnt0=0,cnt1=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			cnt0++;
		}
		else cnt1++;
	}
	int id=0;
	int cur=n+1;
	if(n<m){
		printf("%s",s);
		return 0;
	}
	for(int i=0;i<m;i++){
		if(t[id]=='1'){
			if(!cnt1){
				cur=i;break;
			}
			else cnt1--;
			s[i]=t[id];
		}
		else if(t[id]=='0'){
			if(!cnt0){
				cur=i;break;
			}
			else cnt0--;
			s[i]=t[id];
		}
		id++;
		if(id==m){
			id=len;
			for(int i=m;i<n;i++){
				if(t[id]=='1'){
					if(!cnt1){
						cur=i;break;
					}
					else cnt1--;
					s[i]=t[id];
				}
				else if(t[id]=='0'){
					if(!cnt0){
						cur=i;break;
					}
					else cnt0--;
					s[i]=t[id];
				}
				id++;
				if(id>=m){
					id=len;
				}
			}
			break;
		}
	}
	while(cnt0--){
		s[cur++]='0';
	}
	while(cnt1--){
		s[cur++]='1';
	}
	printf("%s",s);
	
	
	
	
	return 0;
}







