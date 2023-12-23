#include <bits/stdc++.h>

using namespace std;

int const N = 3e5 + 1;

int n, m;
vector<int> g[N];

int vis[N];
int f[N], p[N];

void DFS(int v){
	if (vis[v]) return;
	vis[v] = 1;
	f[v] = 1; 
	for (auto u: g[v]){
		DFS(u);
		if (f[v] < f[u] + 1){
			f[v] = f[u] + 1;
			p[v] = u;
		}
	}
}

#define file "harem"
#define st first
#define nd second

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);
	cin >> n >> m;
	vector<pair<int, int> > edges;
	while (m--){
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		edges.push_back({x, y});
	}

	for (int i = 1; i <= n; i++) DFS(i);

	int pos = -1;
	for (int i = 1; i <= n; i++)
		if (f[i] == n) pos = i;

	if (pos == -1) cout << -1;
	else{
		int ans = 0, cnt = 0;
		bool vis[N] = {};
		for (; ans < edges.size(); ans++){
			if (p[edges[ans].st] == edges[ans].nd){
				if (!vis[edges[ans].st])
					vis[edges[ans].st] = 1, cnt++;
			}
			if (cnt == n - 1) break;
		}
		cout << ans + 1 << "\n";
		for (int i = 1; i <= n; i++){
			cout << pos << " ";
			pos = p[pos];
		}
	}
	return 0;
}
