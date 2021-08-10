#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
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
char s[MAXN];
vector<int>num;
vector<string> ans;
char stack[MAXN];
int len=0;
int book[MAXN];
void find_ans(){
	string s="";
	if(len<=10){
		for(int i=len;i>=1;i--){
			s+=stack[i];
		}
	}
	else{
		for(int i=len;i>=len-4;i--)s+=stack[i];
		s+="...";
		s+=stack[2];s+=stack[1];
	}
	num.push_back(len);
	ans.push_back(s);
}
int main(){
	
	cin>>(s+1);
	int flag=1;//相邻
	//int book=1; //0:a[i]<a[i+2]不删    1:a[i]>=a[i+2]删
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		book[i]=1;
	}
	for(int i=n;i>=1;i--){
		char t=s[i];
		if(len==0){
			len++;
			stack[len]=t;
			flag=1;
		}
		else{//len>=1
			if(flag==1){//相邻 
				if(t!=stack[len]){//不相等
					len++;
					stack[len]=t;//flag=1;
				}
				else{//相邻且相等
					if(len==1){
						len--;
					}
					else{
						if(t>stack[len-1]){
							len--;
							flag=0;
						}
						else if(t<stack[len-1]){
							len++;
							stack[len]=t;
							//flag=1;
						}
						else{
							//if(i==n-18)cout<<book[len]<<endl;
							if(book[len]==0){
								len++;
								stack[len]=t;
							}
							else{
								len--;
								flag=0;
							}
						}
					}
				}
			}
			else{//不相邻
				len++;
				stack[len]=t;
				flag=1;
			}
		}
		find_ans();
		if(len>=3&&stack[len]<stack[len-2]){
			book[len]=0;
		}
		else if(len>=3&&stack[len]>stack[len-2]){
			book[len]=1;
		}
		else if(len>=2){
			if(book[len-1]==0){
				book[len]=0;
			}
			else book[len]=1;
		}
	}
	for(int i=n-1;i>=0;i--){
		cout<<num[i]<<' '<<ans[i]<<endl;
	}
	
	
	return 0;
}










