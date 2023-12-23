#include <bits/stdc++.h>

using namespace std;

int const N = 5e5 + 1;

int n;
vector<int> g[N];
int trv[N], sz[N], p[N], id = 0;

bool tree[N << 2] = {}, lz[N << 2] = {};
void down(int x){
	if (!lz[x]) return;
	tree[2 * x] = tree[2 * x + 1] = lz[2 * x] = lz[2 * x + 1] = 1;
	lz[x] = 0;
}
void upd1(int L, int R, int x = 1, int l = 1, int r = n){
	if (R < l || r < L) return;
	if (L <= l && r <= R){
		tree[x] = 1;
		lz[x] = 1;
		return;
	}
	down(x);
	int mid = (l + r) >> 1;
	upd1(L, R, 2 * x, l, mid);
	upd1(L, R, 2 * x + 1, mid + 1, r);
	tree[x] = tree[2 * x] & tree[2 * x + 1];
}
void upd2(int k, int x = 1, int l = 1, int r = n){
	if (k < l || r < k){
		return;
	}
	if (l == r){
		tree[x] = 0;
		return;
	}
	down(x);
	int mid = (l + r) >> 1;
	upd2(k, 2 * x, l, mid);
	upd2(k, 2 * x + 1, mid + 1, r);
	tree[x] = tree[2 * x] & tree[2 * x + 1];
}
bool get(int L, int R, int x = 1, int l = 1, int r = n){
	if (R < l || r < L) return 1;
	if (L <= l && r <= R) return tree[x];
	down(x);
	int mid = (l + r) >> 1;
	return get(L, R, 2 * x, l, mid) & get(L, R, 2 * x + 1, mid + 1, r);
}

void DFS(int v){
	trv[v] = ++id, sz[v] = 1;
	for (auto u: g[v]) if (u != p[v]){
		p[u] = v;
		DFS(u);
		sz[v] += sz[u];
	}
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines		

	cin >> n;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	DFS(1);

	int q; cin >> q;
	while (q--){
		int t, v; cin >> t >> v;
		if (t == 1){
			if (!get(trv[v], trv[v] + sz[v] - 1))
				upd2(trv[p[v]]);
			upd1(trv[v], trv[v] + sz[v] - 1);
		}
		if (t == 2) upd2(trv[v]);
		if (t == 3) cout << get(trv[v], trv[v] + sz[v] - 1) << "\n";
	}
	return 0;
}