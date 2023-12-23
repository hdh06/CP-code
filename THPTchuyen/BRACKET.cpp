#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e5;
int const N = 21;

int n; string s;
int dp[N][N][N][N];

string f;

int calc(int i, int a, int b, int c){
	if (i == n){
		if (a == 0 && b == 0 && c == 0) cerr << f << "\n";
		return (a == 0 && b == 0 && c == 0);
	}
	if (a < 0 || b < 0 || c < 0) return 0; 

	int &ans = dp[i][a][b][c];
	// if (ans != -1) return ans;
	ans = 0;
	if (s[i] == '?' || s[i] == '(') f = f + '(', (ans += calc(i + 1, a + 1, b, c)) %= MOD, f.pop_back();
	if (s[i] == '?' || s[i] == ')') f = f + ')', (ans += calc(i + 1, a - 1, b, c)) %= MOD, f.pop_back();
	if (s[i] == '?' || s[i] == '[') f = f + '[', (ans += calc(i + 1, a, b + 1, c)) %= MOD, f.pop_back();
	if (s[i] == '?' || s[i] == ']') f = f + ']', (ans += calc(i + 1, a, b - 1, c)) %= MOD, f.pop_back();
	if (s[i] == '?' || s[i] == '{') f = f + '{', (ans += calc(i + 1, a, b, c + 1)) %= MOD, f.pop_back();
	if (s[i] == '?' || s[i] == '}') f = f + '}', (ans += calc(i + 1, a, b, c - 1)) %= MOD, f.pop_back();
	return ans;
}

int main(){
	cin >> n;
	cin >> s;
	memset(dp, -1, sizeof dp);
	cout << calc(0, 0, 0, 0);
	return 0;
}