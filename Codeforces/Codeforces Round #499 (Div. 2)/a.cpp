//https://www.cnblogs.com/markleaf/p/7808817.html
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
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
int a[MAXN];
string s;
int main(){
	
	int n,k;
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[s[i]]++;
	}
	int flag=1;
	int minn=inf;
	for(int i='a';i<='z';i++){
		int sum=0;
		int cnt=0;
		int j=i;
		while(1){
			//cout<<1<<endl;
		if(a[j]){
			sum+=j-'a'+1;
			cnt++;
			if(cnt==k){
				flag=0;
				minn=min(minn,sum);
				break;
			}
			j+=2;
			while(j<='z'&&a[j]==0){
				j++;
				//cout<<j<<endl;
				//cout<<1<<endl;
			}
			if(j>'z'){
				break;
			}
			else{
				
			}
		}
		else break;
		}
	}
	if(flag)minn=-1;
	printf("%d\n",minn);
	
	return 0;
}






























