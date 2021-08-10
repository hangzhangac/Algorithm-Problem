#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
int mx[MAX_N*4], mn[MAX_N*4];
int a[MAX_N], c[MAX_N], p[MAX_N], b[MAX_N];
int la, ra;

void PU(int k) {
	mx[k] = max(mx[2 * k + 1], mx[2 * k + 2]);
	mn[k] = min(mn[2 * k + 1], mn[2 * k + 2]);
}

void build(int l, int r, int k) {
	if (r - l == 1) mx[k] = mn[k] = b[r];
	else {
		build(l, (l + r) >> 1, 2 * k + 1);
		build((l + r) >> 1, r, 2 * k + 2);
		PU(k);
	}
}

void change(int x, int l, int r, int k) {
	if (l > x || r <= x) return;
	if (r - l == 1) {
		mx[k] = mn[k] = b[x + 1];
	}
	else {
		change(x, l, (l + r) >> 1, 2 * k + 1);
		change(x, (l + r) >> 1, r, 2 * k + 2);
		PU(k);
	}
}

int query(int a, int b, int l, int r, int k) {
	if (a <= l && r <= b) {
		if (la <= mn[k] && mx[k] <= ra) return r - l;
		if (la > mx[k] || ra < mn[k]) return 0;
		else {
			return query(a, b, l, (l + r) >> 1, 2 * k + 1) + query(a, b, (l + r) >> 1, r, 2 * k + 2);
		}
	}
	else if (r <= a || b <= l) return 0;
	else {
		return query(a, b, l, (l + r) >> 1, 2 * k + 1) + query(a, b, (l + r) >> 1, r, 2 * k + 2);
	}
}

int main() {
	//memset(mn, 63, sizeof mn);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), p[a[i]] = i;
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++) b[i] = p[c[i]];
	build(0, n, 0);
	for (int i = 0,  l, r, mode; i < m; i++) {
		scanf("%d", &mode);
		if (mode == 1) {
			scanf("%d%d%d%d", &la, &ra, &l, &r);
			printf("%d\n", query(l-1, r, 0, n, 0));
		}
		else {
			scanf("%d%d", &l, &r);
			swap(b[l], b[r]);
			change(l - 1, 0, n, 0);
			change(r - 1, 0, n, 0);
		}
	}
	//system("pause");
}