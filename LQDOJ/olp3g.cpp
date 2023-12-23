#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1919
#endif

using namespace std;

int const N = 1e6 + 1;

typedef long long ll;

int n;
int w[N];

vector<pair<int, int> > edges;
#define st first
#define nd second

ll ans = 0;

int Link[N], sz[N];

void DSUinit(){
	iota(Link, Link + N, 0);
	fill(sz, sz + N, 1);
}

int find(int v){
	return Link[v] = (Link[v] != v? find(Link[v]): v);
}

bool unite(int a, int b, int w){
	a = find(a);
	b = find(b);
	
	if (a == b) return false;
	ans += 1LL * sz[a] * sz[b] * w;
	sz[a] += sz[b];
	Link[b] = a;
	return true;
}

int main(){
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	
	
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		edges.push_back({a, b});
	}
	
	//max
	sort(edges.begin(), edges.end(), [&](pair<int, int> a, pair<int, int> b){
		return max(w[a.st], w[a.nd]) < max(w[b.st], w[b.nd]);
	});
	
	DSUinit();
	for (int i = 0; i < n - 1; i++)
		unite(edges[i].st, edges[i].nd, max(w[edges[i].st], w[edges[i].nd]));
	
	//min
	sort(edges.begin(), edges.end(), [&](pair<int, int> a, pair<int, int> b){
		return min(w[a.st], w[a.nd]) > min(w[b.st], w[b.nd]);
	});
	
	DSUinit();
	for (int i = 0; i < n - 1; i++)
		unite(edges[i].st, edges[i].nd, -min(w[edges[i].st], w[edges[i].nd]));
		
	cout << ans;
	return 0;
	
	
}