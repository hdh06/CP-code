#include <bits/stdc++.h>

using namespace std;

int const N = 1001;
int const INF = 2000;
int const MSUM = 5001;

int n;
string e;
int s = 0;

int num(char c){return c - '0';}

int dp[N][MSUM][2];

int emrua(int i, int sum, bool is){
	if (i == n) return (sum == s? is: INF);

	if (dp[i][sum][is] != -1) return dp[i][sum][is];

	if (e[i] == '0') return dp[i][sum][is] = emrua(i + 1, sum, 1);
	
	int ans = INF, tmp_s = 0;
	for (int j = i; j < n; j++){
		tmp_s = tmp_s * 10 + num(e[j]);
		if (sum + tmp_s > s) break;
		ans = min(ans, emrua(j + 1, sum + tmp_s, 0) + 1);
	}

	return dp[i][sum][is] = ans;
}

int main(){
	cin >> e;
	n = e.size();

	int i = 0;
	while (e[i] != '=') i++;
	for (int j = i + 1; j < n; j++)
		s = s * 10 + num(e[j]);
	e.erase(e.begin() + i, e.end());
	n = e.size();

	memset(dp, -1, sizeof dp);

	cout << emrua(0, 0, 0) - 1;
	return 0;
}