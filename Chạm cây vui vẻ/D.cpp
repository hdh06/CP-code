#include <bits/stdc++.h>

using namespace std;

int const N = 4e5 + 1;

int n, m;
vector<int> g[N];

int c[N], trv[N], sz[N], id = 0;

void DFS(int v, int p = 0){
	trv[v] = ++id, sz[v] = 1;
	for (auto u: g[v]) if (u != p){
		DFS(u, v);
		sz[v] += sz[u];
	}
}

typedef long long ll;

ll tree[N << 2];
int lz[N << 2];
void down(int x){
	if (!lz[x]) return;
	tree[2 * x] = 1LL << lz[x];
	tree[2 * x + 1] = 1LL << lz[x];
	lz[2 * x] = lz[x];
	lz[2 * x + 1] = lz[x];
	lz[x] = 0;
}
void upd(int L, int R, int val, int x = 1, int l = 1, int r = n){
	if (R < l || r < L) return;
	if (L <= l && r <= R){
		tree[x] = 1LL << val;
		lz[x] = val;
		return;
	}
	down(x);
	int mid = (l + r) >> 1;
	upd(L, R, val, 2 * x, l, mid);
	upd(L, R, val, 2 * x + 1, mid + 1, r);
	tree[x] = tree[2 * x] | tree[2 * x + 1];
}
ll get(int L, int R, int x = 1, int l = 1, int r = n){
	if (R < l || r < L) return 0;
	if (L <= l && r <= R) return tree[x];
	down(x);
	int mid = (l + r) >> 1;
	return get(L, R, 2 * x, l, mid) | get(L, R, 2 * x + 1, mid + 1, r);
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	DFS(1);

	for (int i = 1; i <= n; i++)
		upd(trv[i], trv[i], c[i]);

	while (m--){
		int t; cin >> t;
		if (t == 1){
			int v, c;
			cin >> v >> c;
			upd(trv[v], trv[v] + sz[v] - 1, c);
		}else{
			int v; cin >> v;
			cout << __builtin_popcountll(get(trv[v], trv[v] + sz[v] - 1)) << "\n";
		}
	}
	return 0;
}