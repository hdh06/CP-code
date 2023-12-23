#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 5001;

int n;
ll arr[N];

ll dp[N][N] = {};

ll dequy(int l, int r){
	if (l == r) return arr[l];

	if (dp[l][r] != -1) return dp[l][r];

	return dp[l][r] = max(arr[l] - dequy(l + 1, r), arr[r] - dequy(l, r - 1));
}

int main(){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) dp[i][j] = -1;

	cin >> n;
	ll tong = 0;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		tong += arr[i];
	}
	cout << (tong + dequy(1, n))/2;
	return 0;
}