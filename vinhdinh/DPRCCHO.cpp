#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 6001;

ll sum[N] = {};

int n, m, k;

ll memo[N][N] = {};
bool ismemo[N][N] = {};

ll dequy(int i, int k){
	if (k <= 0 || i <= 0) return 0;

	if (ismemo[i][k]) return memo[i][k];
	ismemo[i][k] = true;

	return memo[i][k] = max(
		(i - m >= 0?dequy(i - m, k - 1) + sum[i] - sum[i - m]:0),
	 	dequy(i - 1, k)
	);
}

int main(){	
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 1, temp; i <= n; i++){
		cin >> temp;
		sum[i] = sum[i - 1] + temp;
	}
	cout << dequy(n, k);
	return 0;
}