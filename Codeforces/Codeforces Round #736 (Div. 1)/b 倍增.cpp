#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;

int n;
ll a[maxn];
ll b[maxn];
ll f[maxn][20];//f[i][j]表示从i位起的2^j个数中的最大数，即[i,i+(1<<j)-1]
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
void ST_prewoek()
{
	for(int i=0;i<n;i++) f[i][0]=a[i];
	for(int i=1,imax=log2(n);i<=imax;i++)
		for(int j=0;j+(1<<i)-1<n;j++)//注意j的右端点为j+(1<<i)-1，-1是因为要包含j自己 
			f[j][i]=gcd(f[j][i-1],f[j+(1<<i-1)][i-1]);
}

ll ST_query(int l,int r)//求[l,r]中的最大值 
{
	int k=log2(r-l+1);
	return gcd(f[l][k],f[r-(1<<k)+1][k]);
}
int main()
{
	int T;scanf("%d",&T);while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%lld",&b[i]);
		for(int i=1;i<n;i++){
			a[i-1]=abs(b[i]-b[i-1]);
		}
		n--;
		ST_prewoek();
		int ans=0;
		for(int i=0;i<n;i++){
			int j=i+ans;
			while(j<n&&ST_query(i, j)!=1){
				ans++;
				j++;
			}
		}
		printf("%d\n",ans+1);
	}
	return 0;
}
