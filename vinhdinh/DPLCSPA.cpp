#include <bits/stdc++.h>

using namespace std;

int const N = 5001;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;	
	string a;
	cin >> a;
	a = ' ' + a;


	// vector<vector<int> > dp(n + 2, vector<int>(n + 2, 0));
	// int dp[N][N] = {};

	int x[N] = {}, y[N] = {};

	for (int i = 1; i <= n; i++){
		for (int j = n; j >= 1; j--){
			if (a[i] == a[j]) x[n - j + 1] = y[n - j + 1 - 1] + 1;
			else{
				x[n - j + 1] = max(x[n - j + 1 - 1], y[n - j + 1]);
			}
			// cout << dp[i][j] << " \n"[j == n];
			
		}
				
		for (int i = 1; i <= n; i++) y[i] = x[i];
	}

	cout << n - x[n];
	return 0;
}