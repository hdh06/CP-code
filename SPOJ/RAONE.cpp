#include <bits/stdc++.h>

using namespace std;

int const N = 10;
int const maxSL = 50;
int const maxSC = 50;

int f(string s){
	int n = s.size();

	int dp[N][2][maxSL][maxSC] = {};

	dp[n][0][0][0] = dp[n][1][0][0] = 1;

	for (int i = n - 1; i >= 0; i--){
		for (int tight = 0; tight < 2; tight++){
			for (int L = 0; L < maxSL; L++){
				for (int C = 0; C < maxSC; C++){
					if (tight){
						for (int d = 0; d <= s[i] - '0'; d++)
							if ((n - i) % 2 == 0){
								dp[i][1][L][C] += (d == s[i] - '0')?dp[i + 1][1][L][C - d]:dp[i + 1][0][L][C - d];
							}
							else{
								dp[i][1][L][C] += (d == s[i] - '0')?dp[i + 1][1][L - d][C]:dp[i + 1][0][L - d][C];
							}
					}
					else{
						for (int d = 0; d <= 9; d++)
							if ((n - i) % 2 == 0){
								dp[i][0][L][C] += dp[i + 1][0][L][C - d];
							}
							else{
								dp[i][0][L][C] += dp[i + 1][0][L - d][C];
							}
					}
				}
			}
		}
	}

	int ans = 0;

	for (int L = 0; L < maxSL; L++){
		for (int C = 0; C < maxSL; C++){
			if (C - L == 1){
				ans += dp[0][1][L][C];
				// cout << "BEDBUG: [" << L << "][" << C << "]" << dp[0][1][L][C] << endl;
			}
		}
	}
	return ans;
}

bool g(string s){
	int L = 0, C = 0;
	for (int i = 0; i < s.length(); i ++){
		if ((s.size() - i) % 2 == 0){
			C += (s[i] - '0');
		}
		else L += (s[i] - '0');
	}
	return (C - L == 1);
}

int main(){
	int t;
	cin >> t; 
	while(t--){
		string a, b; 
		cin >> a >> b;
		cout << f(b) - f(a) + g(a) << endl;
	}
	return 0;
}