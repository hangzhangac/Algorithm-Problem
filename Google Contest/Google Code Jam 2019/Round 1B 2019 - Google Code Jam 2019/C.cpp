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
const int MAXN=100020;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int maxn[2][MAXN][21];
int a[2][MAXN];
int n,K;
void getbestarr(int n,int arr[],int maxn[][21])//n为给定的数组的长度  
{  
	int tem = (int)floor(log2((double)n));//因为区间的最长长度是2^tem==n嘛  
	for(int i=1;i<=n;i++)  
		maxn[i][0] = arr[i];  
	for(int j=1;j<=tem;j++) //下标从1开始  
	for(int i=1;i+(1<<j)-1<=n;i++){  
		maxn[i][j] = max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);  //最大值    
	}  
}
int query(int a,int b,int t)//getwhat表示你是想取最大还是最小  
{  
	int k = log2(b-a+1);
	return max(maxn[t][a][k],maxn[t][b-(1<<k)+1][k]);  
}  
bool C(int l,int r,int id,int i,int val){
	int ans=query(l, r, id);
	int ans1=query(l, r, id^1);
	if(ans<=a[id][i]&&ans1<=val){
		return true;
	}
	else return false;
}
map< pair<int,int>, int>ms1,ms2;
int main(){
	
	int T,cnt=1;gi(T);
	while(T--){
		ms1.clear();
		ms2.clear();
		printf("Case #%d: ",cnt++);
		gi2(n,K);
		for(int i=0;i<=1;i++){
			for(int j=1;j<=n;j++)
				gi(a[i][j]);
		}
		getbestarr(n, a[0],maxn[0]);
		getbestarr(n, a[1],maxn[1]);
		ll sum=0;
		for(int i=1;i<=n;i++){
			int l=1,r=i;
			int L1=i+1,R1=i-1;
			while(l<=r){
				int mid=(l+r)/2;
				if(C(mid,i,0,i,a[0][i]+K)){
					L1=mid;
					r=mid-1;
				}
				else{
					l=mid+1;
				}
			}
			l=i,r=n;
			while(l<=r){
				int mid=(l+r)/2;
				if(C(i,mid,0,i,a[0][i]+K)){
					R1=mid;
					l=mid+1;
				}
				else r=mid-1;
			}
			int L2=i+1,R2=i-1;
			l=1,r=i;
			while(l<=r){
				int mid=(l+r)/2;
				if(C(mid,i,0,i,a[0][i]-K-1)){
					L2=mid;
					r=mid-1;
				}
				else{
					l=mid+1;
				}
			}
			
			l=i,r=n;
			while(l<=r){
				int mid=(l+r)/2;
				if(C(i,mid,0,i,a[0][i]-K-1)){
					R2=mid;
					l=mid+1;
				}
				else{
					r=mid-1;
				}
			}
			if(L1==i+1||R1==i-1)continue;
			int ss=L1;
			if(!ms1[make_pair(a[0][i], L1)]){
				
			}
			else{
				L1=ms1[make_pair(a[0][i], L1)];
			}
			ms1[make_pair(a[0][i], ss)]=i+1;
			sum+=1LL*(i-L1+1)*(R1-i+1);
			
			if(L2==i+1||R2==i-1)continue;
			ss=L2;
			if(!ms2[make_pair(a[0][i], L2)]){
				
			}
			else{
				L2=ms2[make_pair(a[0][i], L2)];
			}
			ms2[make_pair(a[0][i], ss)]=i+1;
			sum-=1LL*(i-L2+1)*(R2-i+1);
		}
		printf("%lld\n",sum);
	}
	return 0;
}