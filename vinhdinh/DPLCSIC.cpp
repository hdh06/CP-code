#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int const N = 5001;

int main(){
	int n; cin >> n;
	ll a[N];
	for (int i = 1; i <= n; i++) cin >> a[i];
	int m; cin >> m;
	ll b[N];
	for (int j = 1; j <= m; j++) cin >> b[j];

	int dp[N] = {};
	for (int i = 1; i <= n; i++){
		int curr = 0;
		for (int j = 1; j <= m; j++){
			if (a[i] == b[j])
				dp[j] = max(dp[j], curr + 1);
			if (b[j] < a[i])
				curr = max(curr, dp[j]);
		}
	}
	cout << *max_element(dp, dp + m + 1);
	return 0;
}