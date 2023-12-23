#include <bits/stdc++.h>

using namespace std;

int hmg(int a, int b){
	return __builtin_popcount(a ^ b);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> arr(n + 1, 0);
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < k; j++){
			char c; cin >> c;
			arr[i] |= (1 << j) * (c - '0');
		}
	}

	int ans = 31;

	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			ans = min(ans, hmg(arr[i], arr[j]));

	cout << ans;
	return 0;
}