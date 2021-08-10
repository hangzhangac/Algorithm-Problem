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
int a[]={'R','G','B'};
int main(){
	
	int n;
	gi(n);
	cin>>s;
	sort(a,a+3);
	int cnt=0;
	int minn=inf;
	int pos=0;
	do{
		cnt++;
		int ans=0;
		for(int i=0;i<s.size();i++){
			int t=i%3;
			if(a[t]!=s[i]){
				ans++;
			}
		}
		if(minn>ans){
			minn=ans;
			pos=cnt;
		}
	}while(next_permutation(a, a+3));
	printf("%d\n",minn);
	cnt=0;
	sort(a,a+3);
	do{
		cnt++;
		int ans=0;
		for(int i=0;i<s.size();i++){
			int t=i%3;
			if(a[t]!=s[i]){
				s[i]=a[t];
			}
		}
		if(cnt==pos){
			break;
		}
	}while(next_permutation(a, a+3));
	
	cout<<s<<endl;
	
	
	
	
	return 0;
}



