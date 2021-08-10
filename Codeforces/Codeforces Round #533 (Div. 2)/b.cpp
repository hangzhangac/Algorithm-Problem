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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
string a;
int main(){
	int n,k;
	cin>>n>>k;
	cin>>a;
	
	int maxn=0;
	for(char s='a';s<='z';s++){
		int num=0;
		int i=0;
		while(i<n){
			int cnt=0;
			while(i<n&&a[i]==s){
				i++;
				cnt++;
				if(cnt==k){
					num++;
					cnt=0;
				}
			}
			cnt=0;
			while(i<n&&a[i]!=s){
				i++;
			}
		}
		maxn=max(maxn,num);
	}
	printf("%d\n",maxn);
	
	
}