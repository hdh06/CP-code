#include <bits/stdc++.h>

using namespace std;

int const N = 1002;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n, m;	
		cin >> n >> m;

		char arr[N][N];

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) 
				cin >> arr[i][j];

		bool dp[N][N] = {}, dp2[N][N] = {};

		for (int i = 1; i <= n; i++) dp[i][m + 1] = dp2[i][m + 1] = 1;
		for (int i = 1; i <= m; i++) dp[n + 1][i] = dp2[n + 1][i] = 1;
		dp[n + 1][m + 1] = dp2[n + 1][m + 1] = 1;

		for (int i = n; i >= 1; i--)
			for (int j = m; j >= 1; j--)
				if (arr[i][j] == '.') dp[i][j] = dp[i + 1][j];
			

		for (int j = m; j >= 1; j--)
			for (int i = n; i >= 1; i--)
				if (arr[i][j] == '.') dp2[i][j] = dp2[i][j + 1];	
		
		int dem = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) 
				if (dp[i][j] + dp2[i][j] == 2) dem++;
		cout << dem << endl;
	}
	return 0;
}