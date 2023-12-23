#include <bits/stdc++.h>

using namespace std;

struct node{
	int v, u;
	long long w;
};

int const N = 1e6 + 1;
vector<node> graph;
int link[N], sz[N];

int find(int v){
	while(v != link[v]) v = link[v];
	return v;
}

bool same(int a, int b){
	a = find(a);
	b = find(b);

	return a == b;
}

void unite(int a, int b){
	a = find(a);
	b = find(b);

	if (sz[a] < sz[b]) swap(a,b);

	link[b] = link[a];
	sz[a] += sz[b];
}

bool comp(node a, node b){
	return a.w < b.w;
}

bool check(int n){
	int sample = find(1);
	for (int i = 2; i <= n; i++){
		if (find(i) != sample) return 0;
	}
	return 1;
}

int main(){
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) link[i] = i;
	for (int i = 1; i <= n; i++) sz[i] = 1;

	while (m--){
		node x;
		cin >> x.v >> x.u >> x.w;
		graph.push_back(x);
	}

	sort(graph.begin(), graph.end(), comp);

	long long tong = 0;
	for (auto x: graph){
		if (!same(x.v, x.u)){
			unite(x.v, x.u);
			tong += x.w;
		} 
	}

	if (check(n)) cout << tong;
	else cout << "IMPOSSIBLE";
	return 0;
}