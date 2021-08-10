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
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=2000005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
#define mem(a,x) memset(a,x,sizeof(a))  
int cnt=0,cnt1=1;
int k;
struct Trie{  
	int child[2000005][26];  
	int val[2000005];  
	int nn[2000005];
	int size;  
	void init(){  
		memset(child[0],0,sizeof(child[0]));  
		mem(nn,0);
		size=1;
	}  
	void insert(char p[]){  
		int base='A';  
		int u=0;  
		int len=strlen(p);  
		for(int i=0;i<len;i++){  
			if(!child[u][p[i]-base]){ 
				mem(child[size],0);
				val[u]=0;  
				child[u][p[i]-base]=size++;  
			}  
			val[u]++;  
			u=child[u][p[i]-base];  
		}  
		nn[u]++;
	}  
	bool query(char p[]){  
		int u=0;  
		int len=strlen(p);  
		for(int i=0;i<len;i++){  
			if(!child[u][p[i]-'A'])return 0;  
			u=child[u][p[i]-'A'];  
		}  
		return 1;  
	}
	int dfs(int u,int cur){
		int num=nn[u];
		for(int i='A';i<='Z';i++){
			if(child[u][i-'A']){
				num+=dfs(child[u][i-'A'],cur+1);
			}
		}
		cnt+=num/k*cur;
		return num%k;
	}  
}trie;  
char ps[MAXN];
int main(){
	
	int T;gi(T);
	while(T--){
		cnt=0;
		trie.init();
		int n;gi(n);gi(k);
		while(n--){
			cin>>ps;
			//cout<<ps<<endl;
			trie.insert(ps);
		}
		trie.dfs(0, 0);
		printf("Case #%d: %d\n",cnt1++,cnt);
	}
	return 0;
}