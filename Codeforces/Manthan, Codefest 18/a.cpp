#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
	long long n;
	cin>>n;
	long long q=1;
	int cnt=0;
	while(n&&n>=q){
		n-=q;
		cnt++;
		q*=2;
	}
	if(n)cnt++;
	cout<<cnt<<endl;
}