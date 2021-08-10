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
const int MAXN=105;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;

char s[MAXN];
int num[MAXN];
vector<char>a;
int main(){
	int n;
	gi(n);
	scanf("%s",s);
	int i=0;
	int id=0;
	while(i<n){
		char cur=s[i];
		int cnt=1;
		i++;
		while(i<n&&s[i]==cur){
			cnt++;
			i++;
		}
		s[id]=cur;
		num[id]=cnt;
		id++;
	}
	int cnt=0;
	for(char t='z';t>='b';t--){
		for(int i=0;i<id;i++){
			int flag=0;
			if(s[i]!=t)continue;
			if(i-1>=0){
				if(s[i-1]==t-1)
					flag++;
			}
			if(i+1<id){
				if(s[i+1]==t-1){
					flag++;
				}
			}
			if(flag){
				cnt+=num[i];
				s[i]='0';
			}
		}
		int q=0;
		for(int j=0;j<id;j++){
			if(s[j]=='0');
			else{
				s[q]=s[j];
				num[q]=num[j];
				q++;
			}
		}
		id=q;
		int j=0;
		q=0;
		while(j<id){
			char cur=s[j];
			int cnt1=num[j];
			j++;
				while(j<id&&s[j]==cur){
					cnt1+=num[j];
					j++;
				}
				s[q]=cur;
				num[q]=cnt1;
				q++;
		}
		id=q;
	}
	printf("%d\n",cnt);
	
	
	return 0;
}




















