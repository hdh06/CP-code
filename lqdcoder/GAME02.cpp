#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 3;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int n; cin >> n;
	ll arr[N] = {};	
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	ll dp[N + 3] = {};
	for (int i = 1; i <= n + 2; i++)
		dp[i + 3] = max({dp[i - 2 + 3] + arr[i], dp[i - 3 + 3] + arr[i - 1] + arr[i], dp[i - 4 + 3] + arr[i - 2] + arr[i - 1]});
	
	cout << *max_element(dp, dp + N + 3);
	return 0;
}