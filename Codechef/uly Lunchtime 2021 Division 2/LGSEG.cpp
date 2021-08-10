#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
const int maxn=1e5+10;

int n,k,s;
int a[maxn];
int f[maxn][20];//f[i][j]表示从i位起的2^j个数中的最大数，即[i,i+(1<<j)-1] 
void ST_prework()
{
	for(int i=0;i<n;i++) f[i][0]=a[i];
	for(int i=1,imax=log2(k);i<=imax;i++)
		//for(int j=0;j+(1<<i)-1<n;j++)//注意j的右端点为j+(1<<i)-1，-1是因为要包含j自己
		for(int j=0;j<n;j++)
			f[j][i]=f[f[j][i-1]][i-1];
			//f[j][i]=max(f[j][i-1],f[j+(1<<i-1)][i-1]);
}
int main()
{
	int T;gi(T);while(T--){
		cin>>n>>k>>s;
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<n;i++){
			for(int j=0;j<20;j++)f[i][j]=0;
		}
		for(int j=0;j<20;j++)f[n][j]=n;
		int r=0;
		ll sum=0;
		for(int i=0;i<n;i++){
			while(r<n&&sum+a[r]<=s){
				sum+=a[r];
				r++;
			}
			sum-=a[i];
			a[i]=r;
		}
		ST_prework();
		vector<int>tmp;
		while(k){
			tmp.push_back(k&1);k>>=1;
		}
		int maxn=0;
		for(int i=0;i<n;i++){
			int cur=i;
			for(int j=tmp.size()-1;j>=0;j--){
				if(tmp[j])
					cur=f[cur][j];
				if(cur==n)break;
			}
			maxn=max(cur-i,maxn);
		}
		cout<<maxn<<endl;
		
	}
		
	return 0;
}
