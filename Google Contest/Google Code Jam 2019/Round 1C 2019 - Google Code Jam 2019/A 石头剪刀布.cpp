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
int n;
int num[260];
int book[260];
string a[260];
int t[1000];
int tt[5];
char s[MAXN*30];
int main(){
	
	int T;
	gi(T);
	int mm=1;
	t['R']=0,t['S']=1,t['P']=2;
	tt[0]='R';tt[1]='S';tt[2]='P';
	while(T--){
		printf("Case #%d: ",mm++);
		mem(book,0);
		mem(num,0);
		gi(n);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int j=0;
		int bok=0;
		int qq=0;
		while(qq<n){
			int cur[4]={0,0,0,0};
			int flag=0;
			for(int i=1;i<=n;i++){
				if(book[i])continue;
				flag=1;
				int id=num[i]++;
				if(num[i]==a[i].size())num[i]=0;
				char s=a[i][id];
				id=(t[s]+1)%3;
				cur[id]=1;
			}
			if(!flag){qq=n;break;}
			int cnt=0;
			for(int i=0;i<3;i++){
				cnt+=cur[i];
			}
			int ss=0;
			if(cnt==3){
				bok=1;
				break;
			}
			else if(cnt==1){
				for(int i=0;i<3;i++){
					if(cur[i]){
						s[j++]=tt[(i+1)%3];
						ss=(i+1)%3;
						break;
					}
				}
				
			}
			else if(cnt==2){
				for(int i=0;i<3;i++){
					if(!cur[i]){
						ss=i;
						s[j++]=tt[i];
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(!book[i]){
					int id=(num[i]-1+a[i].size())%(a[i].size());
					char s=a[i][id];
					id=t[s];
					if((ss+1)%3==id){
						book[i]=true;
						qq++;
					}
				}
			}
		}
		if(bok||qq!=n){
			printf("IMPOSSIBLE\n");
		}
		else{
			t[j]='\0';
			printf("%s\n",s);
		}
		
	}
	return 0;
}













