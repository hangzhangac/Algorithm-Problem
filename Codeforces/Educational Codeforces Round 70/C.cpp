#include <bits/stdc++.h>
using namespace std;
vector<int>maxid;
vector<int>minid;
string a;
int minx=0,miny=0,maxx=0,maxy=0;
bool judge(int minx,int maxx,char l,char r){
	maxid.clear();
	minid.clear();
	int x=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==r){
			x++;
		}
		else if(a[i]==l){
			x--;
		}
		if(x==maxx){
			maxid.push_back(i);
		}
		if(x==minx)minid.push_back(i);
	}
	if(maxx!=0&&(minid.empty()||maxid[0]>minid.back()))return true;
	if(minx!=0&&(maxid.empty()||minid[0]>maxid.back()))return true;
	return false;
}
int main(){
 
	int T;
	scanf("%d",&T);
	while(T--){
		cin>>a;
		int n=a.size();
		int x=0,y=0;
		minx=0,miny=0,maxx=0,maxy=0;
		for(int i=0;i<n;i++){
			if(a[i]=='A'){
				x--;
			}
			else if(a[i]=='D'){
				x++;
			}
			else if(a[i]=='W'){
				y++;
			}
			else{
				y--;
			}
			minx=min(minx,x);
			maxx=max(maxx,x);
			miny=min(miny,y);
			maxy=max(maxy,y);
		}
		long long dx=maxx-minx+1;
		long long dy=maxy-miny+1;
		long long ans=dx*dy;
		if(dx>2){
			if(judge(minx,maxx,'A','D'))
				ans=min(ans,(dx-1)*dy);
		}
		if(dy>2){
			if(judge(miny,maxy,'S','W'))
				ans=min(ans,(dy-1)*dx);
		}
		cout<<ans<<endl;
	}
	return 0;
}
