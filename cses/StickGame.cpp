#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;

int main(){
	int n, k; cin >> n >> k;
	vector<int> moves(k);
	for (auto &x: moves) cin >> x;
	
	bool dp[N] = {};
	
	for (int i = 1; i <= n; i++){
		for (auto x: moves) if (i - x >= 0)
			dp[i] |= !dp[i - x];
		cout << (dp[i]?"W":"L");
	}
	return 0;
}