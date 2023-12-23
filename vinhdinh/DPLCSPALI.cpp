#include <bits/stdc++.h>

using namespace std;

int const N = 2001;

int main(){
	string s1, s2;
	cin >> s1;

	s2 = s1; reverse(s2.begin(), s2.end());

	s1 = ' ' + s1;
	s2 = ' ' + s2;

	int dp[N][N] = {};

	for (int i = 1; i < s1.size(); i++){
		for (int j = 1; j < s2.size(); j++){
			if (s1[i] == s2[j]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	string ans;

	for (int i = s1.size() - 1, j = s2.size() - 1; i > 0 && j > 0;){
		if (s1[i] == s2[j]){
			ans = s1[i] + ans;
			i--;
			j--;
		}
		else if (dp[i][j - 1] == dp[i][j]) j--;
		else i--;
	}

	cout << ans;
	return 0;
}