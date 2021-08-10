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
const int MAXN=500005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n,m;
int a[MAXN];
int f[MAXN][21];//f[i][j]表示从i位起的2^j个数中的最大数，即[i,i+(1<<j)-1] 
stack< pair<int,int> >s;
stack< pair<int,int> >s1;
//stact< pair<int,int> >s;
ll book1[MAXN];
ll book2[MAXN];
void ST_prewoek()
{
	for(int i=0;i<n;i++) f[i][0]=a[i];
	for(int i=1,imax=log2(n);i<=imax;i++)
		for(int j=0;j+(1<<i)-1<n;j++)//注意j的右端点为j+(1<<i)-1，-1是因为要包含j自己 
			f[j][i]=min(f[j][i-1],f[j+(1<<i-1)][i-1]);
}
 
int ST_query(int l,int r)//求[l,r]中的最大值 
{
	int k=log2(r-l+1);
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
vector<int>ans;
vector<int>ans1;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	ll cnt=0;
	ST_prewoek();
	for(int i=0;i<n;i++){
		int num=1;
		while(!s.empty()){
			pair<int, int>q=s.top();
			if(q.second>=a[i]){
				num+=q.first;
				cnt-=q.first*1LL*q.second;
				s.pop();
			}
			else break;
		}
		
		s.push(make_pair(num, a[i]));
		cnt+=1LL*num*a[i];
		book1[i]=cnt;
	}
	cnt=0;
	for(int i=n-1;i>=0;i--){
			int num=1;
			while(!s1.empty()){
				pair<int, int>q=s1.top();
				if(q.second>=a[i]){
					num+=q.first;
					cnt-=q.first*1LL*q.second;
					s1.pop();
				}
				else break;
			}
			s1.push(make_pair(num, a[i]));
			cnt+=1LL*num*a[i];
			book2[i]=cnt;
	}
	ll maxn=0;
	int pos=0;
	for(int i=0;i<n;i++){
		ll s=book1[i]+book2[i]-a[i];
		if(s>=maxn){
			maxn=s;
			pos=i;
		}
	}
	for(int i=pos;i<=pos;i++){
				int j=0;
				ll cnt=0;
				while(j<=i){
					int s=ST_query(j,i);
					while(j<=i&&a[j]>s){
						cnt+=s;
						j++;
						ans.push_back(s);
					}
					if(j>i){
						break;
					}
					cnt+=s;
					ans.push_back(s);
					j++;
				}
				
				j=n-1;
				while(j>=i){
					
					int s=ST_query(i,j);
					while(j>=i&&a[j]>s){
						cnt+=s;
						ans1.push_back(s);
						j--;
					}
					if(j<i){
						break;
					}
					cnt+=s;
					ans1.push_back(s);
					j--;
				}
				ans1.pop_back();
				cnt-=a[i];
				if(cnt>=maxn){
					pos=i;
				}
				maxn=max(cnt,maxn);
			}
			for(int i=0;i<ans.size();i++){
				cout<<ans[i]<<' ';
			}
			for(int i=ans1.size()-1;i>=0;i--){
				cout<<ans1[i]<<' ';
			}
	return 0;
}