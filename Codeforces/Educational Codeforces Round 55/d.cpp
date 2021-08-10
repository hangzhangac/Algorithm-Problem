#include <iostream>
#include <algorithm> 
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <functional>
const int INF=0x3f3f3f3f;
const int maxn=500+10; 
const int mod=1e9+7;
const int MOD=998244353;
const double eps=1e-7;
typedef long long ll;
#define vi vector<int> 
#define si set<int>
#define pii pair<int,int> 
#define pi acos(-1.0)
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
#define sci(x) scanf("%d",&(x))
#define scll(x) scanf("%lld",&(x))
#define sclf(x) scanf("%lf",&(x))
#define pri(x) printf("%d",(x))
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
#define mem(a,b) memset(a,b,sizeof(a)) 
using namespace std;
int n,sum,len,pos;
struct node
{
	int degree;
	int id;	
}q[maxn];
bool cmp(node a,node b)
{
	if(a.degree!=b.degree)return a.degree<b.degree;
	else return a.id<b.id;
}
vector<pii>ans;
//先连成链 再挂度为1的点 
int main()
{ 
	sci(n);
	rep(i,0,n-1)
	{
		sci(q[i].degree);
		q[i].id=i;
		sum+=q[i].degree;
	}
	if(sum<2*(n-1))return puts("NO"),0;
	sort(q,q+n,cmp);
	rep(i,0,n-1)
	{
		if(q[i].degree>=2)
		{
			pos=i;
			break;
		}
	}
	rep(i,pos,n-2)//先成链 
	{
		ans.push_back(pii(q[i].id,q[i+1].id));
		q[i].degree--,q[i+1].degree--;
	}
	len=n-1-pos;
	rep(i,0,pos-1)
	{
		if(!i)//挂头 
		{
			ans.push_back(pii(q[0].id,q[pos].id));
		    q[0].degree--,q[pos].degree--;
			len++;
		}
		else if(i==1)//挂尾 
		{
			ans.push_back(pii(q[1].id,q[n-1].id));
			q[1].degree--,q[n-1].degree--;
			len++;
		}
		else
		{
			rep(j,pos,n-1)//把剩下的点挂上 
			{
				if(!q[j].degree)continue;
				ans.push_back(pii(q[i].id,q[j].id));
				q[i].degree--,q[j].degree--;
				break;
			}
		}
	}
	printf("%s %d\n","YES",len);
	int num=ans.size();
	printf("%d\n",n-1);
	rep(i,0,num-1)
	{
		int u=ans[i].first,v=ans[i].second;
		if(u>v)swap(u,v);
		printf("%d %d\n",1+u,1+v);
	}
	return 0;
}