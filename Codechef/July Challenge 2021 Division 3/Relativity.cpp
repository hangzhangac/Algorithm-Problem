#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int T;cin>>T;
	while(T--){
		int g,c;
		cin>>g>>c;
		cout<<c*c/(2*g)<<endl;
	}
	return 0;
}