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
#include <stack>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
const int MAXN = 1000002;
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const ll mod=1000000007;
const int inf=0x3f3f3f3f;
int n,a[100007];
map<int,int>ms;
vector<int>ans[MAXN];
int read()     //输入外挂
{
	int res=0,ch,flag=0;
	if((ch=getchar())=='-')
		flag=1;
	else if(ch>='0'&&ch<='9')
		res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-'0';
	return flag?-res:res;
}
//使用：  v=read();
void Out(ll a)    //输出外挂
{
	if(a>9)
		Out(a/10);
	putchar(a%10+'0');
}

int main(){
	for(int i = 2; i < MAXN; i ++){
		for(int t = i; t < MAXN; t += i){
			ans[t].push_back(i);
		}
	}
	n=read();
	for(int i = 1; i <= n; i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		int q=ans[a[i]].size()-1;
		for(int k = q;k >= 0; k--){
			ll sss = ms[ans[a[i]][k] - 1];
			if(sss != 0) ms[ans[a[i]][k]] = (ms[ans[a[i]][k]] + sss) % mod;
		}
		ms[1]++;
	}
	ll cnt=0;
	for(auto ttt : ms){
		cnt =(cnt+ ttt.second)%mod;
	}
	Out(cnt);
	return 0;
}