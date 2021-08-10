#include <bits/stdc++.h>
using namespace std;
struct Node{
	int a,b;
}node[105],node1[105];
bool cmp(Node a,Node b){
	return a.a<b.a;
}
bool cmp1(Node a,Node b){
	if(a.a>=b.a){
		int t=a.a-b.a;
		int s=b.b-a.b;
		if(t>=s)return true;
		else return false;
	}
	else{
		int t=b.a-a.a;
		int s=a.b-b.b;
		if(t>=s)return false;
		else return true;
	}
}
int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	int cnt=0,cnt1=0;
	int flag=0;
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		if(b>=0){
			node[++cnt].a=a;
			node[cnt].b=b;
		}
		else{
			node1[++cnt1].a=a;
			node1[cnt1].b=b;
		}
	}
	sort(node+1,node+cnt+1,cmp);
	sort(node1+1,node1+cnt1+1,cmp1);
	for(int i=1;i<=cnt;i++){
		if(r<node[i].a){
			flag=1;break;
		}
		r+=node[i].b;
	}
	for(int i=1;i<=cnt1;i++){
		if(r<node1[i].a){
			flag=1;break;
		}
		r+=node1[i].b;
		if(r<0){
			flag=1;break;
		}
	}
	if(flag)puts("NO");
	else puts("YES");
	return 0;
}