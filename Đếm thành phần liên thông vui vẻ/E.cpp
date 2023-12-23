#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;

map<int, int> cnt[N];
vector<int> g[N];

int n; 
int c[N];
ll w[N], maxx[N];

void merge(map<int, int> &A, map<int, int> &B, int v){
	if (A.size() < B.size()){
		swap(A, B);
	}
	for (auto &x: B){
		A[x.first] += x.second;
		if (A[x.first] > maxx[v]){
			maxx[v] = A[x.first];
			w[v] = x.first;
		}else if (A[x.first] == maxx[v])
			w[v] += x.first;
	}
	B.clear();
}

void DFS(int v, int p){
	cnt[v][c[v]]++;
	w[v] = c[v], maxx[v] = 1;
	for (auto u: g[v]) if (u != p){
		DFS(u, v);
		if (cnt[v].size() < cnt[u].size()){
			swap(cnt[v], cnt[u]);
			w[v] = w[u];
			maxx[v] = maxx[u];
			// for (auto x: cnt[v]){
			// 	if (maxx[v] < x.second){
			// 		maxx[v] = x.second;
			// 		w[v] = x.first;
			// 	}else if (x.second == maxx[v])
			// 		w[v] += x.first;
			// }
		}
		for (auto &x: cnt[u]){
			cnt[v][x.first] += x.second;
			if (cnt[v][x.first] > maxx[v]){
				maxx[v] = cnt[v][x.first];
				w[v] = x.first;
			}else if (cnt[v][x.first] == maxx[v])
				w[v] += x.first;
		}
		cnt[u].clear();
	}
	// int maxx = 0;
	// for (auto x: cnt[v]){
	// 	if (x.second > maxx){
	// 		maxx = x.second;
	// 		w[v] = x.first;
	// 	}else if (x.second == maxx)
	// 		w[v] += x.first;
	// }
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	DFS(1, 0);
	for (int i = 1; i <= n; i++)
		cout << w[i] << " ";
	return 0;
}