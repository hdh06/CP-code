#include <bits/stdc++.h>

using namespace std;

int const N = 1e5;
typedef array<int, 3> a3;
vector<a3> lgraph;

int link[N], sze[N];

bool comp(a3 a, a3 b){
	return a[2] > b[2];
}

int find(int v){
	while (v != link[v]) v = link[v];
	return v;
}

bool same(int a, int b){
	return find(a) == find(b);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);

	if (sze[a] < sze[b]) swap(a, b);

	sze[a] += sze[b];
	link[b] = link[a];
}

int main(){
	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) link[i] = i;
	for (int i = 1; i <= n; i++) sze[i] = 1;
	int tong = 0;
	while(m--){
		int v, u, w;
		cin >> v >> u >> w;
		lgraph.push_back({v,u,w});
		tong += w;
	}

	sort (lgraph.begin(), lgraph.end(), comp);

	for (auto a: lgraph){
		if (!same(a[0], a[1])){
			unite(a[0], a[1]);
			tong -= a[2];
		} 
	}

	cout << tong;

	return 0;
}