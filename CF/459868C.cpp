#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 16;

int n, k;

ll dp[N][N][1 << N];

ll calc(int i, int pre, int mask){
	if (i == n) return 1;
	
	ll &ans = dp[i][pre][mask];
	if (ans != -1) return ans;
	ans = 0;
	
	for (int j = 0; j < n; j++) if ((i == 0 || abs(pre - j) <= k) && (~mask & (1 << j)))
		ans += calc(i + 1, j, mask | (1 << j));
	
	return ans;
}

int main(){
	cin >> n >> k;
	
	memset(dp, -1, sizeof dp);
	
	cout << calc(0, 0, 0) << "\n";
	return 0;
}