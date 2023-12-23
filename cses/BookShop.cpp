#include <bits/stdc++.h>

using namespace std;

int const N = 1001;
int const X = 1e5 + 1;

int main(){
	int n, x;

	cin >> n >> x;

	int h[N], s[N];
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> s[i];

	int dp[X] = {};
	for (int i = 1; i <= n; i++){
		for (int j = x; j >= h[i]; j--)
			dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
	}

	cout << *max_element(dp, dp + x + 1);
	return 0;
}
