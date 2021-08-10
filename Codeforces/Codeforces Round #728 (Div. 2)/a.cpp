#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int T;cin>>T;
	while(T--){
		int n;
		cin>>n;
//		if(n<=3){
//			cout<<n;
//			for(int i=1;i<=n-1;i++){
//				cout<<" "<<i;
//			}
//			cout<<endl;
//		}
	//	else{
			if(n&1){
				for(int i=1;i<=n-3;i+=2){
					cout<<i+1<<' '<<i<<' ';
				}
				cout<<n-1<<' '<<n<<' '<<n-2;
			}
			else{
				for(int i=1;i<=n;i+=2){
					cout<<i+1<<' '<<i<<' ';
				}
			}
			cout<<endl;
			
			//}
		
	}
}