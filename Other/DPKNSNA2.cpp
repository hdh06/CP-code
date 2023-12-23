#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 501;
int const M = 1e6 + 1;

ll dp[M] = {};

int main(){
	int n, m;
	cin >> m >> n;

	int w[N], v[N];

	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

	for (int i = 1; i <= n; i++){
		for (int j = m; j > 0; j--){
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}

	cout << *max_element(dp + 1, dp + m + 1);
	return 0;
}