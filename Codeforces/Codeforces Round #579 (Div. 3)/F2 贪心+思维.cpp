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
using namespace std;
struct Node{
	int a,b;
}node[105],node1[105];
int book[105];
bool cmp(Node a,Node b){
	return a.a<b.a;
}
bool cmp1(Node a,Node b){
	return a.a>b.a;
}

int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	
	int cnt=0,cnt1=0;
	int num=0;
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
			break;
		}
		num++;
		r+=node[i].b;
	}
	for(int i=1;i<=cnt1;i++){
		if(node1[i].a<=r&&r+node1[i].b>=0){
			num++;
			r+=node1[i].b;
			book[i]=1;
			continue;
		}	
		int id=0;
		int maxn=r;
		for(int j=i-1;j>=1;j--){
			if(book[j]){
				int t=r-node1[j].b;
				if(node1[i].a<=t&&t+node1[i].b>=0){
					if(maxn<t+node1[i].b){
						maxn=t+node1[i].b;
						id=j;
					}
				}	
			}
		}
		if(id==0)continue;
		r=maxn;
		book[i]=1;
		book[id]=0;
		id=0;
		maxn=0;
		for(int j=i-1;j>=1;j--){
			if(book[j]==0){
				if(r>=node1[j].a&&r+node1[j].b>=0){
					if(id==0||maxn<r+node1[j].b){
						id=j;
						maxn=r+node1[j].b;
						
					}
				}
			}
		}
		if(id==0)continue;
		book[id]=1;
		num++;
		r=maxn;
	}
	printf("%d\n",num);
	return 0;
}