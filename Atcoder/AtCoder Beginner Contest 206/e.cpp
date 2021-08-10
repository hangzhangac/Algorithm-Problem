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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;

int solve(int r, int n) {
	vector<int>p;
	p.clear();
	for(int i = 2; i*i <= n; ++i) {
		if(n % i == 0) {
			p.push_back(i);
			while(n % i == 0) n /= i;
		}
	}
	if(n > 1) p.push_back(n); //可能n也是素数
	int sum = 0;
	for(int msk = 1; msk < (1<<p.size()); ++msk) {
		int mult = 1, bits = 0;
		for(int i = 0; i < p.size(); ++i) {
			if(msk & (1<<i)) { //选择了第i个素数因子 
				bits++;
				mult *= p[i];
			}
		}
		int cur = r / mult;
		if(bits & 1) sum += cur;
		else sum -= cur;
	}
	return r - sum;
}

int main(int argc, char *argv[]) {
	
	int l,r;
	cin>>l>>r;
	if(l==1)l++;
	ll cnt=0;
	for(int i=l;i<=r;i++){
		cnt+=solve(r, i)-solve(l-1, i);
		int x=l/i+((l%i)==0?0:1);
		if(x==1)x++;
		int y=r/i;
		if(x<=y){
			int num=(y-x+1);
			cnt+=2*num;
		}
			
	}
	cout<<1ll*(r-l+1)*(r-l)-cnt<<endl;
	
}