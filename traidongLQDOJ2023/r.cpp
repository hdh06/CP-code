#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;

int main(){
	int n; cin >> n;
	vector<int> z;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		z.push_back(x);
	}
	
	bool dp[N] = {};
	dp[0] = 1;
	for (auto x: z)
		for (int i = x; i < N; i++)
			dp[i] |= dp[i - x];
	
	int pos = 0;
	for (int i = 0; i < N; i++) if (dp[i] == 0) pos = i;
	cout << pos << "\n";
	return 0;
}