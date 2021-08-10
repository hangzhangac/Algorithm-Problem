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
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
const int MAX_N = 5205;
bool A[MAX_N][MAX_N];
bool B[MAX_N][MAX_N];
int C[MAX_N][MAX_N/4];
char s[MAX_N];
using namespace std;
int n, cur;


bool qqa(int n, int xx) {
	if (!cur) {
		for (int i = 0; i < n / xx; i++) {
			for (int j = 0; j < n / xx; j++) {
				int mm = i * xx, nn = j * xx;
				bool t1 = A[mm][nn];
				for (int k = 0; k < xx; k++) {
					for (int s = 0; s < xx; s++) {
						if (t1^A[mm+k][nn+s]) {
							return false;
						}
					}
				}
				B[i][j] = t1;
			}
		}
		cur ^= 1;
		return true;
	}
	else {
		for (int i = 0; i < n / xx; i++) {
			for (int j = 0; j < n / xx; j++) {
				int mm = i * xx, nn = j * xx;
				bool t = B[mm][nn];
				for (int k = 0; k < xx; k++) {
					for (int s = 0; s < xx; s++) {
						if (t^B[mm + k][nn + s]) {
							return false;
						}
					}
				}
				A[i][j] = t;
			}
		}
		cur ^= 1;
		return true;
	}
}

void rra() {
	int x = n; int ddls = 1, t = n;
	for (int i = 2; i <= n; i++) {
		if (x%i == 0) {
			while (x%i == 0) {
				if (qqa(t, i)==true) {
					ddls *= i;
					t /= i;
				}
				x /= i;
			}
		}
	}
	cout << ddls << endl;
}

vector<int> change(char q){
	int cur=0;
	if(q>='A'&&q<='F'){
		cur=q-'A'+10;
	}
	else cur=q-'0';
	vector<int>ddls;
	while(cur){
		ddls.push_back(cur%2);
		cur/=2;
	}
	while(ddls.size()<4){
		ddls.push_back(0);
	}
	for(int i=0,j=3;i<j;i++,j--){
		swap(ddls[i],ddls[j]);
	}
	return ddls;
}
int main() {
	
	 cin >> n;
		 for (int i = 0; i < n; i++) {
			 scanf("%s", s);
			 for (int j = 0; j < n / 4; j++) {
				 if ('A' <= s[j]) C[i][j] = s[j] - 'A' + 10;
				 else C[i][j] = s[j] - '0';
			 }
		 }
		 for (int i = 0; i < n; i++) {
			 for (int j = 0; j < n/4; j++) {
				 for (int k = 0; k < 4; k++) {
					 A[i][4 * j + 3-k] = (C[i][j] >> k & 1);
				 }
			 }
		 }
	rra();
}