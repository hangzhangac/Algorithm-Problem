#include <bits/stdc++.h>
using namespace std;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
vector<int>x;
vector<int>y;
vector<int>ansx,ansy;
int main(){
	int q;
	cin>>q;
	while(q--){
		int b,w,flag=0;
		cin>>b>>w;
		//2 2 white
		x.clear(),y.clear();
		ansx.clear();ansy.clear();
		if(b<w){
			swap(b,w);flag=1;
		}
		if(3*w+1<b){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		int xx=2,yy=2;
		b-=w;
		for(int i=0;i<2*w;i++){
			ansx.push_back(xx+i);
			ansy.push_back(yy);
			if(i%2==0){
				x.push_back(xx+i);
				y.push_back(yy);
			}
		}
		if(b==2*w+1){
			ansx.push_back(1);ansy.push_back(2);
			b--;
		}
		if(b>w){
			b-=w;
			for(int i=0;i<x.size();i++){
				int xx=x[i],yy=y[i];
				yy--;
				ansx.push_back(xx),ansy.push_back(yy);
			}
		}
		if(b<=w){
			for(int i=0;i<x.size()&&i<b;i++){
				int xx=x[i],yy=y[i];
				yy++;
				ansx.push_back(xx),ansy.push_back(yy);
			}
		}
		for(int i=0;i<ansx.size();i++){
			if(flag){
				printf("%d %d\n",ansx[i]+1,ansy[i]);
			}
			else printf("%d %d\n",ansx[i],ansy[i]);
		}
	}
	return 0;
}