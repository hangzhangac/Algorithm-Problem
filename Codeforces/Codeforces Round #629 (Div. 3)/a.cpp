#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int T;
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b;
		if(!(a%b)){
			printf("0\n");
			continue;
		}
		cout<<(a/b+1)*b-a<<endl;
		
	}
}