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
const int MAXN=1005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n,l[MAXN],r[MAXN];
int book[MAXN];
int tl[MAXN];
int tr[MAXN];
int main(){
	gi(n);
	mem(book,0);
	for(int i=1;i<=n;i++){
		gi(l[i]);tl[i]=l[i];
	}
	for(int i=1;i<=n;i++){
		gi(r[i]);tr[i]=r[i];
	}
	int cnt1=0;
	int cur=n;
	vector<int>ans;
	int ff=1;
	while(1){
		int flag=0;
		int cnt=0;
		ans.clear();
		for(int i=1;i<=n;i++){
			if(!book[i]&&l[i]+r[i]==0){
				book[i]=cur;
				ans.push_back(i);
				cnt++;
				cnt1++;
				flag=1;
			}
		}
		cur--;
		if(!flag)break;
		for(int i=1;i<=n;i++){
			int ll=0,rr=0;
			if(!book[i]){
				if(i<ans[0]){
					rr=cnt;
				}
				else if(i>ans[ans.size()-1]){
					ll=cnt;
				}
				else{
					for(int j=0;j<ans.size()-1;j++){
						if(i>ans[j]&&i<ans[j+1]){
							ll=j+1;
							rr=cnt-j-1;
							break;
						}
					}
				}
				l[i]-=ll;
				r[i]-=rr;
				if(l[i]<0||r[i]<0){
					ff=0;
					break;
				}
			}
		}
	}
	if(cnt1!=n||ff==0){
		printf("NO\n");
	}
	else{
		printf("YES\n");
		for(int i=1;i<=n;i++){
			cout<<book[i]<<' ';
		}
	}
	return 0;
}








