#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef array<int, 3> iii;
typedef array<int, 2> ii;

int const N = 2e5 + 1;
int const L = 20;

int link[N];

int find(int x){
	if (x != link[x]) return link[x] = find(link[x]);
	return x;
}

bool unite(int a, int b){
	a = find(a), b = find(b);
	if (a == b) return false;
	link[a] = b;
	return true;
}

vector<ii> tree[N];

int p[N][L], h[N];
int rmq[N][L] = {};
void DFS(int v){
	for (auto u: tree[v]) if (u[0]!= p[v][0]){
		p[u[0]][0] = v;
		for (int j = 1; j < L; j++)
			p[u[0]][j] = p[p[u[0]][j - 1]][j - 1];
		rmq[u[0]][0] = u[1];
		for (int j = 1; j < L; j++)
			rmq[u[0]][j] = max(rmq[u[0]][j - 1], rmq[p[u[0]][j - 1]][j - 1]);
		h[u[0]] = h[v] + 1;
		DFS(u[0]);
	}
}

int LCA(int a, int b){
	if (h[a] > h[b]) swap(a, b);
	int k = h[b] - h[a];
	for (int i = 0; i < L; i++) if (k & (1 << i))
		b = p[b][i];

	if (a == b) return a;

	for (int i = log2(h[a]); i >= 0; i--)
		if (p[a][i] != p[b][i])
			a = p[a][i], b = p[b][i];
	return p[a][0];
}

int maxq(int a, int b){
	if (a == b) return 0;
	int ans = 0, k = log2(h[a] - h[b]);
	for (int i = 0, v = a; i < L; i++) if (k & (1 << i)){
		ans = max(ans, rmq[v][i]);
		v = p[v][i];
	}
	return ans;
}

int calc(int a, int b){
	int anc = LCA(a, b);
	return max(maxq(a, anc), maxq(b, anc));
}

int main(){
	int n, m; cin >> n >> m;
	iii g[N], h[N];
	for (int i = 1; i <= m; i++) {
		cin >> g[i][1] >> g[i][2] >> g[i][0];
		h[i] = g[i];
	}

	sort(g + 1, g + m + 1);

	for (int i = 1; i <= n; i++) link[i] = i;

	ll ans = 0;
	
	for (int i = 1; i <= m; i++){
		if (unite(g[i][1], g[i][2])){
			// cout << "+"<< g[i][1] << ' ' << g[i][2] << " " << g[i][0] << "\n";
			ans += g[i][0];
			int a = g[i][1], b = g[i][2];
			tree[a].push_back({b, g[i][0]});
			tree[b].push_back({a, g[i][0]});
		}
	}

	DFS(1);

	auto check = [&](int a, int b){
		for (auto v: tree[a]) if (v[0] == b) return true;
		return false;
	};

	for (int i = 1; i <= m; i++){
		int a = h[i][1], b = h[i][2];
		if (check(a, b))
			cout << ans << "\n";
		else{			
			cout << ans + (ll)h[i][0] - (ll)calc(a, b) << "\n";
			// cout << calc(h[i][1], h[i][2]) << "\n";
		}
	}
	return 0;
}