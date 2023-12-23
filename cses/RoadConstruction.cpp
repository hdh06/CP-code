#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;
int n, m, z;
int link[N], sz[N];

int maxc = 1;

int find(int v){
	while (v != link[v]) v = link[v];
	return v;
}

void unite(int a, int b){
	a = find(a);
	b = find(b);

	if (a == b){
		return;
	}

	z--;

	if (sz[a] < sz[b]) swap(a, b);

	sz[a] += sz[b];
	maxc = max(maxc, sz[a]);
	link[b] = link[a];
}

void print(){
	cout << z << " " << maxc << endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("in.inp", "r", stdin); freopen("out.out", "w", stdout);
	cin >> n >> m;
	z = n;
	for (int i = 1; i <= n; i++) link[i] = i;
	for (int i = 1; i <= n; i++) sz[i] = 1;

	while (m--){
		int u, v;
		cin >> u >> v;
		unite(u, v);
		print();
	}
	return 0;
}