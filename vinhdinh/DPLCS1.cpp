#include <bits/stdc++.h>

using namespace std;

int const N = 2001;
int dp[N][N] = {};


int main(){
	string a, b;
	cin >> a >> b;
	int ans = 0;
	a = " " + a;
	b = " " + b;
	for(int i = 1; i < a.length(); i++){
		for (int j = 1; j < b.length(); j++){
			if (a[i] == b[j]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[a.length() - 1][b.length() - 1];

	return 0;
}

