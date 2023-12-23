#include <bits/stdc++.h>

using namespace std;

int const N = 201;
int const MOD = 1e9 + 7;

string s;
int n;

int num(char c){return c - '0';}

int dp[N][9 * N];

int emrua(int i, int pre){
	if (i == n) return 1;

	if (dp[i][pre] != -1) return dp[i][pre];

	int ans = 0, sum = 0;
	for (int j = i; j < n; j++){
		sum += num(s[j]);
		if (sum < pre) continue;
		(ans += emrua(j + 1, sum)) %= MOD;
	}

	return dp[i][pre] = ans;
}


int TEST = 0;
void solve(){
	n = s.size();
	memset(dp, -1, sizeof dp);
	cout << ++TEST << ". " << emrua(0, 0) << "\n";
}

int main(){
	while (1){
		cin >> s;
		if (s == "bye") break; 
		solve();
	}
	return 0;
}