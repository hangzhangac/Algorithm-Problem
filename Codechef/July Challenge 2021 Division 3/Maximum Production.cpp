#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int T;cin>>T;
	while(T--){
		int d,x,y,z;
		cin>>d>>x>>y>>z;
		cout<<max(x*7,d*y+(7-d)*z)<<endl;
	}
}