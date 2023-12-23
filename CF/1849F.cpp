#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;

int n, m, r;

vector<vector<vector<int> > > f;

void solve(){
	cin >> n >> m >> r;
	f.assign(n + 1, vector<vector<int> > (m + 1, vector<int>(r + 1, 1)));
	
	for (int i = 1; i <= r; i++){
		int t, d, c; cin >> t >> d >> c;
		
		if (d == 1){
			for (int i = 0; i <= m; i++)
				if (0 <= t - i - c && t - i - c <= r)
					f[c][i][t - i - c] = false;
		}
		if (d == 2){
			for (int i = 0; i <= n; i++)
				if (0 <= t - i - c && t - i - c <= r)
					f[i][c][t - i - c] = false;			
		}
	}
	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++){
			for (int k = 0; k <= r; k++) if (f[i][j][k]){
				if (i || j || k) f[i][j][k] = false;
				if (i) f[i][j][k] |= f[i - 1][j][k];
				if (j) f[i][j][k] |= f[i][j - 1][k];
				if (k) f[i][j][k] |= f[i][j][k - 1];
			}	
		}

	for (int k = 0; k <= r; k++){
		if (f[n][m][k]){
			cout << n + m + k << "\n";
			return;
		}
	}
	cout << "-1\n";
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	
	int t; cin >> t;
	while (t--) solve();
	return 0;
}