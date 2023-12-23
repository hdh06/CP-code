#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

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

int main(){
	int n, m; cin >> n >> m;
	int g[N][2];
	for (int i = 1; i <= m; i++)
		cin >> g[i][0] >> g[i][1];	
	int que[N], is[N] = {};
	int q; cin >> q;
	for (int i = 1; i <= q; i++){
		cin >> que[i];
		is[que[i]] = 1;
	}

	int ans = n;
	for (int i = 1; i <= n; i++) link[i] = i;
		
	for (int i = 1; i <= m; i++) if (!is[i])
		ans -= unite(g[i][0], g[i][1]);

	vector<int> e;
	for (int i = q; i > 0; i--){
		e.push_back(ans);
		ans -= unite(g[que[i]][0], g[que[i]][1]);
	}

	reverse(e.begin(), e.end());
	for (auto x: e) cout << x << " ";

	return 0;
}