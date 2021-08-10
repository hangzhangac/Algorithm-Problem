#include<bits/stdc++.h>
using namespace std;


typedef pair<int, int> P;
queue<P> p[10], q[10];
const int MAX_N = 1e3 + 5;
bool used[MAX_N][MAX_N];
string mp[MAX_N];
int ans[10];
int n, m, play;
int dx[4] = {1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1 };
int cnt;
int speed[10];

void move(int id) {
	while (!p[id].empty()) {
		P t = p[id].front(); p[id].pop();
		for (int i = 0; i < 4; i++) {
			int tx = dx[i] + t.first, ty = dy[i] + t.second;
			if (0 <= tx && tx < n && 0<=ty&&ty<m && !used[tx][ty]) {
				used[tx][ty] = true;
				ans[id]++;
				q[id].push(P(tx,ty));
				cnt++;
			}
		}
	}
	while (!q[id].empty()) {
		P t = q[id].front(); q[id].pop();
		p[id].push(t);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> play;
	for (int i = 1; i <= play; i++) cin >> speed[i];
	for (int i = 0; i < n; i++) cin >> mp[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mp[i][j] == '.')continue;
			if (mp[i][j] == '#') {
				used[i][j] = true;
				cnt++;
			}
			else {
				used[i][j] = true;
				int id = mp[i][j] - '0';
				//cout << "id: " << id << endl;
				p[id].push(P(i, j));
				ans[id] ++;
				//cnt++;
			}
		}
	}
	while (true) {
		for (int i = 1; i <= play; i++) {
			for (int j = 1; j <= speed[i]; j++) {
				if (p[i].empty()) break;
				move(i);
			}
		}
		bool flag = false;
		for (int i = 1; i <= play; i++) {
			if (!p[i].empty()) flag = true;
		}
		if (!flag) break;
	}
	for (int i = 1; i <= play; i++) {
		cout << ans[i] << " ";
	}
	//system("pause");
}