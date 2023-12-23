#include <bits/stdc++.h>

using namespace std;

int const N = 501;
int dp[N][N];

int dq(int a, int b){
	if (a == b) return 0;
	if (dp[a][b] != -1) return dp[a][b];

	int ans = INT_MAX;
	for (int i = 1; i <= a - 1; i++) 
		ans = min(ans, dq(i, b) + dq(a - i, b) + 1);

	for (int i = 1; i <= b - 1; i++)
		ans = min(ans, dq(a, i) + dq(a, b - i) + 1);

	return dp[a][b] = ans;
}

int main(){
	memset(dp, -1, sizeof(dp));
	int a, b; cin >> a >> b;
	cout << dq(a, b);
	return 0;
}