#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;

int const N = 4e5 + 1;

int n, q;
int t[N];

vector<int> g[N];
int id = 0, cycleId[N], cycle[N], cycleLen[N];

bool vis[N];
deque<int> path;
void DFS(int v){
	path.push_back(v);
	if (vis[v]) return;
	vis[v] = 1;
	DFS(t[v]);
}

int h[N];
void calc(int v){
	for (auto u: g[v]){
		h[u] = h[v] + 1; 
		calc(u);
	}
}

int jump[N][25];

int main(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> t[i];	
		
	id = n;
	for (int i = 1; i <= n; i++){
		path.clear();
		DFS(i);
		
		while (path.front() != path.back()) path.pop_front();
		if (path.size() < 2) continue;
		path.pop_back();
		++id, cycleLen[id] = path.size();
		int cid = 0;
		for (auto x: path){
			cycleId[x] = ++cid;
			cycle[x] = id;
		}
	}
	
	for (int i = 1; i <= n; i++){
		if (cycle[i]) continue;
		if (cycle[t[i]])
			g[cycle[t[i]]].push_back(i);
		else g[t[i]].push_back(i);		
	}
	
	for (int i = n + 1; i <= id; i++)
		calc(i);
		
	for (int i = 1; i <= n; i++)
		jump[i][0] = t[i];
		
	for (int j = 1; j <= 24; j++)
		for (int i = 1; i <= n; i++)
			jump[i][j] = jump[jump[i][j - 1]][j - 1];
			
	// debug(cycleId[2], cycleId[3]);
	
	while (q--){
		int a, b; cin >> a >> b;
		if (cycle[a] == cycle[b] && cycle[a]){
			if (cycleId[b] < cycleId[a])
				cout << cycleLen[cycle[a]] + (cycleId[b] - cycleId[a]) << "\n";
			else cout << cycleId[b] - cycleId[a] << "\n";
			continue;
		}
		
		if (cycle[a] == cycle[b] && !cycle[a]){
			if (h[a] < h[b]){
				cout << "-1\n";
				continue;
			}
			
			int k = h[a] - h[b];
			for (int j = 0; j < 25; j++) if ((1 << j) & k)
				a = jump[a][j];
			
			if (a == b){
				cout << k << "\n";
			}else cout << "-1\n";
			continue;
		}
		
		if (!cycle[a] && cycle[b]){
			int k = h[a];
			for (int j = 0; j < 25; j++) if ((1 << j) & k)
				a = jump[a][j];
			
			if (cycle[a] == cycle[b]){
				if (cycleId[b] < cycleId[a])
					cout << k + cycleLen[cycle[a]] + (cycleId[b] - cycleId[a]) << "\n";
				else cout << k + cycleId[b] - cycleId[a] << "\n";
			}else cout << "-1\n";
			continue;
		}
		cout << "-1\n";
	}
	return 0;
}