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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n,h;
int l[MAXN],r[MAXN];
int main(){
	gi2(n, h);
	r[0]=-1000000001;
	for(int i=1;i<=n;i++){
		gi2(l[i], r[i]);
		if(l[i]==r[i-1]){
			r[i-1]=r[i];
			n--;i--;
		}
	}
	int p=1;
	int cur=1;
	int sum=r[1]-l[1];
	int h1=h;
	int maxn=0;
	int flag=0;
	while(1){
		while(cur+1<=n&&h>l[cur+1]-r[cur]){
			sum+=r[cur+1]-r[cur];
			h-=l[cur+1]-r[cur];
			cur++;
		}
		if(cur>=n){
			sum+=h;
			maxn=max(maxn,sum);
			break;
		}
		else{
			maxn=max(maxn,sum+h);
			while(p<cur&&h<=l[cur+1]-r[cur]){
				h+=l[p+1]-r[p];
				sum-=-l[p]+r[p];
				sum-=l[p+1]-r[p];
				p++;
			}
			if(p==cur){
				maxn=max(maxn,sum+h);
				p++;
				cur++;
				sum=r[cur]-l[cur];
				h=h1;
				//sum=0;
			}
			else{
				
			}
		}
	}
	
	
	printf("%d\n",maxn);
	return 0;
}