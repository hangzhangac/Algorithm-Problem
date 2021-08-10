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
int num[1000];
char a[MAXN];
int main(){
	int n;
	cin>>n;
	cin>>a;
	for(int i=0;i<n;i++){
		num[a[i]]++;
	}
	for(int i='a';i<='z';i++){
		for(int j=num[i];j>0;j--){
			printf("%c",char(i));
		}
	}
}
























