#include <bits/stdc++.h>

using namespace std;

int const N = 3e5 + 1;

int n, q;
int arr[N];

bool check1(){
	for (int i = 1; i <= n; i++) if (__builtin_popcount(arr[i]) > 1) return false;
	return true;
}

namespace sub12{
	vector<int> g[N];
	bitset<3001> f[3001];
	void DFS(int v){
		if (f[v] != 0) return;
		for (auto u: g[v]){
			DFS(u);
			f[v] |= f[u];
		}
		f[v][v] = 1;
	}

	void solve(){
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++) if (arr[i] & arr[j]){
				g[i].push_back(j);
			}
		}

		for (int i = 1; i <= n; i++)
			DFS(i);
		
		while (q--){
			int x, y; cin >> x >> y;
			cout << (f[x][y]? "Yes\n": "No\n");
		}
	}
}

namespace sub3{
	void solve(){
		while (q--){
			int x, y; cin >> x >> y;
			if (arr[x] & arr[y]) cout << "Yes\n";
			else cout << "No\n";
		}
	}
}

namespace sub4{
	int const L = 30;
	int next[L], minn[L][N];

	bool bit(int k, int x){
		return (x >> k) & 1;
	}
	
	void solve(){
		int i, j, k;

		for (i = 0; i < L; ++i){
			next[i] = n + 1;
			for (int j = 1; j <= n; j++)
				minn[i][j] = n + 1;
		}
		
		for (j = n; j >= 1; --j){
			if (j < n)
				for (i = 0; i < L; ++i) 
					if (bit(i, arr[j + 1]))
						next[i] = j + 1;
			for (k = 0; k < L; k++) if (bit(k, arr[j])){
				minn[k][j] = j;
				if (next[k] <= n)
					for (i = 0; i < L; i++) 
						minn[i][j] = min(minn[i][j], minn[i][next[k]]);
				next[k] = j;
			}
		}
		int l, r; 
		bool y = 0;
		while (q--){
			cin >> l >> r;
			y = 0;
			for (i = 0; i < L; ++i)
				if (bit(i, arr[r]) && minn[i][l] <= r){
					y = 1;
					break;
				}
			if (y) cout << "Yes\n"; else cout << "No\n";
		}
	}
}

#define file "and"

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout); 
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	if (check1()) 
		sub3::solve();
	else if (n <= 3000) 
		sub12::solve();
	else 
		sub4::solve();
	return 0;
}
