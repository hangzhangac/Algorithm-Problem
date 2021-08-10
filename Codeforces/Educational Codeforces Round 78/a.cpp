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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
char p[MAXN];
char h[MAXN];
int num[27];
int book[27];
bool judge(int i,int j){
	for(int k=i;k<=j;k++){
		book[h[k]-'a']++;
		//cout<<1<<endl;
	}
	for(int i=0;i<26;i++){
		if(book[i]==num[i])continue;
		return false;
	}
	return true;
}
int main(){
	
	int T;
	cin>>T;
	while(T--){
		mem(num,0);
		mem(book,0);
		scanf("%s",p);
		scanf("%s",h);
		//cout<<p<<endl;
		//cout<<h<<endl;
		int flag=0;
		int lenp=strlen(p);
		int lenh=strlen(h);
		for(int i=0;i<lenp;i++){
			int s=p[i]-'a';
			num[s]++;
			
		}
		for(int i=0;i+lenp-1<lenh;i++){
			int j=i+lenp-1;
			mem(book,0);
			if(judge(i,j)){
				flag=1;
				break;
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	
	
	
	return 0;
}














