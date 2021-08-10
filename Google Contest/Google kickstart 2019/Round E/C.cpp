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
#define LL long long

#define MAX_L 1000007
#define MAX_SORT_B 1000007

bool is_prime[MAX_L];
bool is_prime_small[MAX_SORT_B];

//对区间[a,b)内的整数执行筛法。isprime[i - a]=true <=> i是素数

void segment_sieve(LL a,LL b)
{
	for(int i=0; (LL)i*i < b; i++)is_prime_small[i]=true;
	for(int i=0; i<b-a; i++)is_prime[i]=true;
	for(int i=2; (LL)i * i<b; i++)
	{
		if(is_prime_small[i])
		{
			for(int j=2*i; (LL)j * j < b; j += i)
			{
				is_prime_small[j]=false;//筛[2,sqrt(b))
			}
			for(LL j=max(2LL, (a+i-1)/i)*i ; j<b; j+=i) //(a+i-1)/i为[a,b)区间内的第一个数至少为i的多少倍.
			{
				is_prime[j - a] =false;//筛[a,b)
			}
		}
	}
}
int main(){
	
	
	int T;gi(T);
	int cnt1=1;
	while(T--){
		long long a,b;
		int cnt=0;
		gll2(a,b);
		if(2>=a&&2<=b)cnt--;
		b++;
		
		for(int j=0; j<b-a; j++)
		{
			is_prime[j]=false;
		}
		segment_sieve(a,b);
		for(int j=0; j<b-a; j++)
		{
			if(is_prime[j])cnt++;
			is_prime[j]=false;
		}
		for(int i=a;i<b;i++){
			if(i%2==0){
				int t=i/2;
				if(t&1)cnt++;
			}
		}
		b--;
		if(a%4==0){
			a/=4;
		}
		else{
			a/=4;
			a++;
		}
		b/=4;
		b++;
		for(int j=0; j<b-a; j++)
		{
			is_prime[j]=false;
		}
		if(b>a)
			segment_sieve(a, b);
		for(int j=0; j<b-a; j++)
		{
			if(is_prime[j])cnt++;
			is_prime[j]=false;
		}
		printf("Case #%d: %d\n",cnt1++,cnt);
	}
	return 0;
}