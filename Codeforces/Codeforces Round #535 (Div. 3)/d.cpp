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
string s;
char a[]={'R','G','B'};
int main(){
	
	int n;
	gi(n);
	cin>>s;
	if(n==1){
		printf("0\n");
		cout<<s<<endl;
		return 0;
	}
	int cnt=0;
	for(int i=0;i<s.size()-1;i++){
		if(s[i]==s[i+1]){
			if(i+2>=s.size()){
				for(int j=0;j<3;j++){
					if(a[j]!=s[i]){
						s[i+1]=a[j];
						break;
					}
				}
			}
			else{
				for(int j=0;j<3;j++){
					if(a[j]!=s[i]&&a[j]!=s[i+2]){
						s[i+1]=a[j];
						break;
					}
				}
			}
			cnt++;
		}
	}
	printf("%d\n",cnt);
	cout<<s<<endl;
	
	
	
	
	return 0;
}