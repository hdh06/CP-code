#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef array<int, 3> iii;

int const N = 1e5 + 1;

vector<iii> g;

int link[N], sz[N];

int find(int x){
	return x == link[x]? x: link[x] = find(link[x]); 
}

bool unite(int a, int b){
	a = find(a);
	b = find(b);

	if (a == b) return false;

	sz[a] += sz[b];
	link[b] = a;
	return true; 
}

int main(){
	int n, m; cin >> n >> m;
	while (m--){
		int u, v, w; cin >> u >> v >> w;
		g.push_back({u, v, w});
	}

	sort(g.begin(), g.end(), [](iii a, iii b){return a[2] < b[2];});

	for (int i = 1; i <= n; i++){
		link[i] = i;
		sz[i] = 1;
	}

	ll ans = 0;
	for (auto x: g) if (unite(x[0], x[1])) ans += x[2];
		
	if (sz[find(1)] != n) cout << "IMPOSSIBLE";
	else cout << ans;
	return 0;
}