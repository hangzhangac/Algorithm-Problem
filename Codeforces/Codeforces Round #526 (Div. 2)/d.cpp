#include <bits/stdc++.h>
using namespace std;

int w[300005];
struct E
{
	int v, c;
};

vector<E> G[300005];

long long up[300005], f[300005];

void dfs(int u, int p)
{
	up[u] = f[u] = w[u];
	long long best = 0;
	for (E e: G[u]) {
		int v = e.v, c = e.c;
		if (v == p)
			continue;
		dfs(v, u);
		if (c <= up[v]) {
			//u是x的祖先 up[u]代表x到u所得汽油的最大值
			up[u] = max(up[u], up[v] - c + w[u]);
			f[u] = max(f[u], w[u] + best + up[v] - c);//从u的另一个子树 走到当然这棵子树的最大值
			best = max(up[v] - c, best);//从某棵子树走到u的最大值
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i < n; i++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		G[u].push_back({v, c});
		G[v].push_back({u, c});
	}
	dfs(1, 0);
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i]);
	cout << ans << '\n';
	return 0;
}