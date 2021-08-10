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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
string x[MAXN];
int main() {
	
	int T,cnt1=1;gi(T);
	while(T--){
		
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		string cur;
		string last=x[1];
		int ans=0;
		for(int i=2;i<=n;i++){
			cur=x[i];
			if(cur.size()<=last.size()){
				int flag=0;
				for(int j=0;j<cur.size();j++){
					if(cur[j]==last[j]){
						continue;
					}
					else if(cur[j]<last[j]){
						flag=1;
						ans+=last.size()-cur.size()+1;
						
						while(cur.size()!=last.size()){
							cur+="0";
						}
						cur+="0";
						break;
					}
					else{
						flag=2;
						ans+=last.size()-cur.size();
						while(cur.size()!=last.size()){
							cur+="0";
						}
						break;
					}
				}
				if(!flag){
					int idd=-1;
					for(int j=last.size()-1;j>=cur.size();j--){
						if(last[j]!='9'){
							flag=1;
							idd=j;
							break;
						}
					}
					if(flag){
						while(cur.size()!=last.size()){
							int t=cur.size();
							if(cur.size()<idd){
								cur+=last[t];
								ans++;
							}
							else if(cur.size()==idd){
								cur+=(last[t]+1);
								ans++;
							}
							else{
								cur+="0";
								ans++;
							}
						}
					}
					else{
						while(cur.size()!=last.size()){
							cur+="0";
							ans++;
						}
						ans++;
						cur+="0";
					}
				}
			}
			last=cur;
			//cout<<last<<endl;
		}
		
		
		printf("Case #%d: %d\n",cnt1++,ans);
	}
	
}




















