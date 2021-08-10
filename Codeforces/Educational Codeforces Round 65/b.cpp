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
using namespace std;

int q[5][2] = { {1,2},{3,4},{2,5},{3,6} };
int n,m;
int ems[4] = {};

void solve() {
	for (int i = 0; i < 4; i++) {
		cout << "? " << q[i][0] << " " << q[i][1] << endl;
		fflush(stdout);
		cin >> ems[i];
	}
}

int a[6] = { 4, 8, 15, 16, 23,  42 };

int main() {
	solve();
	do {
		bool flag = true;
		for (int i = 0; i < 4; i++) {
			if (a[q[i][0]-1] * a[q[i][1]-1] != ems[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "! ";
			for (int i = 0; i < 6; i++) cout << a[i] << " ";
			fflush(stdout);
		}
	} while (next_permutation(a, a + 6));
}